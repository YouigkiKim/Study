#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class SomeClass{
    std::vector<int> vec;
    int num_erased;

    public:
    SomeClass() {
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(2);
        vec.push_back(1);
        vec.push_back(3);
        vec.push_back(4);
    };
    vec.erase(std::remove(vec.begin(),vec.end(),
                            [this] (int i){
                                if(this->num_erased >=2) return false;
                                else {
                                    this->num_erased++;
                                    return true;
                                }
                            } )
                ,vec.end());
};

template <typename Iter>
void print(Iter begin, Iter end) {
  while (begin != end) {
    std::cout << "[" << *begin << "] ";
    begin++;
  }
  std::cout << std::endl;
}
int main() {
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  std::cout << "처음 vec 상태 ------" << std::endl;
  print(vec.begin(), vec.end());

  std::cout << "벡터에서 홀수인 원소 제거 ---" << std::endl;
  vec.erase(std::remove_if(vec.begin(), vec.end(),
// lambda function [capture list] (input) -> returntype {function, return}
                           [](int i) { return i % 2 == 1; }),
            vec.end());
  print(vec.begin(), vec.end());
}