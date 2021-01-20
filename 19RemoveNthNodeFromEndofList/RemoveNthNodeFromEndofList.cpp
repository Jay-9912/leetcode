class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        ListNode* loc[31];
        int i=0;
        while (p!=nullptr)
        {
            i+=1;
            loc[i]=p;
            p=p->next;
        }
        if (n==i)
        {
            p=head;
            head=head->next;
            delete p;
        }
        else
        {
            loc[i-n]->next=loc[i-n+1]->next;
            delete loc[i-n+1];
        }
        return head;
    }
};
