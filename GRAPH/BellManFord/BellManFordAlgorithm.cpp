#include <cstdio> 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
//TC: V*E
class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        // Code here
       vector<int> dist(v,1e8);
       dist[src]=0;
       for(int i=1;i<v;i++){
           for(auto vec:edges){
               if(dist[vec[0]]==1e8)continue;
               if(dist[vec[0]]+vec[2]<dist[vec[1]])
               dist[vec[1]]=dist[vec[0]]+vec[2];
           }
       }
       for(auto vec:edges){
           if(dist[vec[0]]==1e8)
           continue;
           if(dist[vec[0]]+vec[2]<dist[vec[1]]){
               vector<int> res(1,-1);
               return res;
           }
       }
       return dist;
    }
};



int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";

        cout << "~" << endl;
    }
    return 0;
}

