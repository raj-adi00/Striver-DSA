#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
//TC:O(Edges)
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n=3, src=0, dst=2, k=1;
    vector<vector<int>> v={{0,1,100},{1,2,100},{0,2,500}};
    vector<vector<pair<int, int>>> adj(n);
    for (auto pr : v)
    {
        adj[pr[0]].push_back({pr[1], pr[2]});
    }
    int ans=1e9;
    //stops,node,price
    vector<int> dist(n,1e9);
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    dist[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int node=it.second.first;
        int price=it.second.second;
        for(auto val:adj[node]){
            auto edgeW=val.second;
            auto adjNode=val.first;
            if(stops<=k && edgeW+price<dist[adjNode]){
                if(adjNode!=dst)
                q.push({stops+1,{adjNode,edgeW+price}});
                dist[adjNode]=edgeW+price;
            }
        }
    }
    if(dist[dst]==1e9)
    return -1;
    else
    return dist[dst];
}