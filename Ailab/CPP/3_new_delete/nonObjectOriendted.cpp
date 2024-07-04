//객체지향이 아닌 프로그래밍
#include <iostream>

typedef struct {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

// -> pointer변수의 멤버 찾을 때/// . 직접접근할 때 
//Animal animal 로 선언되었다면 animal.name, animal.age로 접근
void create_animal(Animal *animal){
    std::cout <<"동물의 이름";
    std::cin >> animal -> name;
    std::cout << "동물의 나이";
    std::cin >> animal -> age;

    animal -> health = 100;
    animal -> food = 100;
    animal -> clean = 100;
}

void play(Animal *animal){
    animal -> health +=10;
    animal-> food -=20;
    animal -> clean -=30;
}

void one_day_pass(Animal * animal){
    animal -> health -=10;
    animal -> food -= 30;
    animal -> clean -=20;
}

void show_stat(Animal *animal){
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력 : " << animal -> health;
    std::cout << "배부름 : " << animal -> food;
    std::cout << "청결 : " << animal -> clean;
}

int main(){
    Animal *list[10];
    int animal_num = 0;
    // (;;)을 통해 무한루프 구현
    for(;;){
        std::cout << "1. add animal" << std::endl;
        std::cout << "2. play" << std::endl;
        std::cout << "3. stat" << std::endl;

        int input;
        std::cin >> input;
        switch(input){
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "play with?" << std::endl;
                std::cin >> play_with;
                // 단일 조건문은 중괄호 생략가능
                if(play_with < animal_num) play(list[play_with]);
                break;
            case 3:
                std::cout << "who`s stat"<< std::endl;
                std::cin >> play_with;
                if(play_with < animal_num) show_stat(list[play_with]);
                break;
        }
        for (int i =0;i != animal_num; i++){
            one_day_pass(list[i]);
        }

    }
    for(int i =0;i!=animal_num;i++){
        delete list[i];
    }
    return 0;
}
