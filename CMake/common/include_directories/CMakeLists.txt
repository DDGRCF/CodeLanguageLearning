cmake_minimum_required(VERSION 3.8)
# set(CMAKE_VERBOSE_MAKEFILE ON) # 详细输出
project(include_directories)
aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS) # 这个结果不递归，但是这个路径是相对路径(可以加上绝对路径使其变为绝对路径)
file(GLOB DIR_SRCS_GLOB src/*.cc) # 这个结果不递归，但是这个路径是绝对路径，而且这个结果是正则匹配
file(GLOB_RECURSE DIR_SRCS_GLOB_RECURSE src/*.cc) # 这个结果递归，这个是绝对路径，而且这个结果是正则匹配
message(STATUS "aux source directory: ${DIR_SRCS}")
message(STATUS "file glob: ${DIR_SRCS_GLOB}")
message(STATUS "file recurse glob: ${DIR_SRCS_GLOB_RECURSE}")


include_directories(${CMAKE_SOURCE_DIR}/world/include) # 这里包括了子目录就不用包括了，但是使用了target_include_directories就不一样了，只为目标包括头文件
message(STATUS "include world include: ${CMAKE_SOURCE_DIR}/world/include")

add_subdirectory(world)
add_executable(${CMAKE_PROJECT_NAME} ${DIR_SRCS})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include) # 直白的讲就是不会使用子目录包括的文件，INTERFACE会使用相关信息(比如使用头文件之中的结构体)
