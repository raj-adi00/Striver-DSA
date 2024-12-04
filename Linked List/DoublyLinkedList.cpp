#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const auto &x : v) out << x << ' ';
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x : v) in >> x;
    return in;
}
/*       <<<<<CODE HERE>>>>>      */
struct Node {
    int data;
    Node *next, *prev;
    Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};
Node *arra2LL(vector<int> &v, int n) {
    if (n == 0) return nullptr;
    Node *head = new Node(v[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++) {
        Node *temp = new Node(v[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}
void traverse(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *deleteHead(Node *head) {
    if (!head || head->next == nullptr) return nullptr;
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    head->prev = nullptr;
    free(temp);
    return head;
}
Node *deleteTail(Node *head) {
    if (!head || head->next == nullptr) return nullptr;
    Node *temp = head;
    while (temp->next->next) temp = temp->next;
    Node *nod = temp->next;
    nod->prev = nullptr;
    temp->next = nullptr;
    free(nod);
    return head;
}
Node *deleteKthElement(Node *head, int k) {
    if (!head) return nullptr;
    if (k == 1) {
        if (head->next == nullptr) {
            free(head);
            return nullptr;
        }
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    Node *frontNode = temp->next;
    if (frontNode == nullptr) {
        prevNode->next = nullptr;
        temp->prev = nullptr;
        free(temp);
        return head;
    }
    prevNode->next = frontNode;
    temp->prev = nullptr;
    temp->next = nullptr;
    frontNode->prev = prevNode;
    free(temp);
    return head;
}
void deletNode(Node *del) {
    Node *prev = del->prev;
    Node *front = del->next;
    if (front == nullptr) {
        prev->next = nullptr;
        del->prev = nullptr;
        free(del);
        return;
    }
    prev->next = front;
    del->next = del->prev = nullptr;
    front->prev = prev;
    free(del);
    return;
}
Node *insertHead(Node *head, int val) {
    Node *temp = new Node(val, head, nullptr);
    head->prev = temp;
    return temp;
}
Node *insertTail(Node *head, int val) {
    Node *temp = head;
    Node *newNode = new Node(val);
    if (!head) return newNode;
    while (temp->next) {
        temp = temp->next;
    }
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev) temp->prev->next = newNode;
    temp->prev = newNode;
    if (newNode->prev) return head;
    return newNode;
}
Node *inserKthElement(Node *head, int val, int k) {
    if (k == 1) return insertHead(head, val);
    if (!head) return nullptr;
    int curr = 0;
    Node *temp = head;
    while (temp) {
        curr++;
        if (curr == k) {
            if (temp->next == nullptr) return insertTail(head, val);
            Node *node = new Node(val, temp, temp->prev);
            temp->prev->next = node;
            temp->prev = node;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
void insertBeforeHead(Node *temp, int val) {
    Node *newNode = new Node(val, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void ReverseDLLNaive(Node *head) {
    stack<int> s;
    Node *temp = head;
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (!s.empty()) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
}

Node *revrseDLLOptimised(Node *head) {
    if (!head || head->next == nullptr) return head;
    Node *prev = nullptr;
    Node *current = head;
    while (current) {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    Node *head = arra2LL(v, n);
    traverse(head);
    head = revrseDLLOptimised(head);
    traverse(head);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
}