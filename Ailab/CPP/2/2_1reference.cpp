#include <iostream>

int change_val(int* p){
    *p = 3;
    return 0;
}

// 원래함수에 존재하던 변수를 참조 해 조작 후 리턴 >> 변수값의 복사가 불필요 >> 메모리절약
// 함수시작 시  int& a = 변수 로 참조자 초기화
int& function(int&a){
    a = 5;
    return a;
}

int main(){
    //예제
    int number = 5;
    std::cout << number<< std::endl;
    change_val(&number);
    std::cout<<number<<std::endl;


    //c++의 참조자 사용
    int a = 3;
    //참조자(reference) 정의 >> 변수형 뒤에 &사용 *&사용 시 포인터 참조자
    //참조자 >> 변수의 또다른 이름 a 의 또다른 이름 another_a 
        //참조자는 메모리에 존재하지 않을수도 있음 another_a를 a로 대치하면 되기 때문
        // 등호의 왼쪽은 참조자 선언시 사용, 등호의 오른쪽은 주소연산자, 주소 받아올 때 사용
    int& another_a = a;
    another_a = 5;
    std::cout<<"a : "<<a<<std::endl;
    std::cout<<"another_a : "<<another_a<<std::endl;

    // 참조자 실습코드
    int x;
    int &y = x;
    int& z = y;
    x = 1;
    std::cout<<"x : "<< x<<"y: "<<y<<"z: "<<z<<std::endl;
    y = 2;
    std::cout<<"x : "<< x<<"y: "<<y<<"z: "<<z<<std::endl;
    z = 3;
    std::cout<<"x : "<< x<<"y: "<<y<<"z: "<<z<<std::endl;
    int w;
    //cin 은 함수내부에서 참조연산자를 활용해 변수에 값 할당 이후 터미널출력
    std::cin >> w;

    //배열(array)의 레퍼런스, 레퍼런스의 배열
        //레퍼련스의 배열은 존재 불가능 
        //배열의 주소는 첫번째 원소의 주소값에서 하나씩 더해짐
        //이는 메모리상에 존재한다는 의미이지만 레퍼런스는 특별한 경우가 아닌 이상 메모리에 존재하지않음
        //따라서 레퍼런스의 배열은 모순

        //배열의 레퍼런스는 가능
        //크기가 3인 배열 정의
        int arr[3] = {1,2,3};
        //크기가 3인 배열의 레퍼런스ref정의 (&변수이름) 괄호안에 작성
        int (&ref)[3] = arr;
        ref[0] = 2;
        ref[1] = 3;
        ref[2] = 1;
        std::cout << arr[0]<<arr[1]<<arr[2]<<std::endl;

    //원래의 경우라면 int& c = func(); 과 같은 참조자로 리턴을 받는 문장은 
    //리턴 시 사라지는 지역변수를 참조학기 때문에 문법에 어긋남
    // 하지만 상수로 선언한 const int& c = func(); 와 같이 const로 선언하게되면 예외적으로 처리가능
    return 0;   
}