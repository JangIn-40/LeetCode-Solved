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
    void divide(vector<ListNode*>& arr, int lo, int hi)
    {
        if(lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            divide(arr, lo, mid);
            divide(arr, mid + 1, hi);

            Merge(arr, lo, mid, hi);
        }
    }

    void Merge(vector<ListNode*>& arr, int lo, int mid, int hi)
    {
        int i = lo, j = mid + 1;

        for(int k = lo; k <= hi; ++k)
        {
            temp[k] = arr[k];
        }

        for(int k = lo; k <= hi; ++k)
        {
            if(i > mid)
            {
                arr[k] = temp[j++];
            }
            else if(j > hi)
            {
                arr[k] = temp[i++];
            }
            else if(temp[j]->val < temp[i]->val)
            {
                arr[k] = temp[j++];
            }
            else
            {
                arr[k] = temp[i++];
            }
        }
    }

    ListNode* sortList(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }

        ListNode* current = head;
        vector<ListNode*> arr;
        while(current)
        {
            arr.emplace_back(current);
            current = current->next;
        }

        temp.resize(arr.size());
        divide(arr, 0, arr.size() - 1);

        for(int i = 0; i < arr.size() - 1; ++i)
        {
            arr[i]->next = arr[i + 1];
        }
        arr.back()->next = nullptr;

        return arr[0];
    }

private:
    vector<ListNode*> temp;
};