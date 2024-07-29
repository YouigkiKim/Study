#include <thread>
#include <iostream>
#include <cstdio>
#include <vector>
using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result){
    int sum = 0;
    for(auto itr = start;itr<end;++itr){
        sum+= *itr;
    }
    *result = sum;
    thread::id this_id = std::this_thread::get_id();
    //printf는 중간에 문맥교환이 일어나도 모두 출력할 수 있음
    printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 %d \n", this_id, *start, *(end-1), sum);
}

int main(){
    //합할 데이터 저장
    vector<int> data(10000);
    for(int i=0;i<10000;i++){
        data[i] = i;
    }

    vector<int> partial_sums(4);

    //thread 할당
    vector<thread> workers;
    for(int i=0;i<4;i++){
        workers.push_back(thread(worker, data.begin()+i*2500,data.begin()+(i+1)*2500, &partial_sums[i]));
    }


    //thread 실행 및 반환까지 대기
    for(int i=0;i<4;i++){
        workers[i].join();
    }
    //total 합 구하기
    int total;
    for (int i=0;i<4;i++){
        total += partial_sums[i];
    }

    std::cout << "전체 합 : "<<total<<std::endl;
}