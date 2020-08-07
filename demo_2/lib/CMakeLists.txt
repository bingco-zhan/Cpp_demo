SET(LIBHELLO_SRC hello.cpp)
# 添加静态库
# ADD_LIBRARY( libname [SHARED|STATIC|MODULE] [EXCULDE_FROM_ALL] source... )
# libname 生成的库文件 默认.so|.a结尾
# 类型 SHARED:动态库 STATIC:静态库 MODULE:dyld系统有效,若不支持dyld则当做SHARED
# EXCLUDE_FROM_ALL 默认不构建这个库
# source 源文件
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})
# 设置目标参数
# SET_TARGET_PROPERTIES(target... PROPERTIES prop1 value1 prop2 value2 ...)
# target 目标对象, prop - value 键值对
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
# 获取目标参数
GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME:" ${OUTPUT_VALUE})
# 设置动态库版本 效果如下
# libhello.so.1.2
# libhello.so   -> libhello.so.1
# libhello.so.1 -> libhello.so.1.2
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)
# 安装时统一配置目录 注:静态库需要使用ARCHIVE关键字
INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# 安装时文件拷贝至目录
INSTALL(FILES hello.h DESTINATION include)
