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
        int cnt=0;
        int n1,n2;
        ListNode *p,*q,*r,*start;
        p=l1;
        q=l2;
        start=r=new ListNode;
        while (p!=nullptr || q!=nullptr ||cnt!=0)
        {
            r=r->next=new ListNode;
            int s;
            if (p==nullptr && q==nullptr)
                s=cnt;
            else if (p==nullptr)
                s=q->val+cnt;
            else if (q==nullptr)
                s=p->val+cnt;
            else
                s=p->val+q->val+cnt;
            r->val=s%10;
            cnt=s/10;
            if (p!=nullptr)
                p=p->next;
            if (q!=nullptr)
                q=q->next;
        }
        r=nullptr;

        return start->next;

    }
};
