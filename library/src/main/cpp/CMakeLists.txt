project(UV)
cmake_minimum_required (VERSION 3.6)

include_directories(
  ${PROJECT_SOURCE_DIR}/include/
  ${PROJECT_SOURCE_DIR}/../../../../thirdparty/libuv/include/
  )


add_library(uv STATIC IMPORTED)
set_target_properties(uv
        PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../../../../thirdparty/libuv/lib/libuv.a)


set(UV_FILES
    ${CMAKE_SOURCE_DIR}/uv_native.cpp
)

add_library(
    uv-jni
    SHARED
    ${UV_FILES})

target_link_libraries(
   uv-jni
   uv
   log
)
