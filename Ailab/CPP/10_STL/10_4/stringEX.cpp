#include <iostream>
#include <string>




int main(){
    std::u32string u32_str = U"이건 UTF-32 문자열 입니다";
    // u32string 객체 정의
    // U는 UTF-32문자열으로 인코딩하라 선언
    std::string str = u8"이건 UTF-8 문자열 입니다";
    //선언방식 위와 동일, string객체
    //대부분의 시스템은 utf-8이므로 자동으로 형성됨
    std::cout <<"u32문자열의 크기 : "<< u32_str.size()<<std::endl;
    std::cout <<"u8문자열의 크기 : "<< str.size()<<std::endl;


    std::u16string u16_str = u"이건 UTF-16 문자열 입니다";
    std::cout << u16_str.size() << std::endl;
}