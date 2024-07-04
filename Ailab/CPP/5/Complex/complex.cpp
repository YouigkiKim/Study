#include <iostream>
#include <cmath>
class Complex{
    private:
    double real, img;

    public:
    Complex(double real, double img):real(real),img(img){}
    Complex(const char* str);
    //연산자 오버로딩 연산자를 오버로딩할 때 자기 자신을 리턴하지 않는 연산자들은 외부에 선언하는 것이 원칙
    //밑에 함수들 다 밖으로 빼야됨
    // Complex operator+(const Complex& c) const;
    // Complex operator-(const Complex& c) const;
    // Complex operator*(const Complex& c) const;
    // Complex operator/(const Complex& c) const;
    //자기 자신을 리턴하는 연산자들은 멤버함수로 선언하는 것이 원칙 
    Complex& operator=(const Complex& c);
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);
    double get_number( const char* str,int begin, int end) const;
    void println(){std::cout<<"( "<<real<<"+i"<<img<<" )"<<std::endl;};

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator-(const Complex& a, const Complex& b);
    friend Complex operator/(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os,const Complex& a);
    friend std::istream& operator>>(std::istream& os, const Complex& c);
};
//레퍼런스를 반환하지 않는 이유 >> 원래 객체는 유지하며 등호 형식으로 새로운 객체를 형성하기 위함
//사칙연산의 항이 두개 이상 되는데 레퍼런스로 반환할 경우 원래의 값이 덮어씌워짐
// Complex Complex::operator+(const Complex& c)const{
//     Complex temp(real+c.real,img+c.img);
//     return temp;
// }
Complex::Complex(const char* str){
    int begin = 0,end = strlen(str);
    double str_img,str_real;
    int pos_i = -1;
    for (int i=0;i<end;i++){
        if(str[i] == 'i'){
            pos_i = i;
            break;
        }
    }
    if (pos_i == -1){
        real = get_number(str,begin,end-1);
        img =0.0;
    }
    else{
        real = get_number(str,begin,pos_i);
        img = get_number(str,pos_i,end-1);
        if(str[pos_i-1]=='-') img*=-1.0;
    }
}
// Complex Complex::operator-(const Complex& c)const{
//     Complex temp(real-c.real,img-c.img);
//     return temp;
// }
// Complex Complex::operator*(const Complex& c)const{
//     Complex temp(real*c.real-img*c.img,real*c.img+img*c.real);
//     return temp;
// }
// Complex Complex::operator/(const Complex& c)const{
//     double denum = c.real*c.real+c.img*c.img;
//     Complex temp((real*c.real+img*c.img)/denum,(-real*c.img+img*c.real)/denum);
//     return temp;
// }
// 대입연산자는 레퍼런스인 이유 >> 우변의 항이 많아 여러번 변해도 레퍼런스는 계속 값을 따라가기 때문
Complex& Complex::operator=(const Complex& c){
    real = c.real;
    img = c.img;
    return *this;
}
Complex& Complex::operator+=(const Complex& c){
    (*this) = (*this)+c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c){
    (*this) = (*this) -c;
    return (*this);
}
Complex& Complex::operator*=(const Complex& c){
    (*this) = (*this) *c;
    return (*this);
}
Complex& Complex::operator/=(const Complex& c){
    (*this) = (*this)/ c;
    return (*this);
}
double Complex::get_number(const char* str, int begin, int end) const{
    bool minus = false;
    if(begin>=end)return 0;
    if(str[begin] == '-') minus = true;
    if(str[begin] == '-' || str[begin] == '+') begin++;
    double num = 0.0;
    double decimal = 1.0;
    bool integer_part = true;
    for (int i=begin;i<end;i++){
        if(isdigit(str[i])&&integer_part){
            num*=10.0;
            //문자열은 ascii코드의 번호로 반환 >> 문자열0의 아스키번호를 빼주면 실제 숫자반환가능
            num+=(str[i]-'0'); 
        }else if(str[i]=='.'){
            integer_part=false;
        }else if(isdigit(str[i])&&!integer_part){
            decimal/=10.0;
            num+=(str[i]-'0')*decimal;
        }else break;
    }
    if(minus) num *= -1.0;
    return num;
}

// friend 명령어를 통해 Complex멤버변수에 접근 >> 문자열 + Complex를 가능하게 해주는 외부함수
Complex operator+(const Complex& a,const Complex& b) {
    Complex temp(a.real+b.real,a.img+b.img);
    return temp;
}
Complex operator-(const Complex& a,const Complex& b){
    Complex temp(a.real-b.real,a.img-b.img);
    return temp;
}
Complex operator*(const Complex& a, const Complex& b){
    Complex temp(a.real*b.real-a.img*b.img,a.real*b.img+a.img*b.real);
    return temp;
}
Complex operator/(const Complex& a, const Complex& b){
    double den = b.real*b.real+b.img*b.img;
    Complex temp((a.real*b.real+a.img*b.img)/den,(a.img*b.real-a.real*b.img)/den);
    return temp;
}
std::ostream& operator<<(std::ostream& os, const Complex& a){
    os << "("<<a.real<<"+i"<<a.img<<")";
    return os;
    }
Complex operator>>(std::istream& os){
    Complex temp(os);
    return temp;
}
int main(){
    Complex a(2,3);
    Complex b(4,2);
    Complex c = a+b;
    c.println();
    Complex d = a*b;
    d.println();
    Complex e = a/b;
    e.println();
    Complex h = a+b+c+e+d+a*b/c+a;
    h.println();
    h/=a;
    h.println();
    Complex g("1+i4");
    g.println();
    Complex i = "1+5i" + a;
    i.println();

    //<<operator 오버로딩
    std::cout<<i<<std::endl;
    return 0;
}