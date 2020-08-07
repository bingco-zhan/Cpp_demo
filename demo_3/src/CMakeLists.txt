ADD_EXECUTABLE(main main.cpp)
# 包含外部目录
INCLUDE_DIRECTORIES(/workspace/app/include)
# 动态库链接
TARGET_LINK_LIBRARIES(main /workspace/app/lib/libhello.so)
