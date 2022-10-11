# cmake -D 就会在cmake 中定义一个变量，而且这个变量可以通过submodule传递
if(DST_FILE)
    # cache 缓存变量会在整个生命周期中都会使用，如果原来缓存中有该变量，不会改变，具体查看https://www.cnblogs.com/narjaja/p/8351500.html
    set(MY_DIR ${TEST_DIR} CACHE PATH "root for library output, set this to change where android libs are compiled to")
    # get absolute path, but get_filename_component ABSOLUTE only refer with source dir, so find_file here :(
    get_filename_component(DST_FILE_NAME ${DST_FILE} NAME)
    get_filename_component(DST_FILE_EXT ${DST_FILE} EXT)
    get_filename_component(DST_FILE_DIRECTORY ${DST_FILE} DIRECTORY)
    get_filename_component(DST_FILE_STEM ${DST_FILE} NAME_WE)
    # find_file(DST_FILE ${DST_FILE_NAME} PATHS ${CMAKE_SOURCE_DIR} NO_DEFAULT_PATH)
# STATUS = 非重要消息；
# WARNING = CMake 警告, 会继续执行；
# AUTHOR_WARNING = CMake 警告 (dev), 会继续执行；
# SEND_ERROR = CMake 错误, 继续执行，但是会跳过生成的步骤；
# FATAL_ERROR = CMake 错误, 终止所有处理过程；
    message(STATUS "DST_FILE = ${DST_FILE}")
    message(STATUS "DST_FILE_NAME = ${DST_FILE_NAME}" ", " 
                   "DST_FILE_EXT = ${DST_FILE_EXT}" ", " 
                   "DST_FILE_DIRECTORY = ${DST_FILE_DIRECTORY}" ", " 
                   "DST_FILE_STEM = ${DST_FILE_STEM}")
    message(STATUS "MY_DIR = ${MY_DIR}")
endif()