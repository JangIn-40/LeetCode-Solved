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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
        {
            return list2;
        }
        else if(!list2)
        {
            return list1;
        }

        
        ListNode dummy(-1);
        ListNode* dPtr = &dummy;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                dPtr->next = list1;
                list1 = list1->next;
            }
            else
            {
                dPtr->next = list2;
                list2 = list2->next;
            }
            dPtr = dPtr->next;
        }

        if(list1)
        {
            dPtr->next = list1;
        }
        else
        {
            dPtr->next = list2;
        }

        return dummy.next;
    }
};