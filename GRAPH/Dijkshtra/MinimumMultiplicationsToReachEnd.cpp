#include <bits/stdc++.h>
using namespace std;


#define mod 100000
//TC without priority queue: O(n*100000)  hypothetical scenerio
class Solution {
  public:
    int minimumMultiplications(vector<int>& v, int start, int end) {
        // code here
        int n=v.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(1e5,1e9);
        pq.push({0,start});
        dist[start]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            auto dis=it.first;
            auto node=it.second;
            for(int i=0;i<n;i++){
                int adjNode=(node*v[i])%mod;
                if(dis+1<dist[adjNode]){
                    dist[adjNode]=dis+1;
                    if(adjNode==end)
                    return dist[adjNode];
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        if(dist[end]==1e9)
        return -1;
        else
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

