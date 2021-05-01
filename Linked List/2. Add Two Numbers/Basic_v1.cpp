/**
 * Definition for singly-linked list.
**/

// Rearrangement of the code is made comparing to Basic_v0.cpp
// Idea is the same, coding and code structure is improved

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
        ListNode * head;
        ListNode * tail = nullptr;
        int carry = 0;
        int l1_val;
        int l2_val;
        int sum;

        while(l1 || l2){
            l1_val = l1 ? l1->val : 0;
            l2_val = l2 ? l2->val : 0;
            sum = l1_val + l2_val + carry;

            ListNode * node = new ListNode(sum % 10);
            carry = (sum) / 10;
            
            if(tail){
                tail->next = node;
            }else{
                head = node;
            }
            
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
            tail = node;
        }
        if(carry == 1){
            ListNode * node = new ListNode(carry);
            tail->next = node;
        }

    return head;
    }
};
