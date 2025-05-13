cmake_minimum_required(VERSION 3.13...3.25)
project(clang-ast LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LLVM 安装路径
set(LLVM_INSTALL_DIR "${CMAKE_SOURCE_DIR}/llvm-project/build")

# 显式指定 LLVM 和 Clang 的 CMake 配置路径（不使用 CMAKE_PREFIX_PATH）
set(LLVM_DIR "${LLVM_INSTALL_DIR}/lib/cmake/llvm")
set(Clang_DIR "${LLVM_INSTALL_DIR}/lib/cmake/clang")

# 查找 LLVM 和 Clang 包
find_package(LLVM REQUIRED CONFIG PATHS ${LLVM_DIR})
if (NOT LLVM_FOUND)
  message(FATAL_ERROR "LLVM not found in ${LLVM_DIR}")
endif()
find_package(Clang REQUIRED CONFIG PATHS ${Clang_DIR})
if (NOT Clang_FOUND)
  message(FATAL_ERROR "Clang not found in ${Clang_DIR}")
endif()

# 打印路径调试信息
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using ClangConfig.cmake in: ${Clang_DIR}")
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "Clang_INCLUDE_DIRS: ${CLANG_INCLUDE_DIRS}")

# 创建你的可执行文件
add_executable(clang-ast src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/llvm-project/clang/include)

# 包含头文件路径
target_include_directories(clang-ast PRIVATE
  ${LLVM_INCLUDE_DIRS}
  ${CLANG_INCLUDE_DIRS}
)

# 设置宏定义
target_compile_definitions(clang-ast PRIVATE
  ${LLVM_DEFINITIONS}
)

# 链接 clang 和 LLVM 的组件
target_link_libraries(clang-ast PRIVATE
  clangTooling
  clangFrontend
  clangSerialization
  clangDriver
  clangParse
  clangSema
  clangAnalysis
  clangASTMatchers
  clangAST
  clangLex
  clangBasic

  LLVMCore
  LLVMIRReader
  LLVMSupport
  LLVMAnalysis
)
