// (c) Copyright 2022 - 2025 Advanced Micro Devices, Inc. All Rights Reserved.

#include <iostream>
#include <memory>

#include "clang/Frontend/FrontendAction.h"

class FindNamedClassAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::make_unique<FindNamedClassConsumer>();
  }
};

int main() {
  std::cout << "hello world" << std::endl;
  return 0;
}