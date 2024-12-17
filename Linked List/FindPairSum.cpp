//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class Solution {
   public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node *curr = head;
        unordered_set<int> s;
        vector<pair<int, int>> res;
        while (curr) {
            int val = curr->data;
            int req = target - val;
            if (s.find(req) != s.end()) res.push_back({req, val});
            s.insert(val);
            curr = curr->next;
        }
        sort(res.begin(), res.end());
        return res;
    }

    vector<pair<int, int>> findPairsWithGivenSum2(Node *head, int target) {
        if (!head) return {};
        Node *first = head;
        Node *second = head;
        int req = target - first->data;
        while (second->next) {
            if (second->data >= req) break;
            second = second->next;
        }
        vector<pair<int, int>> res;
        if (req == second->data && first->data < second->data)
            res.push_back({first->data, req});
        while (first && first->data < second->data) {
            first = first->next;
            int req = target - first->data;
            while (second && first->data < second->data && second->data > req)
                second = second->prev;
            if (second->data == req && first->data < second->data)
                res.push_back({first->data, second->data});
        }
        return res;
    }

    vector<pair<int, int>> findPairsWithGivenSum3(Node *head, int target) {
        // code here
        if (!head) return {};
        Node *curr = head;
        Node *tail = head;
        while (tail->next) tail = tail->next;
        vector<pair<int, int>> res;
        while (curr && curr->data < tail->data) {
            int sum = curr->data + tail->data;
            if (sum == target) {
                res.push_back({curr->data, tail->data});
                curr = curr->next;
                tail = tail->prev;
            } else if (sum < target) {
                curr = curr->next;
            } else
                tail = tail->prev;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++) {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}

// } Driver Code Ends