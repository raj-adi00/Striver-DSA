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
    Node *next;
    Node(int data1, Node *next1 = nullptr) {
        data = data1;
        next = next1;
    }
};
Node *Array2LL(vector<int> &v, int n) {
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++) {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversal(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertHead(Node *head, int val) {
    Node *temp = new Node(val, head);
    return temp;
}

Node *insertTail(Node *head, int val) {
    Node *node = new Node(val);
    if (!head) return node;
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

Node *insertAtPosition(Node *head, int val, int k) {
    Node *node = new Node(val);
    if (k == 1) {
        node->next = head;
        return node;
    }
    if (!head) return node;
    Node *temp = head;
    int cnt = 0;
    while (temp) {
        cnt++;
        if (cnt == k - 1) {
            node->next = temp->next;
            temp->next = node;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertValueBeforeValue(Node* head,int val,int x) {
    if(!head)
    return nullptr;
    Node *node = new Node(val);
    if (x == head->data) {
        node->next = head;
        return node;
    }
    Node *temp = head;
    while (temp->next) {
        if (temp->next->data==x) {
            node->next = temp->next;
            temp->next = node;
        }
        temp = temp->next;
    }
    return head;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    Node *head = Array2LL(v, n);
    traversal(head);
    head = insertAtPosition(head, 10, 1);
    traversal(head);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
}