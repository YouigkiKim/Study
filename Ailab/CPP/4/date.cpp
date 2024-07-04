#include <iostream>

class Date{
    int year_;
    int date_;
    int month_;

    public:
        void SetDate(int year, int month, int date){
            year_ = year;
            date_ = date;
            month_ = month;
        };
        void AddDay(int inc){
            if(month_ == 2){
                if(date_+inc > 28){
                    month_++;
                    date_ = date_+inc-28;
                }
            }
            else if(month_ == 4 or month_ == 6 or month_ == 9 or month_ == 11){
                if(date_+inc<31){
                    date_+= inc;
                }
                else{
                    date_ = date_+inc-30;
                    month_++;
                }
            }
            else{
                if(date_+inc < 32){
                date_ += inc;
                }
                else{
                    date_ = date_+inc-31;
                    month_ ++;
                }
            }
        };
        void AddMonth(int inc){
            if ((month_+inc)>12) year_++;
            month_ = (month_+inc)%12;
        };
        void AddYear(int inc){
            year_ += inc;
        };
        void ShowDate(){
            std::cout << "YYYY.MM.DD " << year_<<"."<<month_<<"."<<date_<<"."<<std::endl;
        }
};

int main(){
    Date date;
    date.SetDate(2024,7,1);
    date.ShowDate();
    date.AddYear(2);
    date.ShowDate();
    date.AddMonth(6);
    date.ShowDate();
    date.AddDay(1);
    date.ShowDate();

    return 0;
}