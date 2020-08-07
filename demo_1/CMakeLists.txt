#指定CMAKE版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
#定义项目名
PROJECT(demo_1)
#定义变量
SET(SRC_LIST main.cpp)
#输出消息
MESSAGE(STATUS "This is BINARY dir " ${demo_1_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${demo_1_SOURCE_DIR})
#添加子目录
ADD_SUBDIRECTORY(src bin)
#指定文件的安装目录make install时生效
# 注: cmake时可指定安装目录
#     cmake -DCMAKE_INSTALL_PREFIX=/usr/local
# DESTINATION :定义输出目录
# FILES :指定文件
INSTALL(FILES COPYRIGHT README DESTINATION share/doc)
# PROGRAMS :指定可执行文件
INSTALL(PROGRAMS start.sh DESTINATION bin)
# DIRECTORY :指定文件夹
INSTALL(DIRECTORY doc/ DESTINATION share/doc)
