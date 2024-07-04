#include <iostream>

class Animal{
    private:
        int food;
        int weight;
        char name[10];
    public:
        void set_animal( int _food,int _weight ){
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc){
            food += inc;
            weight += (inc/3);
        }
        void view_stat(){
            std::cout << "food : " << food << std::endl;
            std::cout << "weight : " << weight << std::endl;
        }
};

int main(){
    Animal cat;
    cat.set_animal(100,5);
    cat.increase_food(10);
    cat.view_stat();
}