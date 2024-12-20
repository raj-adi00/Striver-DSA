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
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution2 {
    ListNode* reverse(ListNode* head) {
        if (!head->next) return head;
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
    ListNode* getKthNode(ListNode* head, int k) {
        for (int i = 1; i < k; i++) {
            if (!head) return nullptr;
            head = head->next;
        }
        return head;
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* KthNode = head;
        ListNode* prevConnect = head;
        ListNode* nextConnect = head;
        while (temp) {
            KthNode = getKthNode(temp, k);
            if (!KthNode) {
                prevConnect->next = temp;
                break;
            }
            nextConnect = KthNode->next;
            KthNode->next = nullptr;
            reverse(temp);
            if (temp == head)
                head = KthNode;
            else {
                prevConnect->next = KthNode;
                prevConnect = temp;
            }
            temp = nextConnect;
        }
        return head;
    }
};

class Solution {
    ListNode* reverse(ListNode* head) {
        if (!head->next) return head;
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *temp = head;
        ListNode* prevConnect = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        ListNode* headNode = temp;
        ListNode* NextConnect = temp->next;
        temp->next = nullptr;
        reverse(curr);
        curr = NextConnect;
        while (curr && temp) {
            temp = curr;
            for (int i = 1; i < k && temp; i++) temp = temp->next;
            if (!temp) {
                prevConnect->next = curr;
                break;
            }
            NextConnect = temp->next;
            temp->next = nullptr;
            reverse(curr);
            prevConnect->next = temp;
            prevConnect = curr;
            curr = NextConnect;
        }
        return headNode;
    }
};