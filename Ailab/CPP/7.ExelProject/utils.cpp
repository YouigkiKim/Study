#include "utils.h"
#include <ctime>

namespace MyExcel{
//Vector function
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
    //std::cout<< "s pushed : " << s << std::endl;
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

// 연산자 오버로드 소스코드
std::ostream& operator<<(std::ostream& o, Table& table){
    o<<table.print_table();
    return o;
}

//Stack function
Stack::Stack() : start(NULL,""){current = &start;}
void    Stack::push(string s){
    Node* n = new Node(current,s);
    current = n;
    //std::cout << "Stack pushed string : "<< s<<std::endl;
}
string  Stack::pop(){
    if(current == &start) return "";
    Node*   prevNode = current->prev;
    string  data = current->s;
    delete  current;
            current = prevNode;
    return  data;
}
string  Stack::peek(){return current->s;}
bool Stack::is_empty() {
    if(current == &start) return true;
    return  false;
}
Stack::~Stack(){
    while(current != &start){
        Node*   prevNode = current -> prev;
        delete  current;
        current = prevNode;
    }
}
/*

NumStack

*/
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



Table::Table(int max_row_size, int max_col_size)
    : max_row_size(max_row_size), max_col_size(max_col_size){
        data_table = new Cell**[max_row_size];
        for(int i=0;i<max_row_size;i++){
            data_table[i] = new Cell*[max_col_size];
            for(int j=0;j<max_col_size;j++){
                data_table[i][j] = NULL;
            }
        }
    }
Table::~Table(){
    //2차원 데이터 메모리 해제
    for(int i=0;i<max_row_size;i++){
        for(int j=0;j<max_col_size;j++){
            if(data_table[i][j]) delete data_table[i][j];
        }
    }
    //1차원 데이터 메모리 해제
    for (int i=0;i<max_row_size; i++){
        delete[] data_table[i];
    }
    //table메모리 해제
    delete[] data_table;
}
void    Table::reg_cell(Cell* c, int row, int col){
    if(!(row<max_row_size && col < max_col_size)) return;
    
    if(data_table[row][col]) delete[] data_table[row][col];
    data_table[row][col] = c;
}
int     Table::to_numeric(const string& s){
    int col = s[0] - 'A';
    int row = atoi(s.c_str()+1)-1;
    if(row<max_row_size && col < max_col_size){
        if ( data_table[row][col]){
            return data_table[row][col] -> to_numeric();
        }
    }
    return NULL;
}
int     Table::to_numeric(int x, int y){
    if(x < max_row_size && y<max_col_size && data_table[x][y]){
        return data_table[x][y] -> to_numeric();
    }
    return 0;
}
string  Table::stringify(int row,int col){
    if(row<max_row_size && col< max_col_size && data_table[row][col]){
        return data_table[row][col] -> stringify();
    }
    return "";
}
string  Table::stringify(const string& s){
    int col = s[0] - 'A';
    int row = atoi(s.c_str()+1)-1;

    if(row< max_row_size && col < max_col_size && data_table[row][col]){
        return data_table[row][col] -> stringify();
    }
    return 0;
}


TxtTable::TxtTable(int row, int col) : Table(row,col){}

string  TxtTable::print_table(){
    string total_table;

    int* col_max_wide = new int[max_col_size];
    for(int i=0;i<max_col_size;i++){
        unsigned int max_wide = 2;
        for(int j=0;j<max_row_size;j++){
            if(data_table[j][i] &&
            data_table[j][i] -> stringify().length()){
                max_wide = data_table[j][i] -> stringify().length();
            }
        }
        col_max_wide[i] = max_wide;
    }
    total_table += "    ";
    int total_wide = 4;
    for(int i=0;i<max_col_size; i++){
        if(col_max_wide[i]){
            int max_len = std::max(2,col_max_wide[i]);
            total_table += "|" + col_num_to_str(i);
            total_table += repeat_char(max_len - col_num_to_str(i).length(),' ');
 
            total_wide += (max_len +3);
        }
    }

    total_table += "\n";
    for(int i=0;i<max_row_size;i++){
        total_table += repeat_char(total_wide,'-');
        total_table += "\n" + std::to_string(i+1);
        total_table += repeat_char(4-std::to_string(i+1).length(),' ');

        for(int j=0; j< max_col_size;j++){
            if(col_max_wide[j]){
                int max_len = std::max(2,col_max_wide[j]);

                string s = "";
                if(data_table[i][j]){
                    s = data_table[i][j] -> stringify();
                }
                total_table += " | " +s;
                total_table += repeat_char(max_len - s.length(),' ');
            }
        }
        total_table +="\n";
    }
    return total_table;
}
string TxtTable::repeat_char(int n, char c){
    string s = "";
    for(int i=0;i<n;i++) s.push_back(c);
    return s;
}
// AA ZZ의 열번호를 가진다.
string TxtTable::col_num_to_str(int n){
    string s = "";
    if(n<26){
        s.push_back('A'+n);
    }else{
        char first= 'A'+n/26-1;
        char second = 'A' + n % 26;
        s.push_back(first);
        s.push_back(second);
    }
    return s;
}

//Cell function
Cell::Cell(int x, int y, Table* table) : x(x),y(y),table(table){}
/*

String Cell

*/
StringCell::StringCell(string data, int x, int y, Table*t)
    : data(data),Cell(x,y,t){}
string StringCell::stringify(){ return data;}
int StringCell::to_numeric(){ return 0;}
/* 

NumberCell

*/
NumberCell::NumberCell(int data, int x,int y, Table*t)
    :data(data),Cell(x,y,t){}
string NumberCell::stringify(){return std::to_string( data);}
int NumberCell::to_numeric(){return data;}
/*

DateCell

*/
DateCell::DateCell(string s, int x, int y, Table*t)
    : Cell(x,y,t){
        int year = atoi(s.c_str());
        int month = atoi(s.c_str()+5);
        int day = atoi(s.c_str()+8);

        tm timeinfo;

        timeinfo.tm_year = year-1000;
        timeinfo.tm_mon = month-1;
        timeinfo.tm_mday = day;
        timeinfo.tm_hour = 0;
        timeinfo.tm_min = 0;
        timeinfo.tm_sec = 0;

        data = mktime(&timeinfo);
    }
string DateCell::stringify(){
    char buf[50];
    tm temp;
    localtime_r(&data,&temp);

    strftime(buf,50,"%F",&temp);
    return string(buf);
}
int DateCell::to_numeric(){ return static_cast<int>(data);}

/*

ExprCell

*/
// 입력인자 또한 data이고 조작하려는 멤버변수 이름 또한 data여서 업데이트 안되는 문제가 발생함.
ExprCell::ExprCell(string string, int x, int y, Table *t)
 : Cell(x,y,t),data(string){
    parse_expression();
    data = std::to_string(to_numeric());
    //std::cout << "data:"<<data<< std::endl;
}
string ExprCell::stringify(){return data; }
int ExprCell::to_numeric(){
    double result = 0;
    NumStack stack;
    for(int i=0;i<exp_vec.size();i++){
        string s = exp_vec[i];
        //셀일경우
        if (isalpha(s[0])){
            stack.push(table -> to_numeric(s));
        }
        //숫자일경우
        else if(isdigit(s[0])){
            stack.push(atoi(s.c_str()));
        }//연산자일경우
        else{
            double y = stack.pop();
            double x = stack.pop();
            switch(s[0]){
                case '+':
                    stack.push(x+y);
                    break;
                case '-':
                    stack.push(x-y);
                    break;
                case '*':
                    stack.push(x*y);
                    break;
                case '/':
                    stack.push(x/y);
                    break;
            }
        }
    }

    return stack.pop();
}
int ExprCell::precedence(char c){
    switch (c){
        case '(':
        case '[':
        case '{':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return  2;
    }
    return 0;
}
void ExprCell::parse_expression(){
    Stack stack;
    data.insert(0,"(");
    data.push_back(')');
    for(int i=0;i<data.length();i++){
        if(isalpha(data[i])){
            exp_vec.push_back(data.substr(i,2));
            i++;
            }else if( isdigit(data[i])){
            exp_vec.push_back(data.substr(i,1));
        }else if(data[i] =='(' || data[i] =='[' || data[i] == '{'){
            stack.push(data.substr(i,1));
        }else if(data[i] ==')' || data[i] ==']' || data[i] == '}'){
            string t = stack.pop();
            while(t != "("  && t!="[" && t!="{"){
                exp_vec.push_back(t);
                t = stack.pop();
                //std::cout << t << " poped from stack "<< std::endl;
            }
            // stack.peek()은 string형을 반환하고 precedence는char를 인자로 받음 
        }else if ( data[i] == '+' || data[i] == '-'|| data[i] =='*' || data[i] == '/'){
            while(!stack.is_empty() && precedence(stack.peek()[0]) >= precedence(data[i])){
                exp_vec.push_back(stack.pop());
                for (int i=0;i<exp_vec.size();i++){
                    //std::cout << "exP_vec["<<i<<"] : "<<exp_vec[i]<<std::endl;
                }
            }
            stack.push(data.substr(i,1));
            //std::cout << data.substr(i,1)<< " pused to stack"<<std::endl;
        } 
    }
}

/*

Excel class

*/
Excel::Excel(int max_row,int max_col, int choice = 0){
    switch(choice){
        case 0: current_table = new TxtTable(max_row, max_col);
        break;
    }

}
int Excel::parse_user_input(string s){
    int next = 0;
    string command = "";
    for(int i=0; i<s.length();i++){
        if(s[i] == ' '){
            command = s.substr(0,i);
            next = i+1;
            break;
        }else if( i == s.length()-1){
            command = s.substr(0,i+1);
            next    = i+1;
            break;
        }
    }

    string to = "";
    for(int i=next;i<s.length();i++){
        if(s[i] == ' ' || i==s.length() -1){
            to      = s.substr(next,i-next);
            next    = i+1;
            break;
        }else if( i == s.length()-1){
            to      = s.substr(0,i+1);
            next    = i+1;
            break;
        }
    }

    int col = to[0] -'A';
    int row = atoi(to.c_str()+1)-1;

    string rest = s.substr(next);

    if(command == "sets"){
        current_table -> reg_cell(new StringCell(rest, row, col, current_table), row,col);
    }else if(command == "setn"){ 
        current_table -> reg_cell(
            new NumberCell(atoi(rest.c_str()),row, col, current_table),row,col);
    }else if(command == "setd"){
        current_table -> reg_cell(
            new DateCell(rest, row, col, current_table), row, col);
    }else if(command == "sete"){
        current_table -> reg_cell(
            new ExprCell(rest, row, col, current_table),row, col);
    }else if(command == "out"){
        std::ofstream out(to);
        out << *current_table;
        std::cout << to << " 에 내용이 저장되었습니다" << std::endl;
    }else if(command == "exit"){
        return 0;
    }
    return 1;
}

void Excel::command_line(){
    string s;
    std::getline(std::cin, s);

    while(parse_user_input(s)){
        std::cout << *current_table << std::endl << ">> ";
        std::getline(std::cin,s );
    }
}



}// namespace MyExcel





