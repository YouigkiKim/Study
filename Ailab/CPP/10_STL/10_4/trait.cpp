#include <cctype>
#include <iostream>
#include  <string>

struct my_char_traits : public std::char_traits<char>{
    static int get_real_rank(char c){
        if(isdigit(c)){
            return c+256;
        }
        return c;
    }

    static bool lt(char c1, char c2){
        return get_real_rank(c1)<get_real_rank(c2);
    }

    static int compare(const char* s1, const char* s2 , size_t n){
        while (n-- !=0){
            if(get_real_rank(*s1) < get_real_rank(*s2)){
                return -1;
            }
            if(get_real_rank(*s1)>get_real_rank(*s2)){
                return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
};

void* operator new(std::size_t count){
    std::cout << count << " bytes 할당 "<<std::endl;
    return malloc(count);
}

bool contains_very(std::string_view str){
    return str.find("very") != std::string_view::npos;
}
// 문자열에 "very" 라는 단어가 있으면 true 를 리턴함
bool contains_very_nv(const std::string& str) {
  return str.find("very") != std::string::npos;
}

int main(){
    std::basic_string<char,my_char_traits> my_s1 ="1a";
    std::basic_string<char,my_char_traits> my_s2 ="a1";
    std::cout<<"숫자의 우선순귀악 더 낮은 문자열 : "<<std::boolalpha<<(my_s1<my_s2)<<std::endl;
    std::string s1 = "1a";
    std::string s2 = "a1";
    std::cout << "일반 문자열 : "<<std::boolalpha << (s1<s2) <<std::endl;    

    std::cout <<std::endl;
    std::cout <<std::endl;
    std::cout << " 에제2 SSO"<<std::endl;
    std::cout<<"s1생성 --- "<<std::endl;
    std::string s3 = "this is a pretty long sentence!!!";
    std::cout << "s2의 크기 "<< sizeof(s3)<<std::endl;
    std::cout << "s2생성 ==="<<std::endl;;
    std::string s4 = "short sentence";
    std::cout << "s2의크기 : "<<sizeof(s4)<<std::endl;

    std::cout <<std::endl;
    std::cout <<std::endl;
    std::cout << "예제3 string_view는 string객체를 복사하지 않는다"<<std::endl;
      // 암묵적으로 std::string 객체가 불필요하게 생성된다.
  std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
            << std::endl;
      std::cout << contains_very("c++ string is not easy to use") << std::endl;

            std::cout << "string을 참조할 때는 메모리를 할당한다"<<std::endl;
  std::cout << std::boolalpha << contains_very_nv("c++ string is very easy to use")
            << std::endl;
  std::cout << contains_very_nv("c++ string is not easy to use") << std::endl;

            

}