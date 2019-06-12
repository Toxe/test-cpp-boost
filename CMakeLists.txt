cmake_minimum_required(VERSION 3.14)
project("Boost" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Theoretisch sollte es reichen CMake mit -DCMAKE_PREFIX_PATH=$SUITE_BUILD aufzurufen,
# aber aus irgendeinem Grund werden dann die Boost Variablen nicht gesetzt.
find_package(Boost REQUIRED COMPONENTS headers regex)
set(Boost_INCLUDE_DIRS "$ENV{SUITE_BUILD}/include")

include_directories(${Boost_INCLUDE_DIRS})

add_executable(example_lambda example_lambda.cpp)
add_executable(example_regex example_regex.cpp)
add_executable(stream_to_log_file stream_to_log_file.cpp)

target_compile_features(example_lambda PUBLIC cxx_std_17)
target_compile_features(example_regex PUBLIC cxx_std_17)
target_compile_features(stream_to_log_file PUBLIC cxx_std_17)

target_link_libraries(example_regex PRIVATE ${Boost_LIBRARIES} Boost::regex)

set_target_properties(example_lambda PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(example_regex PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(stream_to_log_file PROPERTIES CXX_EXTENSIONS OFF)
