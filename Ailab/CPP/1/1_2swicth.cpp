#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main(){
    int user_input;
    cout<<"정보"<<endl<<"1.이름"<<endl<<"2.나이"<<endl<<"3.성별"<<endl;
    cin>>user_input;
    //해당 변수에 맞는 코드 실행
    switch(user_input){
        case 1:
        cout<< "Psi"<<endl;
        break;
        case 2:
        cout<<"27"<<endl;
        break;
        case 3:
        cout<<"man"<<endl;
        break;
        // 각 항목마다 break없으면 default도 실행됨
        default:
        cout<<"bye"<<endl;
        break;
    }
    return 0;
}