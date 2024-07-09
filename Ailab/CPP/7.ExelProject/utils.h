#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <ctime>
using std::string;

namespace MyExcel{

class Cell;
class Vector;
class Stack;
class Table;

class Vector{
    // 저장되는 데이터
    string* data;
    // 저장할 수 있는 글자수
    int     capacity;
    //저장된 문자열의 개수
    int     length;

    public:
    Vector(int n=1);
    ~Vector();
    void    push_back(string s);
    string  operator[](int i);
    void    remove(int x);
    int     size();
};

class Stack{
    struct Node {
        Node* prev;
        string s;
        Node(Node* prev, string s) : prev(prev),s(s) {
        }
    };
    Node*   current;
    Node    start;

    public:
     Stack();
     void push(string s);
     string pop();
     string peek();
     bool is_empty();
     ~Stack();
};
class NumStack{
    struct Node {
        Node* prev;
        double s;
        Node(Node* prev, double s) : prev(prev),s(s) {}
    };
    Node* current;
    Node start;

    public:
    NumStack();
    void push(double s);
    double pop();
    double peek();
    bool is_empty();

    ~NumStack();
};
//Cell class and dreived class
class Cell{

    protected:
    int x,y;
    Table* table;

    public:
    virtual string stringify() = 0;
    virtual int to_numeric() = 0;

    Cell( int x, int y, Table* table);
};

class StringCell : public Cell {
    string data;

    public:
    string stringify();
    int to_numeric();

    StringCell(string data, int x,int y, Table* t);
};

class NumberCell : public Cell{
    int data;
    public:
    string stringify();
    int to_numeric();
    NumberCell(int data, int x, int y ,Table*t);
};

class DateCell : public Cell{
    time_t data;
    public:
    DateCell(string s, int x, int y, Table* t);
    string stringify();
    int to_numeric();
};

class ExprCell : public Cell{
    string data;
    string* parsed_expr;
    Vector exp_vec;
    int precedence(char c);
    void parse_expression();
    public:
    ExprCell(string data, int x, int y,Table *t);
    string stringify();
    int to_numeric();
};


class Table{

    protected:
    int max_row_size, max_col_size;
    Cell*** data_table;

    public:
    Table(int max_row_size,int max_col_size);
    ~Table(); 
    
    //새로운 셀 등록
    void            reg_cell(Cell* c, int row, int col);
    //해당 셀의 정수값 반환
    int             to_numeric(const string& s);
    //행열로 셀 호출
    int             to_numeric(int row, int col);
    //해당 셀 문자열 반환
    string          stringify(const string&s);
    string          stringify(int row, int col);
    virtual string  print_table() = 0; 
};
class TxtTable : public Table{
    string repeat_char(int n , char  c);
    string col_num_to_str(int n);

    public:
    TxtTable(int row, int col);
    string      print_table();
};

std::ostream& operator<<(std::ostream& o, Table& table);


/*

Excel class

*/
class Excel {
    Table* current_table;

    public:
    Excel(int max_row, int max_col, int choice);
    int     parse_user_input(string s);
    void    command_line();
};
} //namespace MyExcel

# endif // UTILS_H