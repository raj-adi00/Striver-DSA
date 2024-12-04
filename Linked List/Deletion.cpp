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

Node *deleteHead(Node *head) {
    if (!head) return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node *deleteTail(Node *head) {
    if (!head || head->next == NULL) return nullptr;
    Node *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}


Node *deletePosition(Node *head, int k) {
    if (!head || k <= 0) return nullptr;
    Node *temp = head;
    if (k == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 1;
    Node *prev = nullptr;
    while (temp) {
        if (cnt == k) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}


Node *RemovElement(Node *head, int k) {
    if (!head) return nullptr;
    Node *temp = head;
    if (head->data==k) {
        head = head->next;
        free(temp);
        return head;
    }
    Node *prev = nullptr;
    while (temp) {
        if (temp->data == k) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
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


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    Node *head = Array2LL(v, n);
    traversal(head);
    head = RemovElement(head, 5);
    traversal(head);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
}