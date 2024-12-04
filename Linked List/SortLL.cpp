/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};
Node* sortList(Node* head) {
    // Write your code here.
    Node *zero = nullptr, *one = nullptr, *two = nullptr;
    Node *tempzero = nullptr, *tempone = nullptr, *temptwo = nullptr;
    Node* temp = head;
    while (temp) {
        if (temp->data == 0) {
            if (zero == nullptr) {
                zero = temp;
                tempzero = temp;
            } else {
                tempzero->next = temp;
                tempzero = tempzero->next;
            }
        } else if (temp->data == 1) {
            if (one == nullptr) {
                one = temp;
                tempone = temp;
            } else {
                tempone->next = temp;
                tempone = tempone->next;
            }
        } else {
            if (two == nullptr) {
                two = temp;
                temptwo = temp;
            } else {
                temptwo->next = temp;
                temptwo = temptwo->next;
            }
        }
        temp = temp->next;
    }
    if (temptwo) temptwo->next = nullptr;
    if (tempone) tempone->next = nullptr;
    if (tempzero) tempzero->next = nullptr;
    head = zero;
    if (!head) {
        head = one;
        if (!head)
            head = two;
        else
            tempone->next = two;
        return head;
    } else {
        tempzero->next = one;
        if (!one)
            tempzero->next = two;
        else
            tempone->next = two;
        return head;
    }
    return nullptr;
}