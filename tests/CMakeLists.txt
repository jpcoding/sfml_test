add_executable(sfml_tets sfml_test.cpp)
target_link_libraries(sfml_tets PRIVATE sfml-graphics)
target_compile_features(sfml_tets PRIVATE cxx_std_17)

add_executable(hw1 hw1.cpp)
target_link_libraries(hw1 PRIVATE sfml-graphics)
target_compile_features(hw1 PRIVATE cxx_std_17)


install(TARGETS sfml_tets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)