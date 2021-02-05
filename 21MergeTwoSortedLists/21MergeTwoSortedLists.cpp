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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1,*h2,*h,*p;
        h1=l1;
        h2=l2;
        if (l1==nullptr) return l2;
        else if (l2==nullptr) return l1;
        if (h1->val<h2->val)
        {
            p=h=h1;
            h1=h1->next;
        }
        else 
        {
            p=h=h2;
            h2=h2->next;
        }
        while(h1!=nullptr||h2!=nullptr)
        {
            
            if (h1==nullptr||(h2!=nullptr&&h1->val>h2->val))
            {
                p=p->next=h2;
                h2=h2->next; 
            }
            else if (h2==nullptr||(h1!=nullptr&&h1->val<=h2->val))
            {
                p=p->next=h1;
                h1=h1->next; 
            }
        }
        return h;
    }
};
