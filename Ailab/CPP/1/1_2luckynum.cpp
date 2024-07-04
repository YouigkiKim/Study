#include <iostream>

int main(){
    int lucky_number= 3;
    std::cout<<"맞춰보셈"<<std::endl;
    int user_input;
    while(1){
        std::cout<<"입력: ";
        //cin은 유저의 입력을 받는 명령어 >> 쉬프트를 통해 해당변수로 저장함
        std::cin >> user_input;
        if(user_input == lucky_number){
            std::cout<<"정답"<<std::endl;
            break;
        } else{
            std::cout<<"오답"<<std::endl;
        }

    }
    return 0;
}