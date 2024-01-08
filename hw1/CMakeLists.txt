add_executable(hw1 hw1.cpp)
target_link_libraries(hw1 PRIVATE sfml-graphics)
target_compile_features(hw1 PRIVATE cxx_std_17)


install(TARGETS hw1
        RUNTIME DESTINATION bin/hw1/
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
## copy resources
install(FILES config.txt
        DESTINATION bin/hw1)