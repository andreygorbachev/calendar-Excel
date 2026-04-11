project("${PROJECT_NAME}_test" LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  parse.cpp
  dll.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  calendar-Excel
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
