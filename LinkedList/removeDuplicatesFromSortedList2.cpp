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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(0);
        unordered_map<int, int> m;
        ListNode *curr = head;
        while (curr)
        {
            m[curr->val]++;
            curr = curr->next;
        }
        curr = head;
        ListNode *curr1 = dummy;
        while (curr)
        {
            if (m[curr->val] == 1)
            {
                curr1->next = curr;
                curr1 = curr1->next;
            }
            curr = curr->next;
        }
        curr1->next = NULL;
        return dummy->next;
    }
};