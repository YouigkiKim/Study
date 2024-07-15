#include <iostream>

//std::Array의 template을 통한 구현
template <typename T, unsigned int N>
class Array{
    T data[N];

    public:
    Array(T (&arr)[N]){
        for (int i=0;i<N;i++){
            data[i] = arr[i];
        }
    };
    T* get_array(){ return data; };
    unsigned int size() { return N;};
    void print_all() const {
        std::cout << "data : ";
        for(int i = 0;i<N;i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    T& operator[](int i){ return data[i];};
};


// Wrapper Class, Operator - Template Meta Programming
template<int N>
struct Int{
    static const int num = N;
};
typedef Int<1> one;
typedef Int<2> two;
template<typename T, typename U>
struct add{
    // Int<3>을 result로 typedef한다
    typedef Int<T::num+U::num> result;
};
template < int N>
struct Factorial{
    static const int fac = N*Factorial<N-1>::fac;
};
template<>
struct Factorial<1>{
    static const int fac = 1;
};

//최대공약수 구하기
int gcd(int a, int b){
    return gcd(a,a%b);
} // TMP

template<int a, int b>
struct GCD{
    typedef GCD<b,a%b> type;
    static const int value = GCD<b,a%b>::value;
};
template<int a> // 템플릿 구체화를 통한 재귀템플릿의 종료
struct GCD<a,0>{
    static const int value = a;
};

//Ratio의 구현
template<int N, int D = 1>
struct Ratio{
    typedef Ratio<N,D> type;
    static const int num = N;
    static const int den = D;
};
template<class R1, class R2>
struct _Ratio_add{
    typedef Ratio< R1::num*R2::den + R1::den*R2::num, R1::den*R2::den > type;
};
//Ratio를 상속받아 Ratio add생성
template<class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main(){
    int arr[3] = {1,2,3};
    Array<int,3> arr2(arr);

    arr2.print_all();
    std::cout<< arr2[0] <<std::endl;
    arr2[0]  = 2;
    arr2.print_all();
    //one 과 two는 컴파일타임에 정해져서 현재 코드상에서도 확인가능
    std::cout<< "template one, two : "<< one::num<<", "<<two::num<<std::endl;
    typedef add<one,two>::result three;
    std::cout << "TMP add : " << three::num<< std::endl;
    std::cout <<Factorial<5>::fac<<std::endl;
    std::cout << " GCD by TMP : "<< GCD<30,20>::value<<std::endl; 

    typedef Ratio<12,11> rat1;
    typedef Ratio<17,19> rat2;
    typedef _Ratio_add< Ratio<1,2>, Ratio<3,4> >::type addedRatio;
    typedef Ratio_add<rat1,rat2> rat4;
    typedef _Ratio_add<rat1, rat2 >::type rat3;
    typedef GCD<addedRatio::num,addedRatio::den> GGG;
    using GGG GCD<addedRatio::num,addedRatio::den>;
    typedef Ratio<addedRatio::num/GGG::value  , addedRatio::den/GCD<addedRatio::num,addedRatio::den>::value  >::type finalType;
    std::cout << "before GCD by TMP : "<< addedRatio::num<<"/"<<addedRatio::den<<std::endl;
    std::cout << "final type : "<< finalType::num<<"/"<<finalType::den<<std::endl;
    std::cout << "TMP Ratio add " << rat4::num << "/"<<rat4::den<<std::endl;
    return 0;
}