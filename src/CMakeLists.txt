file(GLOB src_files *.cpp)

add_library(src_lib OBJECT ${src_files})
target_include_directories(src_lib PUBLIC ${VENDOR_DIR}/elnormous_http/)
target_compile_definitions(hue_controller PUBLIC src_lib)