include_directories(Catch/single_include)
include_directories(${CMAKE_SOURCE_DIR}/src)
add_definitions(-g3)
add_executable(${PROJECT_NAME}-tests main.cpp tests.cpp)
add_custom_target(tests-run
    DEPENDS ${PROJECT_NAME}-tests
    COMMAND time ./${PROJECT_NAME}-tests
)

