//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int key) {
        // Write your code here
        Node* head=(*head_ref);
        if(!head)
        return;
        while(head && head->data==key){
            Node* temp=head;
            head=head->next;
            temp->next=nullptr;
            delete(temp);
            head->prev=nullptr;
        }
        if(!head){
            *head_ref=nullptr;
            return;
        }
        *head_ref=head;
        Node* curr=head;
        while(curr && curr->next){
            Node* temp=curr->next;
            while(temp && temp->data==key){
                curr->next=temp->next;
                if(temp->next){
                    temp->next->prev=curr;
                }
                temp->next=nullptr;
                temp->prev=nullptr;
                delete(temp);
                temp=curr->next;
            }
            curr=temp;
        }
    }

    void deleteAllOccurOfX2(struct Node** head_ref, int x) {
        // Write your code here
        Node* head=*head_ref;
        if(!head)
        return;
        Node* previous=nullptr;
        Node* ahead=head->next;
        Node* curr=head;
        while(curr){
            if(curr->data==x){
                if(previous)
                previous->next=ahead;
                if(ahead)
                ahead->prev=previous;
                if(curr==head)
                head=ahead;
                curr->next=nullptr;
                curr->prev=nullptr;
                delete(curr);
            }
           curr=ahead;
           if(ahead)
                ahead=ahead->next;
                if(curr)
                previous=curr->prev;
        }
        *head_ref=head;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends