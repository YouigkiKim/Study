#include <iostream>
#include <string>

int func(int c){
    if( c==1){
        throw 10;
    }else if(c ==2){
        throw std::string("hi!");
    }else if(c==3){
        throw 'a';
    }else if(c==4){
        throw "hello!";
    }
    return 0;
}

int main(){
    int c;
    while(c != 0){
        std::cin >> c;
        try{
            func(c);
        }catch(char x){
            std::cout << "char : "<< x<< std::endl;
        }catch(int x){
            std::cout << "int : "<<x<<std::endl;
        }catch(std::string x){
            std::cout << "string : "<<x<<std::endl;
        }catch(const char* x){
            std::cout << "string literal : "<<x<<std::endl;
        }
    }
}