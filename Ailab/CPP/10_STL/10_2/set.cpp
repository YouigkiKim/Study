#include <iostream>
#include <set>
#include <string>


template <typename T,typename C>
void print_set(std::set<T,C>& s){
    std::cout << "[";
    for(const auto& elam : s){
        std::cout << elam << " ";
    }
    std::cout << "]"<<std::endl;
}
class Todo{
    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
    friend struct TodoCmp;
    int priority;
    std::string job_desc;

    public:
    Todo(int priority, std::string desc ): priority(priority),job_desc(desc){};
    // bool operator<(const Todo& c2)const {
    //     //셋의 정렬 알고리즘을 고려한 우선순위 -> priority만으로 구분하면 중복된 priority가 오지 못함
    //     if( priority == c2.priority) return job_desc <c2.job_desc;
    //     else return priority <c2.priority;
    // }
    //set의 정의
    //template <class Key, class Compare = std::less<Key>,
    //    class Allocator = std::allocator<Key>  // ← 후에 설명하겠습니다
    //    >
    // class set;

};
//함수객체
struct TodoCmp{
    bool operator()(const Todo& t1,const Todo& t2) const{
        if (t1.priority == t2.priority){
            return t1.job_desc<t2.job_desc;
        }
        return t1.priority > t2.priority;
    }
};
std::ostream& operator<<(std::ostream& o, const Todo& td){
    o<<"[priority : "<< td.priority<<"] " <<td.job_desc<<std::endl;
    return o;
};
int main(){
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(20);
    s.insert(50);
    s.insert(40);
    s.insert(70);
    std::cout<<" print set"<<std::endl;
    print_set(s);
    std::set<int>::iterator itr = s.find(25);
    //반복자가 bidirectionIterator이기때문에 이런식으로 찾는다
    if(itr != s.end()){
        std::cout << "25 in s"<<std::endl;

    }else{
        std::cout<< "25 is not in s"<<std::endl;
    }


    /*
    
    
    TOdo
    
    
    */
   std::set<Todo, TodoCmp> todos;
   todos.insert(Todo(1,"농구하기"));
   todos.insert(Todo(2,"수학 숙제하기"));
   todos.insert(Todo(1,"프로그래밍 프로젝트"));
   todos.insert(Todo(3,"친구 만나기"));
   todos.insert(Todo(2,"영화 보기"));
   print_set(todos);

   std::cout << "-------"<<std::endl;
   std::cout<<"end HW"<<std::endl;
   todos.erase(todos.find(Todo(2,"수학 숙제하기")));
    print_set(todos);
    return 0;
}