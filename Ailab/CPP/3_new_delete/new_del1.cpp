// new, delete는 malloc과 free같이 메모리 할당 및 해제를 뜻함
// new로 힙에 할당된공간이 있는 경우에만 delete로 해제가능
#include <iostream>

int main(){
    // int의 크기공간을 할당해 그 주소값을 포인터로 지정
    int* p = new int;
    //포인터변수를 이용해 해당 주소값에 10입력
    *p = 10;
    std::cout << *p<<std::endl;

    delete p;
    return 0;
}