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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* rt=list1;
        a-=1;
        ListNode* nxt=NULL;
        while(b--)
        {
            rt=rt->next;
        }
        nxt=rt->next;
        rt=list1;
        while(a--)
        {
            list1=list1->next;
        }
        
        list1->next=list2;
        while(list2->next!=NULL)
        {
            list2=list2->next;
        }
        list2->next=nxt;
        return rt;
        
    }
};