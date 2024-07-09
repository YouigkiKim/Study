#include "utils.h"
#include <iostream>
#include <fstream>



int main() {
  MyExcel::TxtTable table(5, 5);
  table.reg_cell(new MyExcel::NumberCell(2, 1, 1, &table), 1, 1);
  table.reg_cell(new MyExcel::NumberCell(3, 1, 2, &table), 1, 2);
  table.reg_cell(new MyExcel::NumberCell(4, 2, 1, &table), 2, 1);
  table.reg_cell(new MyExcel::NumberCell(5, 2, 2, &table), 2, 2);
  table.reg_cell(new MyExcel::ExprCell("B2+B3*(C2+C3-2)", 3, 3, &table), 3, 3);
  table.reg_cell(new MyExcel::StringCell("B2 + B3 * ( C2 + C3 - 2 ) = ", 3, 2, &table),
                 3, 2);
  std::cout << table;

  std::cout
      << "테이블 타입(0) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요"
      << std::endl;
  std::cout << "* 참고 * " << std::endl;
  std::cout << "1 : 텍스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블"
            << std::endl;
  int type, max_row, max_col;
  std::cin >> type >> max_row >> max_col;
  MyExcel::Excel m(max_row, max_col, type - 1);
  m.command_line();
  return 0;
}