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
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        ListNode *slow = head;
        ListNode *fast = head;
        // find middle of LL
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second = slow->next;
        slow->next = NULL;
        // reverse the half
        ListNode *rev = reverseList(second);
        ListNode *curr1 = head;
        ListNode *curr2 = rev;

        while (curr2)
        {
            ListNode *currOneNext = curr1->next;
            ListNode *currTwoNext = curr2->next;
            curr1->next = curr2;
            curr2->next = currOneNext;
            curr1 = currOneNext;
            curr2 = currTwoNext;
        }
        return;
    }
};