/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry{};
        int num{};
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while(l1 && l2)
        {
            num = l1->val + l2->val + carry;
            carry = num / 10;
            current->next = new ListNode(num % 10);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            num = l1->val + carry;
            carry = num / 10;
            current->next = new ListNode(num % 10);
            current = current->next;
            l1 = l1->next;
        }

        while(l2)
        {
            num = l2->val + carry;
            carry = num / 10;
            current->next = new ListNode(num % 10);
            current = current->next;
            l2 = l2->next;
        }

        if(carry)
        {
            current->next = new ListNode(carry);
        }

        current = dummy->next;
        delete dummy;
        return current;
    }
};