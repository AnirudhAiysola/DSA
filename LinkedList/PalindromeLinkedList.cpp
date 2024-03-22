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
private:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        // find middle of the Linked List
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse after the middle
        ListNode *newHead = reverseList(slow->next);
        ListNode *curr1 = head;
        ListNode *curr2 = newHead;
        while (curr2)
        {
            if (curr1->val != curr2->val)
                return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};