add_executable(test_example main.cpp)
target_link_libraries(test_example multidraw ${CONAN_LIBS})
target_include_directories(test_example PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
add_test(NAME test_example COMMAND test_example)
