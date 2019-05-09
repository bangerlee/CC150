/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        ListNode* t=head;
        ListNode* prev=NULL;
        int i=1;
        while(i++!=n&&p!=NULL) p=p->next;
        while(p->next!=NULL){
            prev=t;
            t=t->next;
            p=p->next;
        }
        if(prev==NULL) return t->next;
        prev->next=t->next;
        return head;
    }
};
