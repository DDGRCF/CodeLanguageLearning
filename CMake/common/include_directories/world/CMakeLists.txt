cmake_minimum_required(VERSION 3.8)

project(world)

aux_source_directory(${PROJECT_SOURCE_DIR}/src WORLD_DIR_SRCS) # 这里变量和parent项目是共享的，因此不能用
message(STATUS "${PROJECT_NAME} SRCS: ${WORLD_DIR_SRCS}")

add_library(${PROJECT_NAME} ${WORLD_DIR_SRCS}) # 另外这里只能使用project name 而不能使用cmake project name，因为cmake 这个是子目录，cmake project name 代表这个项目