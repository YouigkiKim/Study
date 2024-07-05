#include <iostream>
namespace{
    class Array;
    class Int;
}
class Array{
    friend Int;
    
    const int dim;
    //차원정보를 담고있는 배열
    int* size;
    //구조체는 멤버변수와 멤버함수가 public인 
    struct Address{
        int level;  //현재 주소의 차원 나타냄
        void* next; //다음 저장소의 주소 나타냄 
    };
    Address* top;

    public:
    Array(int dim, int* array_size):dim(dim){
        size = new int[dim];
        for(int i=0;i<dim;i++) size[i] = array_size[i];

        top = new Address;
        top -> level=0;
        initialize_address(top);
        copy_address(top,arr.top);
    }
    Array(const Array &arr):dim(arr.dim){
        size = new int[dim];
        for(int i=0;i<dim;i++)size[i] = arr.size[i];
        top = new Address;
        top->level = 0;
    }
    ~Array(){
        delete_address(top);
        delete[] size;
    }
    void copy_address(Address *dst, Addreess *src){
        //재귀함수의 조건이 만족되면 멈추는 부분
        if(dst->level == dim-1){
            for(int i=0;i<size[dst->level];i++){
                static_cast<int *>(dst->next)[i] = static_cast<int *>(src->next)[i];
            }
            return;
        }
        for(int i=0;i!=size[dst->level];i++){
            //재귀적 함수의 조건이 불만족일 떄 반복되는 부분
            Address *new_dst = static_cast<Address*>(dst->next)+1;
            Address *new_src = static_cast<Address *>(src->next)+i;
            //재귀함수를 구현하기 위해 함수 안에 함수를 넣은 모습
            copy_address(new_dst,new_src);
        }
    }
    void* initialize_address(Address *current){
        if(!current) return;
        if(current -> level == dim -1){
            current -> next = new int[size[current -> level]];
            return;
        }
        //현재 Address의 다음 주소는 Address
        current->next = new Address[size[current->level]];
        for(int i=0;i=size[current->level];i++){
            (static_cast<Address *>(current->next)+i)-> level = current->level+1;
            initialize_address(static_cast<Address*>(current->next)+i);
        }
    }
    void delete_address(Address *current){
        if(!current)return;
        for(int i=0; current->level<dim-1 && i<size[current->level] ;i++){
            delete_address(static_cast<Address*>(current->next)+i);
        }
        if(current->level==dim-1){
            delete[] static_cast<int *>(current->next);
        }
        delete[] static_cast<Address*>(current->next);
    }
    Int operator[](const int index);
};
class Int{
    void* data;
    int level;
    Array* array;

    public:
    Int(int index, int _level=0,void *_data=NULL, Array *_array=NULL)
        : level(_level),data(_data),array(_array){
            if(_level<1||index>=array->size[_level-1]) {
                data = NULL;
                return;
            }
            if(level== array->dim){
                data = static_cast<void *>(
                    (static_cast<int *>(static_cast<Array::Address *>(data)->next)+index);
                )
            }else{
                data = static_cast<void *>(
                    static_cast<Array::Address *>(static_cast<Array::Address *>(data)->next) +index);
            }
        }
};

Int Array::operator[](const int index){
    return Int(index,1,static_cast<void *>(top), this);
}
