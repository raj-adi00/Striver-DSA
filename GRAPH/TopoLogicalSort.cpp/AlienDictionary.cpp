//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  //There can be two cases where Dictionary is invalid: 1. If shorter length fall after larger legth though they have no difference till shorter string length. 2.If there is cycle means a->b->c->a eg: adi,bdi,cdi,appu
    string findOrder(string v[], int n, int k) {
        // code here
        vector<vector<int>> adj(k);
        queue<int> q;vector<int> indegree(k,0);
        for(int i=0;i<n-1;i++){
            string a=v[i];
            string b=v[i+1];
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    indegree[b[j]-'a']++;
                    break;
                }
            }
        }
        for(int i=0;i<k;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        string s="";
        while(!q.empty()){
            int x=q.front();
            s+=(char)(x+'a');
            q.pop();
            for(auto val:adj[x]){
                indegree[val]--;
                if(indegree[val]==0)
                q.push(val);
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends