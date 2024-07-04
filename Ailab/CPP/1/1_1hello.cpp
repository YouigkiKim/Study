// C++ 표준 입출력 헤더파일
#include <iostream>

// 메인코드
int main() {
    // std >> 이름공간 어디 소속인지 나타냄 std의 공간에 정의된 cout라는 함수, endl이라는 함수
    std::cout <<"Hello, World!!!" << std::endl;
    std::cout << "hi"<<std::endl
    <<"my name is"
    << "김영기" << std::endl;
    return 0;
}



// namespace 사용
// 생성된 헤더파일
#include "header1.h"
#include "header2.h"
namespace header1{
    // 헤더1의 foo실행
    int func(){
        foo();
        // 헤더2의 foo실행
        header2::foo();
    }
    // header2::foo(); 를 여기에 쓰면 오류발생
}

// 헤더1의 foo함수만 사용할 것으로 선언
using header1::foo;

// 헤더1의 함수들을 사용할 것으로 선언 >> 명시적으로 선언하면 헤더2사용가능 
// 하지만 많은 함수를 내포하고 있기 때문에 권장되지 않음
using namespace header1;

// 이름을 지정하지 않은 이름공간 >> static의 효과를 가짐
// static >> 파일범위, 함수범위로 나뉨 함수범위는 파일실행동안 유효하지만 함수호출시에만 사용가능
namespace {
    // 이 함수와 변수는 이 파일에서만 사용가능
    int OnlyInThisFile(){};
    int only_in_this_file=0;

}



