// C와 비슷한 C++
#include <iostream>

//포인터 변수 선언
int arr[10];
//parr라는 포인터 변수는?? >> arr[0]의 주소
int *parr = arr;
//int *parr = &arr[0]; //과 위의 문장은 동일하다
int i;
// pi라는 포인터변수는 i의 주소를 가짐
int *pi = &i;

int main(){
    //변수선언은 C와 비슷함 아래와 같이 한번에 선언 가능
    int i,sum = 0;
    char c;
    double d;
    float f;

    // for문 문장구조 사용직전에 정의도 가능 int i
    for (int i=0;i<10;i++){
        sum +=i;
        std::cout<<i<<" sum = "<< sum <<std::endl;
    }
    i = 0;
    //while 
    while(i <= 10){
        std::cout << i<<std::endl;
        i++;
    }
    

    return 0;

}