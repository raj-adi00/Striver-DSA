#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(0), cin.tie(0);
        int n=v.size();int m=v[0].size();
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        set<pair<int,pair<int,int>>>s;
        s.insert({0,{0,0}});
        effort[0][0]=0;
        vector<int> row={0,0,-1,1},col={-1,1,0,0};
        while(!s.empty()){
           auto it=(*s.begin());
           s.erase(s.begin());
           auto effortTillNow=it.first;
           auto x=it.second.first,y=it.second.second;
           if(x==n-1 && y==m-1)
           return effortTillNow;
           for(int i=0;i<4;i++){
            int nx=x+row[i];
            int ny=y+col[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                int adjEffort=max(effortTillNow,abs(v[nx][ny]-v[x][y]));
                if(adjEffort<effort[nx][ny]){
                    if(effort[nx][ny]!=1e9){
                        s.erase({effort[nx][ny],{nx,ny}});
                    }
                    s.insert({adjEffort,{nx,ny}});
                    effort[nx][ny]=adjEffort;
                }
            }
           }
        }
        return effort[n-1][m-1];
    }
};