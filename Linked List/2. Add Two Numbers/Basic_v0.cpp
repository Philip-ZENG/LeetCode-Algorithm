// Manipulation on linked-list to add up 2 numbers

/**
 * Definition for singly-linked list.
**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * answer;
        ListNode * pt = nullptr;
        bool first = true;
        int carry = 0;

        while(l1 != nullptr & l2 != nullptr){
            ListNode * node = new ListNode;
            node->next = nullptr;
            node->val = (l1->val + l2->val + carry) % 10;
            if(!first){
                pt->next = node;
            }
            if(first){
                answer = node;
                first = false;
            }
            if((l1->val + l2->val + carry) > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            pt = node;
        }
        while(l1 != nullptr & l2 == nullptr){
            ListNode * node = new ListNode;
            node->next = nullptr;
            node->val = (l1->val + carry) % 10;
            if((l1->val + carry) > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            pt->next = node;
            pt = node;
            l1 = l1->next;
        }
        while(l1 == nullptr & l2 != nullptr){
            ListNode * node = new ListNode;
            node->next = nullptr;
            node->val = (l2->val + carry) % 10;
            if((l2->val + carry) > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            pt->next = node;
            pt = node;
            l2 = l2->next;
        }
        if(carry == 1){
            ListNode * node = new ListNode;
            node->next = nullptr;
            node->val = carry;
            pt->next = node;
        }

    return answer;
    }
};
