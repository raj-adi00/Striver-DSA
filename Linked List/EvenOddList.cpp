/****************************************************************
Following is the Linked list node structure already written

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};
Node* oddEvenList2(Node* head) {
    // Write your code here.
    if (!head || head->next == nullptr) return head;
    Node* odd=head,*even=head->next,*evenHead=odd->next;
    while(even && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}