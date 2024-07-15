/*
가변길이 템플릿
파라미터 팩
폴드 형식
*/


// 파이썬에서 print -> 모든 인자를 print가능 -> cpp에서 template을 통해 간으

#include <iostream>
#include <string>

//재귀적으로 구성된 코드 두 코드의 순서를 바꾸면 오류발생
//컴파일 시 자기 앞에있는 함수밖에 보지 못하기때문ㅇ
template <typename T>
void print(T arg){
    std::cout << arg<<std::endl;

}
// typename... >>파라미터 팩
template <typename T, typename... Types>
void print(T arg, Types...args){
    std::cout << arg << ",";
    print(args...);
}




//임의의 개수의 문자열을 합치는 함수
// concat = s1+s2+s3
// 는 각각의 변수마다 메모리 할당, 해제가 발생할 수 있다.

//GetStringSize의 재귀적 구현 char, string모두 호환
size_t GetStringSize(const char *s){return strlen(s); }
size_t GetStringSize(const std::string& s){return s.size(); }
template <typename String, typename... Strings>
size_t GetStringSize( const String& s, Strings... strs){
    return GetStringSize(s)+GetStringSize(strs...);
}

//AppendToString의 재귀적 구현
void AppendToString(std::string* concat_str){ return ; }
template <typename String, typename... Strings>
void AppendToString(std::string* concat_str,const String& s, Strings... strs){
    concat_str -> append(s);
    AppendToString(concat_str, strs...);
}

//입력인자의 개수에 상관없이 문자열을 합치는 함수
template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs){
    size_t total_size = GetStringSize(s,strs...);

    std::string concat_str;
    concat_str.reserve(total_size);
    concat_str = s;

    AppendToString(&concat_str, strs...);
    return concat_str;
}




// ...sizeof > 남아있는 인자들의 개수를 알려줌

int main(){
    print(1,3.1,"abc");
    print(1,2,3,4,5,6,7);

    std::cout << StrCat(std::string("this"), " "
        , "is ", " ", std::string("a")," ",std::string("sentence"))<<std::endl;
    return 0;
}