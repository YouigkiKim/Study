#include <iostream>


class Marine{
    //static변수는 모든 클래스에서 공통적으로 사용하는 변수정의하는 방법도 다름
    static int total_marine_num;
    int hp;
    int coord_x,coord_y;
    int damage;
    bool is_dead;
    char* name;
    //const int >> 객체의 선언화 함께 초기화되어야하는 변하지 않는 변수
    //따라서 초기화 리스트를 통해 생성해야함 >> 이후 코딩으로 변하는 오류를 방지할 수 있음
    const int default_damage;

    public:
    Marine(); // 기본 생성자
    Marine(int x,int y); // 좌표에 생성
    Marine(int x, int y, const char* marine_name);
    Marine(int x, int y, int default_damage);
    ~Marine();
    int attack(); // 데미지를 리턴
    Marine& be_attacked(int damage_earn);//입는 데미지
    void move(int x, int y); // 새로운 위치
    void show_status();

    //static 함수 클래스 공통 함수 사용 또한 Marine::show_total_marine()으로 사용해야함
    static void show_total_marine();
};

//static 함수 정의
void Marine::show_total_marine(){
    std::cout<<"현재 총 마린 수 :"<< total_marine_num<<std::endl;
}
//static 변수 초기화
int Marine::total_marine_num = 0;

//초기화 리스트를 통한 멤버변수 초기화
//초기화 리스트를 사용하는 이유 > 생성 후 대입 두단계가  생성하면서 대입 한단계로 줄어듦
//int a;int a = 10 >>> int a = 10;
//추가로 생성과 동시에 초기화되어야 하는 것들 const, reference에서 오류발생 
Marine::Marine() 
    : default_damage(5), hp(50),coord_x(0),coord_y(0),damage(5),is_dead(false),name(NULL){total_marine_num++;}
Marine::Marine(int x, int y) 
    : default_damage(5),hp(50),coord_x(x),coord_y(y),damage(5),is_dead(false),name(NULL){total_marine_num++;}
// const int 값에 변수값을 대입해도 생성 시 초기화하기 때문에잘 작동함
Marine::Marine(int x, int y, int default_damage) 
    : default_damage(default_damage),hp(50),coord_x(x),coord_y(y),damage(5),is_dead(false),name(NULL){total_marine_num++;}
Marine::~Marine(){
    if(name) delete[] name;
    total_marine_num -- ;
}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attack(){ return damage; }

// 참조를 반환하는 함수
Marine& Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0){
        is_dead = true;
    }
    //자기 자신을 반환
    return *this;
}
void Marine::show_status(){
    std::cout<<" ***Marine*** "<< std::endl
    <<"Location : (" << coord_x<<", " << coord_y<<")"<< std::endl;
    std::cout<<"hp : " << hp<<std::endl;
}
int main(){
//생성자 초기화를 통한 클래스선언
    Marine marine1(1,2);
    Marine marine2;
    Marine::show_total_marine();
    marine1.show_status();
    marine2.show_status();
    // 자기 자신을 반환함으로써 연속된 메서드에서도 공격당한 상태를 반영
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
    marine2.show_status();
    return 0;
}