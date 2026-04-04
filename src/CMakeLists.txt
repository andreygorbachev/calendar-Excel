# project "calendar-Excel"

add_library(${PROJECT_NAME}
  dll.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  calendar
  calendar_static-data
)
