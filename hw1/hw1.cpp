#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

 /**
  * Provides a game context
  */
class Context {
    int m_width;
    int m_height;

public:
    Context() : m_width(0), m_height(0)
    {
        //Empty
    }

    void setWidth(int width)
    {
        m_width = width;
    }

    void setHeight(int height)
    {
        m_height = height;
    }

    int getWidth() const
    {
        return m_width;
    }

    int getHeight() const
    {
        return m_height;
    }
};

/**
 * Wraps sf::Shape with a name, and speed
 */
class DrawableShape {
    std::shared_ptr<sf::Shape> m_shape;
    std::shared_ptr<sf::Text> m_name;
    sf::Vector2f m_speed;

public:
    DrawableShape(std::shared_ptr<sf::Shape> shape, std::shared_ptr<sf::Text> name, sf::Vector2f speed)
        : m_shape(shape), m_name(name), m_speed(speed)
    {
        //Empty
    }

    std::shared_ptr<sf::Shape> getShape()
    {
        return m_shape;
    }

    std::shared_ptr<sf::Text> getName()
    {
        return m_name;
    }

    void update(const Context& context)
    {
    }
};

int main(int argc, char* argv[])
{
    sf::RenderWindow window;
    Context* context = new Context();

    sf::Font font;

    //Initializer variables for reading in config values
    std::string _fontFilename;
    sf::Color* _fontColor =nullptr;
    int _fontSize = 0;

    int _wWidth = 0;
    int _wHeight = 0;

    std::string _shapename;

    float _initPosX, _initPosY = 0;
    float _initSpeedX, _initSpeedY = 0;

    int _r, _g, _b = 0;

    float _rectWidth, _rectHeight = 0;
    float _circleRadius = 0;

    //Read in config
    std::ifstream fin("config.txt");
    std::string token;

    //List of shapes
    std::vector<std::shared_ptr<DrawableShape>> shapes;

    while (fin.good())
    {
        fin >> token;

        if (token == "Font")
        {
            fin >> _fontFilename >> _fontSize >> _r >> _g >> _b;

            //Attempt to load font";
            if (!font.loadFromFile(_fontFilename))
            {
                // if we can't load the font, print an error to the error console and exit
                std::cerr << "Could not load font!\n";
                exit(-1);
            }

            _fontColor = new sf::Color(_r, _g, _b);

        }
        else if (token == "Rectangle")
        {
            fin >> _shapename >> _initPosX >> _initPosY >> _initSpeedX >> _initSpeedY >> _r >> _g >> _b >> _rectWidth >> _rectHeight;
            std::shared_ptr<sf::RectangleShape> _rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(_rectWidth, _rectHeight));
            _rectangle->setFillColor(sf::Color(_r, _g, _b));
            _rectangle->setPosition(_initPosX, _initPosY);

            std::shared_ptr<sf::Text> _text = std::make_shared<sf::Text>(_shapename, font, _fontSize);
            _text->setFillColor(*_fontColor);

            shapes.push_back(std::make_shared<DrawableShape>(_rectangle, _text, sf::Vector2f(_initSpeedX, _initSpeedY)));
        }
        else if (token == "Circle")
        {
            fin >> _shapename >> _initPosX >> _initPosY >> _initSpeedX >> _initSpeedY >> _r >> _g >> _b >> _circleRadius;
            std::shared_ptr<sf::CircleShape> _circle = std::make_shared<sf::CircleShape>(_circleRadius);
            _circle->setPosition(_initPosX, _initPosY);
            _circle->setFillColor(sf::Color(_r, _g, _b));

            std::shared_ptr<sf::Text> _text = std::make_shared<sf::Text>(_shapename, font, _fontSize);
            _text->setFillColor(*_fontColor);

            shapes.push_back(std::make_shared<DrawableShape>(_circle, _text, sf::Vector2f(_initSpeedX, _initSpeedY)));
        }
        else if (token == "Window")
        {
            fin >> _wWidth >> _wHeight;
            window.create(sf::VideoMode(_wWidth, _wHeight), "HW1 window");
            context->setWidth(_wWidth);
            context->setHeight(_wHeight);
        }
        else
        {
            std::cout << "Bad!\n";
        }
    }


    return 0;
}