# project "calendar-Excel"

add_library(${PROJECT_NAME} SHARED
  dll.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ../include
)

# to make IDE to show this file as part of the project
target_sources(${PROJECT_NAME} PRIVATE
  ../include/error_codes.h # should target_include_directories take care of a path here?
  ../include/parse.h
  ../include/return.h
  ../include/as_of_date.h
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  calendar
  calendar_static-data
)
