#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string a, string b, vector<string> &v)
    {
        ios_base::sync_with_stdio(0), cin.tie(0);
        v.push_back(a);
        int n = v.size();
        int target = -1;
        vector<vector<int>> adj(n, vector<int>());

        function<bool(string, string)> f = [&](string x, string y) -> bool
        {
            int cnt = 0;
            for (int i = 0; i < x.length(); i++)
            {
                if (x[i] != y[i])
                    cnt++;
                if (cnt > 1)
                    return false;
            }
            return cnt == 1;
        };
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (f(v[i], v[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if (v[i] == b)
                target = i;
            if (v[i] == a)
                start = i;
        }
        vector<vector<string>> res;
        if (target == -1)
            return res;
        vector<vector<int>> parents(n, vector<int>());
        vector<string> temp;
        queue<pair<int, int>> q;
        q.push({start, 1});
        vector<int> vis(n, INT_MAX);
        vis[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int move = q.front().second;
            q.pop();
            for (auto val : adj[node])
            {
                if (vis[val] > move + 1)
                {
                    parents[val] = {node};
                    vis[val] = move + 1;
                    q.push({val, move + 1});
                }
                else if (vis[val] == move + 1)
                {
                    parents[val].push_back(node);
                }
            }
        }
        vector<vector<string>> o;
        function<void(int)> Backtraking = [&](int node) -> void
        {
            temp.push_back(v[node]);
            if (start == node)
            {
                vector<string> o = temp;
                reverse(o.begin(), o.end());
                res.push_back(o);
            }
            for (auto parent : parents[node])
            {
                Backtraking(parent);
            }
            temp.pop_back();
        };
        if (vis[target] != INT_MAX)
        {
            Backtraking(target);
        }
        return res;
    }

    vector<vector<string>> f(string a, string b, vector<string> &v){
    unordered_set<string> s(v.begin(),v.end());
    queue<vector<string>> q;
    vector<string> usedOnLevel;
    q.push({a});
    s.erase(a);
    vector<vector<string>> ans;
    usedOnLevel.push_back(a);
    int level=0;
    while(!q.empty()){
     auto vec=q.front();
     q.pop();
     if(vec.size()>level){
        level++;
        for(auto val:usedOnLevel)
        s.erase(val);
        usedOnLevel.clear();
     }
     auto word=vec.back();
     if(word==b){
        if(ans.size()==0)
        ans.push_back(vec);
        else if(ans[0].size()==vec.size())
        ans.push_back(vec);
     }else{
       for(int i=0;i<word.size();i++){
        char original =word[i];
        for(int j=97;j<=122;j++){
            word[i]=(char)j;
            if(s.find(word)!=s.end()){
                vec.push_back(word);
                q.push(vec);
                vec.pop_back();
                usedOnLevel.push_back(word);
            }
        }
        word[i]=original;
       }
     }
    }
    return ans;
}
   
    
     vector<vector<string>> fun(string a,string b,vector<string> &v){
        unordered_set<string> s(v.begin(),v.end());
        queue<string> q;
        q.push(a);
        map<string,int> m;
        m[a]=1;
        // cout<<1<<endl;
        s.erase(a);
        while (!q.empty())
        {
            auto x=q.front();q.pop();
            for(int i=0;i<x.length();i++){
                string w=x;
                for(char j='a';j<='z';j++){
                    x[i]=j;
                    if(s.find(x)!=s.end()){
                        m[x]=m[w]+1;
                        s.erase(x);
                        q.push(x);
                    }
                }
                x=w;
            }
        }
        // for(auto pr:m)
        // cout<<pr.first<<" "<<pr.second<<endl;
        vector<vector<string>> res;
        if(m.find(b)==m.end())
        return res;
        vector<string> temp;
        for(auto val:v)
        s.insert(val);
        function<void(string)>backtrack=[&](string y)->void{
        if(y==a){
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
             reverse(temp.begin(),temp.end());
        }else{
           
           for(int i=0;i<y.length();i++){
            string w=y;
            for(char j='a';j<='z';j++){    
                y[i]=j;
                if(m.find(w)!=m.end() && m[y]==m[w]-1){
                    temp.push_back(y);
                   backtrack(y);
                    temp.pop_back();
                }
            }
            y=w;
           }
        }
        };
        temp.push_back(b);
        backtrack(b);
        return res;
     }


//     vector<vector<string>> fun(string a, string b, vector<string> &v) {
//     unordered_set<string> s(v.begin(), v.end());
//     queue<string> q;
//     q.push(a);
//     map<string, int> m;  
//     m[a] = 1;           
//     s.erase(a);         

//     // BFS to find the shortest transformation sequence
//     while (!q.empty()) {
//         auto x = q.front(); q.pop();
//         for (int i = 0; i < x.length(); i++) {
//             string w = x;
//             for (char j = 'a'; j <= 'z'; j++) {
//                 w[i] = j; 
//                 if (s.find(w) != s.end()) {
//                     m[w] = m[x] + 1; 
//                     s.erase(w);       
//                     q.push(w);        
//                 }
//             }
//         }
//     }

//     vector<vector<string>> res;
//     if (m.find(b) == m.end())
//         return res;  

//     vector<string> temp;
//     function<void(string)> backtrack = [&](string y) -> void {
//         if (y == a) {
//             temp.push_back(y);  
//             reverse(temp.begin(), temp.end());  
//             res.push_back(temp); 
//             reverse(temp.begin(), temp.end());  
//             temp.pop_back();  
//             return;
//         }

//         temp.push_back(y);  // Add the current word to the path
//         for (int i = 0; i < y.length(); i++) {
//             string w = y;
//             for (char j = 'a'; j <= 'z'; j++) {
//                 w[i] = j;
//                 if (m.find(w) != m.end() && m[w] == m[y] - 1) {
//                     backtrack(w);  
//                 }
//             }
//         }
//         temp.pop_back();  
//     };

//     backtrack(b);  
//     return res;
// }

     void solve() {
        string start = "hit";
        string end = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

        vector<vector<string>> result = fun(start, end, wordList);

        cout << "All possible paths from " << start << " to " << end << ":\n";
        for (const auto& path : result) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << "\n";
        }
    }
}; 
int main() {
    Solution sol;
    sol.solve();
    return 0;
}