add_library(YourLibrary main.cpp)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} YourLibrary)
