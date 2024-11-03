#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int v=mat.size();

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                 if(mat[i][j]==-1)
                 mat[i][j]=1e8;
                 if(i==j)
                 mat[i][j]=0;
            }
        }

        //ALGORITHM
        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        
        //DETECT NEGATIVE CYCLE
        for(int i=0;i<v;i++){
           if(mat[i][i]<0){
            //Negative cycle detected
           }
        }
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++)
            {
                if(mat[i][j]==1e8)
                mat[i][j]=-1;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends