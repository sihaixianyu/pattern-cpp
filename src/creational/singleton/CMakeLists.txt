find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(singleton singleton.h singleton.cpp)
target_link_libraries(
    singleton
    PRIVATE fmt::fmt
    PRIVATE GTest::gtest_main
)
