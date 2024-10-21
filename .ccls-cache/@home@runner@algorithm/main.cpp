#include "2024.h" 
#include <iostream>
#include <string>


int main() {
  int year;

  std::cout << "请选择你想执行的代码题目年份 (2009 - 2024): ";
  std::cin >> year;

  // 检查输入年份是否在范围内
  if (year < 2009 || year > 2024) {
    std::cerr << "输入的年份无效！请输入2009到2024之间的年份。" << std::endl;
    return 1;
  }

  // 根据输入年份选择执行对应的逻辑
  switch (year) {
  case 2024:
    run(); // 调用2024的run函数
    break;
  // 可以在此处添加其他年份的逻辑
  default:
    std::cout << "不支持的年份。" << std::endl;
    break;
  }

  return 0;
}