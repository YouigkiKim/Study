#include <iostream>

class array{
    int dim;
    int element_num;
    int whole_num;
    int* arr;

    public:
    array(int dim,int element_num)
    int* operator[](int idx)const ;
    int operator[](int idx)const ;
};

array::array(int dim,int num) : dim(n),elemment_num(num){
    whole_num = 1;
    for(int i=0;i<dim;i++){
        whole_num *= element_num;
    }
    int* arr = new int[whole_num];
}

int main(){
    array l(3);
    std::cout<<array[0][0][0];
}