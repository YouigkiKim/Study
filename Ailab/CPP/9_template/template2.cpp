#include <iostream>
#include <string>
#include <array>

//템플릿 함수
template <typename T>
T max(T& a, T& b){
    //3항연산자 ?좌변이 조건문 조건문이 참일때 :의 좌측반환, 거짓일 때 우측반환
    return a > b  ? a : b;
}

// 타입이 아닌 템플릿인자 
//int num = 5 << num의 기본값을 5로 설정할 수 있음. T만 정의된다면 num의 기본값은 5
template <typename T, int num = 5>
T add_num(T t){
    return t+num;
}
template < typename T>
void print_array(const T& arr){
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i] << " ";
    }
    std::cout<<std::endl;
}

//디폴트 템플릿 인자
template<typename T>
struct Compare{
    bool operator()(const T&a, const T& b) const { return a<b;}
};

template<typename T, typename Comp = Compare<T> >

int main(){
    int a =1, b=2;
    std::cout << "Max ( "<< a<<","<<b<<max(a,b) << std::endl;
    std::string s = "hello",t = "world";
    // 함수템플릿은 변수형 선언 필요없음
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
    std::cout << static_cast<int>('a')<<static_cast<int>('b')<<std::endl;


    //타입이 아닌 템플릿인자 실습
    int c = add_num<int,3>(2); //함수의 정의를 템플릿을 사용해 정의 <int형의 함수입력인자와, 고정변수3>
    std::cout <<"배열이 아닌 템플릿인자 <int, 3> : "<< c<<std::endl;
    //std::array<int, 배열의 길이> << 타입이 아닌 템플릿인자
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int , 7> arr2 = {1,2,3,4,5,6,7};
    std::array<int,3> arr3 = {1,2,3};
    //템플릿 함수를 사용해 여러 종류의 변수형이 아닌 템플릿의 입력을 가지는 array에 대해 하나의 함수 만듦
    print_array(arr1);
    print_array(arr2);
    print_array(arr3);

}

