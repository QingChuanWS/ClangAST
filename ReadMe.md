<!--
 (c) Copyright 2022 - 2025 Advanced Micro Devices, Inc. All Rights Reserved.
-->

# Clang-AST

## build

llvm build

```
cmake -G Ninja ../../llvm-project/llvm \
  -DCMAKE_INSTALL_PREFIX=../llvm-install \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_C_COMPILER=clang-17 \
  -DCMAKE_CXX_COMPILER=clang++-17 \
  -DLLVM_ENABLE_PROJECTS="clang" \
  -DLLVM_TARGETS_TO_BUILD="X86" \
  -DLLVM_ENABLE_RTTI=ON \
  -DLLVM_ENABLE_EH=ON \
  -DLLVM_INCLUDE_TESTS=OFF \
  -DLLVM_INCLUDE_EXAMPLES=OFF \
  -DLLVM_INCLUDE_DOCS=OFF \
  -DLLVM_BUILD_TOOLS=OFF \
  -DLLVM_INSTALL_TOOLCHAIN_ONLY=ON

```
