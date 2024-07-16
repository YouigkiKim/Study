#include <iostream>



template<typename T>
class deque{
    int num_element;
    T* start_block;
    T* element_block;
    T* end_block;
    T** block;

    public:
    int* iterator;
    deque(int e) : num_element(e){
        **block = new T*[3];
        *element_block = new T[num_element-2];
        *end_block = new T[num_element];
        *start_block = new T[num_element];
        block[0] = &start_block;
        block[1] = &element_block;
        block[2] = &end_block;
    }
    psuh_back(&iterator){
        if(&iterator == &start)
    };
    erase();


    T* operator[] (int e){
        if(e ==1){
            return *start_block[0];
        }else if(e != num_element){
            return (*element_block[e-1]);
        }else{
            return *end_block[0];
        }
    }
    ~deque(){
        for(int i=0;i<num_element;i++){
            delete start_block[i];
            delete end_block[i];
            delete element_block[i];
        }
        delete[] block;
    }
};

int main(){
    


    return 0;
}