cmake_minimum_required(VERSION 3.5)

project(cpp_hue_controller)
add_executable(hue_controller main.cpp)

set(VENDOR_DIR ${cpp_hue_controller_SOURCE_DIR}/res/vendor)
set(SRC_DIR ${cpp_hue_controller_SOURCE_DIR}/src)

## HTTP INCLUDES
target_include_directories(hue_controller PUBLIC ${VENDOR_DIR}/elnormous_http/)
target_include_directories(hue_controller PUBLIC ${SRC_DIR})
target_link_libraries(hue_controller wsock32)
target_link_libraries(hue_controller Ws2_32)
target_link_libraries(hue_controller src_lib)

add_subdirectory(src)