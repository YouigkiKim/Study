#include <thread>
using std::thread;
#include <iostream>
#include <vector>
using std::vector;

void workers(int& counter){
    for(int i=0;i<10000;i++){
        counter +=1;
    }
}

int main(){
    int counter = 0;

    vector<thread> workers;
    for(int i=0;i<4;i++){
        workers.push_back(thread(workers, std::ref(counter)));
    }

    for(int i=0;i<4;i++){
        workers[i].join();
    }

    std::cout << "Counter 최종 값"<< counter << std::endl;
}