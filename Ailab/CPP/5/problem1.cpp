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
    for(int i=0;i<dim;i++){
        int*ptr = &whole_num[element_num*(i+1)];
        
    }
    int* array = new int[whole];
    for(int i<dim){
        int* D = array
    }
    // for(int i=0;i<dim;i++){
    //     if(i != dim-1){
    //         int** ptr = new int*[element_num];
    //     }
    //     if(i!=dim-1){
    //         int* prevelement = list;
    //         int** element = new int*[element_num];
    //     }else{
            
    //     }
    // }
}

int main(){
    array l(3);
    std::cout<<array[0][0][0];
}