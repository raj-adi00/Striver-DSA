#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>adj(n);
        vector<int> outdegree(n,0),vis(n,0);
        for(int i=0;i<n;i++){
            for(auto val:v[i]){
               adj[val].push_back(i);
               outdegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
         {
            if(outdegree[i]==0)
            q.push(i);
         }
         vector<int> res;
        while(!q.empty()){
            int x=q.front();res.push_back(x);
            q.pop();
            for(auto val:adj[x]){
                outdegree[val]--;
                if(outdegree [val]==0)
                q.push(val);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> adj={{1,2},{2,3},{5},{0},{5},{},{}};
    for(auto val:obj.eventualSafeNodes(adj))
    cout<<val<<" ";
}