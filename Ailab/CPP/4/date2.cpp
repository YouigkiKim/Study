#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
    //내장함수
    void SetDate(int year, int month, int day);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);
    int GetCurrentMonthTotalDays(int year,int month);
    void ShowDate();
    //생성자 객체를 초기화하는 함수 오버로딩을 통해 두가지 버전의 초기화함수 제작
    Date(int year, int month, int day){
        year_ = year; 
        month_ = month;
        day_ = day;
    }
    //디폴트 생성자
    Date(){
        year_ = 2024;
        month_ = 7;
        day_ = 1;
    }
    

};
void Date::SetDate(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}
int Date::GetCurrentMonthTotalDays(int year,int month){
    static int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month != 2){
        return month_day[month-1];
    }
    else if(year%4 ==0 && year%100!=0){
        return 29;
    }
    else{
        return 28;
    }
};
void Date::AddDay(int inc){
    while(true){
        int current_month_total_days = GetCurrentMonthTotalDays(year_,month_);
        if (day_+inc <= current_month_total_days){
            day_+=inc;
            return;
        }else{
            inc-=(current_month_total_days-day_+1);
            day_ = 1;
            AddMonth(1);
        }
    }
}
void Date::AddMonth(int inc){
    AddYear((inc+ month_ -1)/12);
    month_ = month_+inc%12;
    month_ = (month_==12 ? 12 : month_%12);
}
void Date::AddYear(int inc){
    year_+=inc;
}
void Date::ShowDate(){
    std::cout << "today YYYY.MM.DD " << year_<<"."<<month_<<"."<<day_<<std::endl;
}

int main(){
    Date day(1991,1,2); // 생성자를 만족해야 객체형성가능 
    day.SetDate(2024,7,1); //오버로딩을 통해 없으면 디폴트로 Date() = default;로 디폴트생서자 정의가능
    day.ShowDate();
    day.AddYear(3);
    day.ShowDate();
    day.AddMonth(20);
    day.ShowDate();
    day.AddDay(2000);
    day.ShowDate();
    //암시적 방법
    Date dayy(2022,1,1);
    //명시적 방법
    Date dayyy = Date(2021,1,1);
    //생성자가 없을 떄 초기화를 하지 않아도 컴파일러가 생성자를 초기화해줌 >> 이상한 값이 출력됨.
    dayy.ShowDate();
    return 0;
}