/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode* curr=head;
      map<ListNode*,int> m;
      while(curr){
        if(m[curr]){
        return curr;
        }
        m[curr]=1;
        curr=curr->next;
      }  
      return nullptr;
    }

     ListNode *detectCycle2(ListNode *head) {
        if(!head || (!(head->next)))return nullptr;
        if(head->next==head)return head;
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            break;
        }
        if(fast==nullptr || (fast->next)==nullptr)
        return nullptr;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};