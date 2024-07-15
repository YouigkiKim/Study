#include <iostream>

int sum_all() {return 0; }

template <typename... Ints>
int sum_all(int num, Ints...nums){
    return num+ sum_all(nums...);
}

double average() { return 0; }
template <typename...Ints>
double average(Ints...nums){
    return static_cast<double>(sum_all(nums...))/ (sizeof... (nums));
}




// Fold expansion
//재귀함수를 종료할 베이스함수를 만들어줘야하는 단점이 존재함 > fold expansion으로 해결
template < typename...Ints>
int sum_all_fold(Ints... nums){
    //fold expansion >> 항상 ()로 감싸줘야함
    return (...+nums);
}

int main(){
    std::cout << sum_all(1,2,3,4)<<std::endl;
    std::cout << average(1,4,2,3,10)<<std::endl;
    std::cout << sum_all_fold(1,2,3,4)<<std::endl;

    return 0;
}