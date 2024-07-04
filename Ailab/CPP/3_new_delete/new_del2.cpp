#include <iostream>

int main(){
    int arr_size;
    //배열 크기를 입력받음
    std::cout << "array size: ";
    std::cin >> arr_size;
    //배열 포인터를 new를 통해 힙에 할당
    int* list = new int[arr_size];
    int i = 111;
    std::cout << i << std::endl;
    // 포인터를 이용해 배열 값 변환
    for (int i=0;i<arr_size;i++){
        std::cin >> list[i];
    }
    for (int i=0;i<arr_size;i++){
        std::cout << i+1 << "th element of list : " << list[i] << std::endl;
    }
    // i 는 for문 내부에서 정의되었기 때문에 {}바깥에서는 main에서 정의된 i=111;을 따라감
    std::cout<<i<<std::endl;

    //배열로 할당된 메모리 해제 delete[]
    delete[] list;
    return 0;
}