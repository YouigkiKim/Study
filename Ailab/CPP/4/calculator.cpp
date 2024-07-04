#include <iostream>
#include <cmath>
class Point{
    int x,y;
    public:
    //생성자
    Point(int pos_x,int pos_y){
        x = pos_x;
        y = pos_y;
        std::cout << "Point Created (x,y) " << x<<','<<y << std::endl;
    };
    Point(){
        x= 0;
        y=0;
        std::cout << "Point Created (x,y) " << x<<','<<y << std::endl;
    }
    //x와 y의 값을 불러오는 함수
    int GetX(){return x;}
    int GetY(){return y;}
    friend class Geometry;
};

class Geometry{
    private:
    int num_points;
    Point*point_array[100]; // 포인트들의 주소를 저장하는 100개의 배열

    public:
    Geometry(){
        num_points = 0;
        Point orin;
        AddPoint(orin);
    }
    void AddPoint(const Point& point){ // 상수 레퍼런스 point생성
        point_array[num_points ++] = new Point(point.x,point.y); // 힙에 Point생성
    }
    void PrintDistance();
    void PrintNumMeets();
    double GetLine(const Point& point1, const Point& point2);
    void DeleteHeap(){
        for (int i=0;i<num_points;i++){ 

            delete point_array[i];
        }
    }
    void GetPoint(int i){
        std::cout<< point_array[i] -> x << ", " << point_array[i] -> y<< std::endl;
    }
};

void Geometry::PrintDistance(){
    std::cout << "Distance"<<std::endl;
    double** arr = new double*[num_points]; // rrows
    for (int i=0;i<num_points;i++){
        arr[i] = new double[num_points]; // cols
    }
    for (int i=0;i<num_points;i++){
        for(int j=0;j<num_points;j++){
            int x1 = point_array[i] -> x;
            int y1 = point_array[i] -> y;
            int x2 = point_array[j] ->x;
            int y2 = point_array[j] -> y;
            arr[i][j] =std::sqrt((x1-x2)*(x1-x2) +(y1-y2)*(y1-y2));
            std::cout << arr[i][j]<<",  ";
        }
        std::cout << std::endl;
    }
    //메모리 해제
    for(int i=0;i<num_points;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
void Geometry::PrintNumMeets(){
    int crossnum = 0;
    std::cout<<"Number of Cross"<<std::endl;
    for (int i=0;i<num_points;i++){
        int x1 = point_array[i] -> x;
        int y1 = point_array[i] -> y;
        for(int u = num_points-1;u>i; u--){
            int x2 = point_array[u] -> x;
            int y2 = point_array[u] -> y;
            //두 점간의 라인 형성
            double line1[3] = {x1-x2,y1-y2,-x1*(x1-x2)/(y1-y2)};
            for (int j=0;j<num_points;j++){
                if(j != u && j!=i){
                    int x3 = point_array[j] -> x;
                    int y3 = point_array[j] -> y;
                    for(int k=num_points-1;k>j;k--){
                        if(k!=u && k!=i){
                            int x4 = point_array[k] -> x;
                            int y4 = point_array[k] -> y;
                            //두 점 정의 후 line방정식에 대입 해 위치확인   
                            double classify1 = line1[0]*x3+line1[1]*y3+line1[2];
                            double classify2 = line1[0]*x4+line1[1]*y3+line1[2];
                            //부호가 다를경우 crossnum+1
                            if(classify1*classify2<0){
                                crossnum++;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout <<" 교점의 개수 : "<<crossnum/2<<std::endl;
}
int main(){
    Point point1(1,2);
    Point point2(3,5);
    Point point3(7,1);
    Geometry geometry;
    geometry.AddPoint(point1);
    geometry.AddPoint(point2);
    geometry.AddPoint(point3);
    geometry.GetPoint(0);
    geometry.GetPoint(1);
    geometry.PrintDistance();
    geometry.PrintNumMeets();
    geometry.DeleteHeap();
    return 0;   
}