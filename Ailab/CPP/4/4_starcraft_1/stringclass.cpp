#include <iostream>

class string{
    char * str;
    int len;

    public:
    string(char c, int n);
    string(const char *c);
    string(const string &s );
    ~string();

    void add_string(const string &s);
    void copy_string(const string &s);
    int strlen();
};
string::string(const string &s){
    len = s.len;
    str = new char[s.len+1];
    strcpy(str,s.str);
}
//깊은 복사
string::string(const char *c){
    len = 1;
    str = new char;
    strcpy(str,c);
}
//소멸자
string::~string(){
    if(str){ 
        delete[] str;
    };
}
string::string(char c, int n){
    len = n;
    str = new char[n+1];
    for (int i=0;i<n;i++){
        str[i] = c;
    } 
    std::cout<<str<<std::endl;
}
void string::add_string(const string &s){
    //배열 생성 후 하나씩 집어넣어서 배열 결합
    char* newstr = new char[len+s.len+1];
    for (int i=0;i<len;i++){
        newstr[i] = str[i]; 
    }
    for(int i=0;i<s.len;i++){
        newstr[i+len] = s.str[i];
    }
    delete[] str;
    str = newstr;
    len = len+s.len;
    std::cout<<"added string : "<< str<<std::endl;
}
void string::copy_string(const string &s){
    //new의 반환은 주소값 -> 포인터변수로 받아야함
    delete[] str;
    str = new char[s.len+1];
    for (int i=0;i<s.len;i++){
        str[i] = s.str[i];
    }
    len = s.len;
    std::cout<<"copied string : "<< str <<std::endl;
}

int main(){
    string s('a',3);
    string s2('b',2);
    s.add_string(s2);
    s.copy_string(s2);
    return 0;
}