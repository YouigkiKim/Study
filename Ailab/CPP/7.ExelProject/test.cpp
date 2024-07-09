#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
using std::string;

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
    void printstack() const;
    ~NumStack();
};

NumStack::NumStack() : start(NULL,0){current = &start;}
void NumStack::push(double s){
    Node *n = new Node(current,s);
    current = n;
}
double NumStack::pop(){
    if(current== &start) return 0;

    double s = current -> s;
    Node* prev = current;
    current = current -> prev;

    delete prev;
    return s;
}
double NumStack::peek(){ return current -> s;}
bool NumStack::is_empty(){
    if(current == &start) return true;
    return false;
}
NumStack::~NumStack(){
    while(current != &start){
        Node * prev = current;
        current = current -> prev;
        delete prev;
    }
}
void NumStack::printstack() const{
    std::cout<<current -> s<< std::endl;
}
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
    void    printvec();
};
Vector::Vector(int n) : data(new string[n]),capacity(n),length(n){}
void    Vector::push_back(string s){
    if( capacity <= length ){
        // 길이가 늘어난 temp에 원래 데이터 덮어쓰기
        string* temp = new string[capacity * 2];
        for (int i=0; i < length; i++) {
            temp[i] = data[i];
        }
        //data 에 temp덮어쓰기
        delete[] data;
        data = temp;
        capacity *=2;
    }
    // data의 마지막에 s 추가
    data[length] = s;   // data의 마지막 +1 주소에 
    length++;           //2차원 행렬로 저장되기 때문에 ++만한다.
}
string  Vector::operator[](int i){return data[i];}
void Vector::remove(int x){
    for(int i=x+1; i< length; i++){
        data[i-1] = data[i];
    }
    length --;
}

int    Vector::size(){return length;}
Vector::~Vector(){
    if(data) delete[] data;
}
void Vector::printvec(){
    for(int i=0;i<size();i++){
        std::cout << data[i];
    }
    std::cout<<std::endl;
}
//Cell class and dreived class
class Table;
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
 //namespace MyExcel

// 연산자 오버로드 소스코드
std::ostream& operator<<(std::ostream& o, Table& table){
    o<<table.print_table();
    return o;
}





int main(){
    NumStack stack;
    stack.printstack();
    stack.push(2);
    stack.printstack();
    Vector vec;
    string a;
    std::cout<<"a 입력" << std::endl;
    std::cin>>a;
    vec.printvec();
    std::cout<<"chrl vector"<<std::endl;
    vec.push_back(a);
    std::cout<<"after push "<<std::endl;
    vec.printvec();
    
    return 0;
}