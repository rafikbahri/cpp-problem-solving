#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>

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
        ListNode* removeElements(ListNode* head, int val) {
            if(!head)
                return head;
            if(head->val == val){
                head = head->next;
                return removeElements(head, val);
            }
            ListNode* current = removeElements(head->next, val);
            head->next = current;
            return head;
        }
};

int main() {
    Solution sol;
    
    return 0;
}