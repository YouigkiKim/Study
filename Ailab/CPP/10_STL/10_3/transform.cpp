#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end){
    while(begin != end){
        std::cout << "[" << *begin << "]";
        begin ++;
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vec;
    std::vector<int> vec2(6,0);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout <<  "처음 vec 상태" << std::endl;
    print(vec.begin(), vec.end());
    std::cout << "벡터에 1 더한다 "<<std::endl;
    //이전 예제에서는 lambda함수를 remove에 전달했는데 이번에는 transform에 전달
    //transform은 for문과 비슷하게 동작할 것으로 예상됨.
    std::transform( vec.begin(), vec.end(), vec2.begin(),
                    [](int i){return i+1;} );
    // std::transform(vec.begin(), vec.end(), vec2.begin(),
    //                [](int i) -> int { return i + 1; });
    print(vec2.begin(),vec2.end());
    return 0;
}