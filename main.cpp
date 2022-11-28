#include <iostream>

using namespace std;

struct ListNode{
    int val{};
    ListNode *next,*prev;
    explicit ListNode(int x);
};

    ListNode *first = nullptr;
    ListNode *last;

ListNode::ListNode(int x) : val(x){
    if(first == nullptr){
        first = this;
        prev = nullptr;
    }else if(first != nullptr){
        last->next = this;
        prev = last;
    }
    last = this;
    next = nullptr;
}

class Control{
public:
    void info(ListNode &x){
        cout << "obj str: " << &x <<" next: " <<x.next <<" first: "<<first<<" last: "<<last<<'\n';
    }
    void ListOut(ListNode *x){
        cout << x->val << '\n';
        if(x->next != nullptr) {
            ListOut(x->next);
        }
    }
    void push_back(int x){
        new ListNode(x);
    }
    void sort(ListNode *a) {
        if (a->val > a->next->val) {
            int temp = a->next->val;
            a->next->val = a->val;
            a->val = temp;
            sort(a);
        } else if (a->val <= a->next->val) {
            if(a->next != nullptr){
                sort(a->next);
            }
        }
    }
};

int main() {

    Control sys;

    ListNode a(9);
    //sys.info(a);
    ListNode b(5);
    //sys.info(b);
    ListNode c(6);
    //sys.info(c);


    sys.sort(first);
    sys.ListOut(first);

    return 0;
}
