#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Member {
    friend FamilyTree;
    private:
    std::vector<std::shared_ptr<Member>> children;
    std::vector<std::weak_ptr<Member>> parents;
    std::vector<std::weak_ptr<Member>> spouse;

    public:
    void AddParent(const std::weak_ptr<Member>& parent);
    void AddSpouse(const std::weak_ptr<Member>& spouse);
    void AddChild(const std::shared_ptr<Member>& child);
};
class FamilyTree {
    friend Member;
    private:
     std::vector<std::shared_ptr<Member>> entire_family;

     public:
    // 두 사람 사이의 촌수를 계산한다.
    int CalculateChon(const Member& mem1, const Member& mem2);
};
void Member::AddChild(const std::shared_ptr<Member>& child){children.push_back(child);}
void Member::AddParent(const std::weak_ptr<Member>& parent){parents.push_back(parent);}
void Member::AddSpouse(const std::weak_ptr<Member>& spouse1){spouse.push_back(spouse1);}

int FamilyTree::CalculateChon(const Member& mem1, const Member& mem2){
    bool check = false;
    while(check){
        for(std::weak_ptr<Member> elem : mem1.parents){
            std::shared_ptr<Member> temp = std::make_shared<Member>(elem);
            entire_family.push_back(temp);
        }
        for(std::weak_ptr<Member> elem : mem2.parents){
            std::shared_ptr<Member> temp = std::make_shared<Member>(elem);
            entire_family.push_back(temp);
        }
        for(std::shared_ptr<Member> elem : entire_family){
            if(elem.use_count() <= 2){
                check = true;
                std::weak_ptr common = elem;
            }
        }


        //
    }

}