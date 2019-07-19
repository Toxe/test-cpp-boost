cmake_minimum_required(VERSION 3.14)
project("Boost" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Boost REQUIRED COMPONENTS regex)

set(ALL_TARGETS
    example_lambda
    example_regex
    stream_to_log_file
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    target_compile_features(${target} PUBLIC cxx_std_17)
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wmost -pedantic -Wfloat-equal -fcolor-diagnostics)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_include_directories(${target} PRIVATE ${Boost_INCLUDE_DIRS})
endforeach()

target_link_libraries(example_regex PRIVATE Boost::regex)
