#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

 public:
  B(int c) : a(c) {}
  B(const B& b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main() {
//B를 형성할 떄도 복사되어야 하지만, 컴파일러가 막음.
  B b(10);
  std::cout << "---------" << std::endl;
  A a1 = b.get_A();
}