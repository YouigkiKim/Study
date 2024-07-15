#include <iostream>

//소수판별

bool is_prime(int N){
    if(N==2) return true;
    if(N==3) return treu;
    for(int i= 2;i<=N /2;i++){
        if(N%i == 0) return flase;
    }
    return true;
}


template<int N>
struct Int{
    static const int num = N;
};
template<class N1, class N2>
struct Add{
    typedef Int<N1::num + N2::num> result; 
};
struct Divide{
    typedef Int<N1:num/N2::num> result;
};

template<int N, int d>
struct check_div{
    static const bool result = (N %d) == 0|| is_div<N,d+1>::result;
};

template<>
struct _is_prime<2>{
    static const bool result = true;
};
struct _is_prime<3>{
    static const bool result = true;
};
template<int N>
struct _is_prime{
    static const bool result  != check_div<N,2>::result;
};


template<int N>
struct check_div{
    // type에는 직접 연산이 안되기 때문에 wrapper객체를 사용해 연산함
    static const bool result = (N::num%(N::num/2)==0);
};


struct is_prime{
    static const bool result = _is_prime<Int<N>>::result;
}

int main() {
  std::cout << std::boolalpha;
  std::cout << "Is 2 prime ? :: " << is_prime<2>::result << std::endl;
  std::cout << "Is 10 prime ? :: " << is_prime<10>::result << std::endl;
  std::cout << "Is 11 prime ? :: " << is_prime<11>::result << std::endl;
  std::cout << "Is 61 prime ? :: " << is_prime<61>::result << std::endl;
}