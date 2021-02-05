//使用priority_queue或者分治法(类似于mergesort)可以更快
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res,*p;
        set<int> s;
        p=res=new ListNode(-1);
        set<int>::iterator iter;
        for (int i=0;i<lists.size();++i)
        {
            if (lists[i]!=nullptr)
                s.insert(i);
        }
        while(s.size()>0)
        {
            int loc=-1;
            int min=10001;
            set<int>::iterator idx=s.end();
            for (iter=s.begin();iter!=s.end();++iter)
            {
                if (lists[*iter]->val<min)
                {
                    min=lists[*iter]->val;
                    idx=iter;
                }
            }
            p=p->next=lists[*idx];
            lists[*idx]=lists[*idx]->next;
            if (lists[*idx]==nullptr)
                s.erase(idx);
        }
        return res->next;
    }
};
