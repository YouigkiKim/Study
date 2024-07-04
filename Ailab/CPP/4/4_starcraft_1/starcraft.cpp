#include <iostream>
#include <cmath>

class Marine{
    int hp;
    int coord_x,coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
    Marine(); // 기본 생성자
    Marine(int x,int y); // 좌표에 생성
    Marine(int x, int y, const char* marine_name);
    ~Marine();
    int attack(); // 데미지를 리턴
    void be_attacked(int damage_earn);//입는 데미지
    void move(int x, int y); // 새로운 위치
    void show_status();
};
Marine::~Marine(){
    if(name!=NULL) {
        delete[] name;
    }
}
Marine::Marine(int x, int y,const char* marine_name){
    coord_x = x;
    coord_y = y;
    is_dead = false;
    name = new char[strlen(marine_name)+1];
    strcpy(name,marine_name);
}
Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attack(){ return damage; }
void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0){
        is_dead = true;
    }
}
void Marine::show_status(){
    std::cout<<" ***Marine*** "<< std::endl
    <<"Location : (" << coord_x<<", " << coord_y<<")"<< std::endl;
    std::cout<<"hp : " << hp<<std::endl;
}



class Photon_Cannon{
    int hp,shield,coord_x,coord_y,damage;
    char* name;

    public:
    Photon_Cannon();
    Photon_Cannon(int x,int y);
    Photon_Cannon(int x, int y, const char* cannonname);
    Photon_Cannon(const Photon_Cannon& pc); // 복사생성자를 시각화한 것 default로 존재
    ~Photon_Cannon();
    void show_status();
};
Photon_Cannon::~Photon_Cannon(){
    if(name!= NULL) delete[] name;
    std::cout<<"포토캐논 소멸자 호출"<<std::endl;
} //Photon Cannon 소멸자
//오버로딩된 생성자 
Photon_Cannon::Photon_Cannon(int x, int y, const char* cannonname){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = new char[strlen(cannonname)+1];
    std::strcpy(name,cannonname);
    
}
Photon_Cannon::Photon_Cannon(int x, int y){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}
Photon_Cannon::Photon_Cannon(){
    hp = shield = 100;
    coord_x = 0;
    coord_y = 0;
    damage = 20;
    name = NULL;
}
// //복사생성자를 통한 포톤캐논 형성 표준적 정의>  얕은 복사
// Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
//     coord_x = pc.coord_x;
//     coord_y = pc.coord_y;
//     damage = pc.damage;
//     hp = pc.hp;
//     shield = pc.shield;
//     name = pc.name;
// }
//name의 주소를 할당해 깊은 복사 구현
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
    hp = pc.hp;
    shield = pc.shield;

    name = new char[strlen(pc.name)+1];
    std::strcpy(name,pc.name);
    std::cout << "복사생성자를 통한 포토캐논 생성";

}
void Photon_Cannon::show_status(){
    std::cout << "hp : "<< hp<<"shiled : "<<shield<<std::endl;
    std::cout<<"coordinate : "<<coord_x<<", "<<coord_y<<std::endl;
}
int main(){
    // marine 생성
    Marine marine1(1,2);
    Marine marine2(3,4);
    marine1.show_status();
    marine2.show_status();
    std::cout << std::endl<< "마린 1 이 마린 2를공격! "<< std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();

    // marine 배열 생성
    Marine* marine[100];
    //marine의 요소 속에 메모리할당
    marine[0] = new Marine(5,6);
    marine[1] = new Marine(8,9);
    //할당받은 요소의 메모리 해제 주소가 안없어진다? >> dangling 포인터
    //객체 자체를 delete하면 소멸자 호출 후 객체도 해제됨
    marine[0] -> show_status();
    marine[1] -> show_status();
    delete marine[0];
    delete marine[1];


    //포토캐논deprecated 
    Photon_Cannon pc1;
    Photon_Cannon pc2(1,1,"pc2");
    Photon_Cannon pc3 = pc2;

    return 0;
}
