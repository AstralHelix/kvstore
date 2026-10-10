cmake_minimum_required(VERSION 3.20)
project(kvstore VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_library(store_lib src/store.cpp)
target_include_directories(store_lib PUBLIC include)

add_executable(kvstore src/main.cpp)
target_link_libraries(kvstore PRIVATE store_lib)


target_compile_options(store_lib PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)

target_compile_options(kvstore PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)

enable_testing()

add_executable(store_tests tests/store_tests.cpp)
target_link_libraries(store_tests PRIVATE store_lib GTest::gtest_main)


target_compile_options(store_tests PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)

include(GoogleTest)
gtest_discover_tests(store_tests)

