leetcode 83
struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode *node;
    node prev=NULL;
    node curr=head;
    while(curr){
        if(prev && prev->val==curr->val){
            node temp=curr;
            prev->next=temp->next;
            curr=prev->next;
        }else{
            node temp=curr;
            curr=curr->next;
            prev=temp;
        }
    }
    return head;
}

leetcode 141
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    typedef struct ListNode * node;
    if(!head){
        return false;
    }
    if(head->next==head){
        return true;
    }else if(head->next==NULL){
        return false;
    }
    node fast=head;
    node slow=head;
    while(fast){
        if(!fast->next){
            return false;
        }
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

leetcode 234
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode *node;
node reverse(node head){
    if(head==NULL || head->next==NULL){
        return head;
    } 
    node prev=NULL;
    node curr=head;
    while(curr){
    node temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    int arr[100000];
    int size=0;
    node temp=head;
    while(temp){
        arr[size]=temp->val;
        temp=temp->next;
        size++;
    }
    node rev=reverse(head);
    for(int i=0;i<size;i++){
        if(!(arr[i]==rev->val)){
            return false;
        }
        rev=rev->next;
    }
    return true;
}
