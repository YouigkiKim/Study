#include "utils.h"


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
Stack::Stack() : start(NULL,"") {current = &start;}
void    Stack::push(string s){
    Node* n = new Node(current,s);
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
Cell::Cell(string data, int x, int y, Table* table)
    :data(data),x(x),y(y),table(table){}
string Cell::stringify(){return data;}
int Cell::to_numeric() {return 0; }

}// namespace MyExcel





