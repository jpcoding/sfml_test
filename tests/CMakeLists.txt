add_executable(sfml_tets sfml_test.cpp)
target_link_libraries(sfml_tets PRIVATE sfml-graphics)
target_compile_features(sfml_tets PRIVATE cxx_std_17)


install(TARGETS sfml_tets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)