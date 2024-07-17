#include <iostream>
#include <exception>

class Parent : public std::exception{
    public:
    virtual const char* what() const noexcept override{return "Parent!\n";};
};

class Child : public Parent{
    public:
    const char* what() const noexcept override {return "Child!\n";}
};

int func(int c){
    if(c==1){
        throw Parent();

        throw Child();
    }else if(isdigit(c)){
        throw std::out_of_range("out_of_range");
    }else{
        throw std::overflow_error("put in number");
    }
    return 0;
}

int main(){
    int c;
    while(c != 0){
        std::cin >>c;
        try{
            // func(c);
            if(c==1){
                throw Parent();
            }else if(c ==2 ){
                throw Child();
            }else{
                throw std::out_of_range("out_of_range");
            }
        }catch(Child &c){
            std::cout <<"Child catched"<<std::endl;
            std::cout << c.what();
        }catch(Parent &p){
            std::cout << "Parent catched"<<std::endl; // child를 parent로 받을 수 있기 때문에
            std::cout << p.what(); // parent로 catch되고 child의 what이 실행된다>> child보다 뒤에 정의되어야함 
        }catch(std::out_of_range& e){
            std::cout << e.what() << " dd" <<std::endl;
        }catch(...){
            std::cout << "default exception"<<std::endl;
        }
    }
}