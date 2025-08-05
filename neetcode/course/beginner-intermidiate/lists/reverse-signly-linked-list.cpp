#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseOpt(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* current = head;
        ListNode* res = nullptr;
        while(current){
            ListNode* newHead = new ListNode(current->val);
            newHead->next = res;
            res = newHead;
            current = current->next;
        }
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        vector<int> stack;
        ListNode *current = head;
        while(current != nullptr){
            stack.push_back(current->val);
            current = current->next;
        }
        ListNode *res = new ListNode(stack[stack.size()-1]);
        ListNode *headRes = res;
        stack.pop_back();
        while(!stack.empty()){
            ListNode *el=new ListNode(stack[stack.size()-1]);
            res->next = el;
            res = res->next;
            stack.pop_back();
        }
        return headRes;
    }
 
    void print(ListNode* head){
        ListNode* current = head;
        while(current != nullptr){
            cout << current->val << endl;
            current = current->next;
        }
    }
};

int main(){
    ListNode* tc1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    Solution* s = new Solution();
    // s->print(tc1);
    ListNode* rvrs1 = s->reverseOpt(tc1);
    // s->print(rvrs1);
    return 0;    
}