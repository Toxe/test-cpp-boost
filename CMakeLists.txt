cmake_minimum_required(VERSION 3.14)
project("Boost" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Boost REQUIRED COMPONENTS regex thread)

set(ALL_TARGETS
    example_lambda
    example_regex
    example_threads
    stream_to_log_file
)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE " /W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    target_compile_features(${target} PUBLIC cxx_std_17)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_include_directories(${target} PRIVATE ${Boost_INCLUDE_DIRS})

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wmost -pedantic -Wfloat-equal -fcolor-diagnostics)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        target_compile_options(${target} PRIVATE /W4)
    endif()
endforeach()

target_link_libraries(example_regex PRIVATE Boost::regex)
target_link_libraries(example_threads PRIVATE Boost::thread)
