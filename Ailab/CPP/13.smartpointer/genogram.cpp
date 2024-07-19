#include <iostream>
#include <vector>
#include <memory>


class Member {
    friend FamilyTree;
    private:
    std::vector<std::shared_ptr<Member>> children;
    std::vector<std::weak_ptr<Member>> parents;
    std::vector<std::weak_ptr<Member>> spouse;

    public:
    void AddParent(const std::shared_ptr<Member>& parent);
    void AddSpouse(const std::shared_ptr<Member>& spouse);
    void AddChild(const std::shared_ptr<Member>& child);
};
class FamilyTree {
    friend Member;
    private:
     std::vector<std::shared_ptr<Member>> entire_family;

     public:
    // 두 사람 사이의 촌수를 계산한다.
    int CalculateChon(Member* mem1, Member* mem2);
};
void Member::AddChild(const std::shared_ptr<Member>& child){children.push_back(child); }
void Member::AddParent(const std::shared_ptr<Member>& parent){parents.push_back(parent);}
void Member::AddSpouse(const std::shared_ptr<Member>& spouse1){spouse.push_back(spouse1);}

int FamilyTree::CalculateChon(Member* mem1, Member* mem2){
    int i = 0;
    std::vector<std::shared_ptr<Member>> parents1;
    std::vector<std::shared_ptr<Member>> parents2;
    while(mem1->parents!= mem2->parents){
        
        std::vector<std::shared_ptr<Member>> temp1 = parents1;
        std::vector<std::shared_ptr<Member>> temp2 = parents2;
        parents1.clear();
        parents2.clear();
        for(std::shared_ptr<Member> elem1 : temp1){
            for(Member elem : elem1){
                parents1.push_back(elem);
            }
            for(auto elem : temp2.parents){
                parents2.push_back(elem);
            }
        }
        i++;
    }

    return i;
}