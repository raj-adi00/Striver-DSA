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
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || head->next==nullptr)
        return nullptr;
        ListNode* slow=head,*fast=head;
        ListNode* parentSlow=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            parentSlow=slow;
            slow=slow->next;
        }
        parentSlow->next=slow->next;
        delete(slow);
        return head;
    }
     ListNode* deleteMiddle2(ListNode* head) {
        if(!head || head->next==nullptr)
        return nullptr;
        ListNode* slow=head,*fast=head;
        ListNode* parentSlow=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            if(fast && fast->next)
            slow=slow->next;
        }
        ListNode* mid=slow->next;
        slow->next=slow->next->next;
        delete(mid);
        return head;
    }
};