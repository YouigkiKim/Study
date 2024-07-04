#include <iostream>
#include <string.h>
#include <algorithm>

class MyString{
    char* string_content;
    int string_length;
    int capacity;

    public:
    //생성자
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    explicit MyString(int c); // explicit을 통해 암시적 컴파일 막음
    ~MyString();//소멸자
    //메서드
    int length() const{return string_length;};
    int getcapacity() const{return capacity;};
    void print() const;
    void println() const;
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
    void reserve(int size);
    char at(int i);
    MyString& insert(int loc,const MyString& str);
    MyString& insert(int loc,const char* str);
    MyString& insert(int loc,const char c);
    MyString& erase(int loc,int num);
    int find(int find_from, MyString& str) const;
    int find(int find_from, const char* c) const;
    int find(int find_from, char c) const;
    int compare(const MyString& str) const;
    bool operator==(MyString& str);

    //연산자 오버로딩
    MyString& operator+=(const char* str) ;
    MyString& operator==(const char* str);
    MyString& operator=(const char* str);
    char& operator[](const char* str);
};
//생성자 함수
MyString::MyString(int c) : capacity(c){}
MyString::MyString(char c)
: string_content(new char[1]),string_length(1),capacity(1){
    string_content[0] = c;
}
MyString::MyString(const char* str)
: string_length(strlen(str)), capacity(strlen(str)){
    string_content = new char[string_length];
    for (int i=0;i<string_length;i++){
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str)
:string_length(str.string_length),capacity(str.capacity){
    string_content = new char[string_length];
    for (int i=0;i<string_length;i++){
        string_content[i] = str.string_content[i];
    }
}
//소멸자 함수
MyString::~MyString(){delete[] string_content;}
//메서드
void MyString::print() const{
    for (int i=0;i<string_length;i++){
        std::cout<<string_content[i];
    }
}
void MyString::println() const{
    print();
    std::cout<<std::endl;
}
MyString& MyString::assign(const MyString& str){
    if(capacity<str.string_length){
        delete[] string_content;
        string_content = new char[str.string_length];
        capacity = str.string_length;
    }
    string_length = str.string_length;
    for(int i=0;i<string_length;i++){
        string_content[i] = str.string_content[i];
    }
    return *this;
}
MyString& MyString::assign(const char* str){
    if(capacity<strlen(str)){
        delete[] string_content;
        capacity = strlen(str);
        string_content = new char[string_length];}
    string_length = strlen(str);
    for(int i=0;i<string_length;i++){
        string_content[i] = str[i];
    }
    return *this;
}
void MyString::reserve(int size){
    if(size > capacity){
        char* prev_string = string_content;
        string_content =  new char[size];
        for (int i=0;i<string_length;i++){
            string_content[i] = prev_string[i];
        }
        capacity =size;
    }
}
char MyString::at(int i){
    if(i>string_length||i<0){
        return NULL;
    }else{
        return string_content[i];
    }
}
MyString& MyString::insert(int loc,const MyString& str){
    if(loc<0||loc>string_length) return *this;
    char* prev_string = string_content; ;
    if(capacity<string_length+str.string_length){
        if(capacity*2>string_length+str.string_length){
            capacity *=2;
        }else{
            capacity = string_length+str.string_length;
        }
        string_content = new char[capacity];
        for(int i=0;i<string_length+str.string_length;i++){
            if(i<loc) string_content[i] = prev_string[i];
            else if (i<=loc+str.string_length-1) string_content[i] = str.string_content[i-loc];
            else  string_content[i] = prev_string[i-str.string_length];
        }

        string_length  = string_length+str.string_length;

        delete[] prev_string;
        return *this;
    }else{
        for (int i = string_length - 1; i >= loc; i--) {
            // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
            string_content[i + str.string_length] = string_content[i];
        }
        // 그리고 insert 되는 문자 다시 집어넣기
        for (int i = 0; i < str.string_length; i++)
            string_content[i + loc] = str.string_content[i];

        string_length = string_length + str.string_length;
        return *this;
    }
}
MyString& MyString::insert(int loc,const char* str){
    MyString temp(str);
    return insert(loc,temp);
}
MyString& MyString::insert(int loc,const char c){
    MyString temp(c);
    return insert(loc,temp);
}
MyString& MyString::erase(int loc,int num){
    for(int i=loc;i<string_length-loc-num+1;i++){
        string_content[i] = string_content[i+num];
    }
    string_length -=num;
    return *this;
}
int MyString::find(int find_from, MyString& str) const{
    int i,j;
    if(str.string_length==0) return -1;
    for(i=find_from;i<=string_length-str.string_length;i++){
        for(j=0;j<str.string_length;j++){
            if(string_content[i+j] != str.string_content[j]) break;
        }
        if(j==str.string_length) return i;
    }
    return -1;
}
int MyString::find(int find_from,const char* str) const{
    MyString temp(str);
    return find(find_from,str);
}
int MyString::find(int find_from, char c) const{
    MyString temp(c);
    return find(find_from,c);
}
int MyString::compare(const MyString& str) const{
    //1은 사전에 더 뒤에온다 0은 동일하다 -1은 사전에서 앞에있다.
    for(int i=0;i<std::min(str.string_length,string_length);i++){
        if(string_content[i] > str.string_content[i]) return 1;
        else if(string_content[i] < str.string_content[i]) return -1;
    }
    if(str.string_length==string_length)return 0;
    else if(string_length > str.string_length) return 1;
    else return -1;
}
//연산자 오버로딩
bool MyString::operator==(MyString& str){return !compare(str);}
MyString& MyString::operator+=(const Mystring& str){
    if(capacity<string_length+strlen(str)){
        char* prev_content = string_content;
        if(string_length+str.string_length < 2*capacity){
            capacity *=2;
        }else capacity = str.string_length+string_length;
        int i;
        for ( i=0;i<string_length;i++){
            string_content[i] = prev_content[i];
        }
        for(int j=0;j<str.string_length;j++){
            string_content[i+j+1] = str.string_content[j];
        }
    }
    return (*this)
}
char& MyString::operator[](const int index){return string_content[index];}

int main(){

    std::cout<<"Print함수 확인"<<std::endl;
    MyString str1("hello world!");
    MyString str2(str1);
    str1.print();
    str2.println();

    std::cout<<"assign함수 확인"<< std::endl;
    MyString vvvl("very very very very long");
    vvvl.print();
    std::cout << "  "<<vvvl.getcapacity()<<std::endl;
    vvvl.assign("short");
    vvvl.print();
    std::cout << "  "<< vvvl.getcapacity()<<std::endl;
    vvvl.assign("veryveryverylong");
    vvvl.print();
    std::cout<< "  "<<vvvl.getcapacity()<<std::endl;

    std::cout<<"reserve함수 확인"<<std::endl;
    // vvvl.reserve(35);
    std::cout << "capacity : "<<vvvl.getcapacity()<<" length : "<<vvvl.length()<<std::endl;

    std::cout << "at함수 확인"<<vvvl.at(2)<<std::endl;

    std::cout<< "insert 확인 ";
    MyString abc("abc");
    std::cout<< "원래 문자열 ";
    abc.print();
    std::cout<<std::endl;
    MyString d("ed");
    abc.insert(2,d);
    std::cout<<"추가된 문자열 ";
    abc.print();
    std::cout<<std::endl;
    std::cout << abc.getcapacity()<<" l capacity, r length "<<abc.length()<<std::endl;
    std::cout<<abc.at(3)<<std::endl;

    std::cout<<vvvl.length()<<std::endl;
    vvvl.insert(0,d);
    vvvl.println();
    std::cout<<vvvl.getcapacity()<<","<<vvvl.length()<<std::endl;

    vvvl.erase(0,1);
    vvvl.println();
    MyString e("very");
    std::cout<<vvvl.find(0,e)<<std::endl;
    
    std::cout<<"compare test : " << vvvl.compare(e) <<std::endl;

    //explicit
    MyString s= "abc" ;//성공적으로 ㅓㅋㅁ파일됨
    // MyString y = 3; // 이 생성자는 explicit이기때문에 컴파일 안됨
    MyString y(3); //컴파일 가능

    //연산자 오버로딩
    if(s==y)std::cout<<"s y same"<<std::endl;
    else std::cout<< "s y different"<<std::endl;
}