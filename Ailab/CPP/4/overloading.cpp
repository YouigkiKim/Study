#include <iostream>

//////////////
//오버로드 과정
//1. 타입이 정확히 일치하는 함수를 찾음 
//2. 없을경우형변환 규칙에 맞춰 비슷한 함수 찾음
//3. 2단계에도 찾지 못한 경우 더 포괄적인 형변환을 통해 찾음
//4. 유저 정의된 타입 변환으로 일치하는 것 찾음
//위의 경우에 해당하지 않는 경우 모호함으로 판단하고 오류메세지
//////////////

// 함수의 오버로딩 >> 같은 이름을 가진 함수라도 입력인자의 구분을 통해 따로 작동함
void print(int x) { std::cout << "int : " << x << std::endl;}
void print(char x) { std::cout << "char : "<< x << std::endl;}
void print(double x){std::cout<<"double : "<< x<< std::endl;}


int main(){
    int a = 1;
    char b = 'g';
    double c = 3.1415;
    // 같은 이름의 print함수여도 입력인자에 따라 실행하는 함수가 다름
    print(a);
    print(b);
    print(c);
    return 0;
}
