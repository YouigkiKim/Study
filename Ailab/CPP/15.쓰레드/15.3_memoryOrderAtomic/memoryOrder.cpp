// 원자성 -> 쓰레드들이 수정순서에 동의해야만 하는 경우는 모든연산들이 원자적일 댸
// 원자적 연산 -> 연산 중간에 다른 쓰레드가 끼어들 여지가 없는 연산

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void worker(std::atomic<int>* counter){
    for(int i=0;i<10000;i++){
        counter -> fetch_add(1,std::memory_order_relaxed);
    }
}



/*
memory order 
  - relaxed - 가장 느슨한 조건 - cpu가 연산순서를 맘대로 정할 수 있음
  - release - 해당 명령 이전의 모든 메모리 명령 해당 명령 이후로 재배치되는 것 막는다
  - acquire - 해당 명령 뒤로 오는 메모리명령들이 해당 명령 앞으로 가는 것을 막는다
  - memory_order_acq_rel - acquire, release 동시에 수행
  - memory_order_seq_cst - 메모리 명령의 순차적 일관성 보장
 
*/
void t1(std::atomic<int>* a,std::atomic<int>* b){
    b->store(1,std::memory_order_relaxed);
    int x = a-> load(std::memory_order_relaxed);
    printf("x: %d \n",x);
}
void t2(std::atomic<int>* a, std::atomic<int>* b){
    a->store(1,std::memory_order_relaxed);
    int y = b-> load(std::memory_order_relaxed);

    printf("y: %d \n",y);
}
int main(){
    //0으로 초기화되는 int형 원자적 변수 counter정의
    std::atomic<int> counter(0);
    std::vector<std::thread> workers;
    for(int i=0;i<4;i++){
        workers.push_back(std::thread(worker,ref(counter)));
    }
    for(int i=0;i<4;i++){
        workers[i].join();
    }
    std::cout << "counter 최종 값"<<counter <<std::endl;

    std::cout <<std::endl;

    std::atomic<int> x;
    //std::boolalpha <<  1을 받으면 true, 0받으면 false
    //원자적 연산이 가능한지 여부
    std::cout << "[원자적 연산이 가능한지 확인] is lock free? "<<std::boolalpha<<x.is_lock_free()<<std::endl;


    std::cout << std::endl;
    std::cout << "memory order example"<<std::endl;

    std::vector<std::thread> threads;
    std::atomic<int> a(0);
    std::atomic<int> b(0);
    threads.push_back(std::thread(t1, &a,&b));
    threads.push_back(std::thread(t2, &a,&b));
    for(int i=0;i<2;i++){
        threads[i].join();
    }
}