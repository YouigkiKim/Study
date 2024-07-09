#include "utils.h"
#include <iostream>
#include <fstream>



int main() {
  MyExcel::TxtTable table(5, 5);
  std::ofstream out("/Users/youngki/study/Ailab/CPP/7.ExelProject/test.txt");

  table.reg_cell(new MyExcel::StringCell("Hello~", 0, 0, &table), 0, 0);
  table.reg_cell(new MyExcel::StringCell("C++", 0, 1, &table), 0, 1);
  table.reg_cell(new MyExcel::StringCell("Programming", 1, 1, &table), 1, 1);
  std::cout<< table << std::endl ;
  out << table;
  return 0;
}