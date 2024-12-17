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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head,*slow=head;
        while(fast){
            fast=fast->next;
            if(fast)
            fast=fast->next;
            slow=slow->next;
             if(fast==slow && fast)
            return true;
        }
        return false;
    }

     bool hasCycle2(ListNode *head) {
        map<ListNode*,int> m;
        ListNode* curr=head;
        while(curr){
            if(m[curr])
            return true;
            m[curr]=1;
            curr=curr->next;
        }
        return false;
    }
};