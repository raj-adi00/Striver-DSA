#include <bits/stdc++.h>
using namespace std;
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

class Node {
   public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};
Node *addTwoNumbers(Node *head1, Node *head2) {
    // Write your code here.
    int carry = 0;
    Node *head = nullptr, *tail = nullptr;
    while (head1 || head2 || carry) {
        int sum = carry;
        if (head1) {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2) {
            sum += head2->data;
            head2 = head2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        Node *newNode = new Node(sum);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}