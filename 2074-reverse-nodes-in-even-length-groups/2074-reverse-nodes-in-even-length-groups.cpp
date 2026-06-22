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
void reverse(ListNode* head,int times){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(times--){
        ListNode* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return;
}
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* left=head;
        ListNode* right;
        ListNode* res=NULL;
        ListNode* prevleft=NULL;
        int size=1;
        while(left){
           ListNode* right=left;
           int cnt=1;
           for(int i=0;i<size-1;i++){
                if(right->next==NULL){
                    break;
                }
                right=right->next;
                cnt++;
            }
            ListNode* nextleft=right->next;
            if(cnt%2==0){
                reverse(left,cnt);
                if(prevleft){
                    prevleft->next=right;
                }
                prevleft=left;
            }else{
                if(prevleft){
                    prevleft->next=left;
                }
                if(!res){
                    res=left;
                }
                prevleft=right;
            }
            left=nextleft;
            size++;
        }
        return res;
    }
};