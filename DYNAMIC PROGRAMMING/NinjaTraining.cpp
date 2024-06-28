#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define mod 1000000007
/*       <<<<<CODE HERE>>>>>      */
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[i].push_back(x);
        v[i].push_back(y);
        v[i].push_back(z);
    }
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i].push_back(-1);
        dp[i].push_back(-1);
        dp[i].push_back(-1);
    }

    function<int(int, int)> DP = [&](int i, int state) -> int
    {
        if (i >= n)
            return 0;
        if (dp[i][state] != -1)
            return dp[i][state];
        int ans = INT_MIN;
        for (int j = 0; j < 3; j++)
        {
            if (j != state) 
                ans = max(ans, DP(i + 1, j) + v[i][j]);
        }
        return dp[i][state] = ans;
    };
    cout << max({DP(0, 0), DP(0, 1), DP(0, 2)}) << endl;
  

  //Tabulation

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
    }
    for (int j = 0; j < 3; ++j)
    {
        dp[0][j] = v[0][j];
    }

    // Fill the dp array
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    // Get the maximum points from the last day
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]})<<endl;





    for (int i = 0; i < n; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
        dp[i].push_back(-1);
    }
    function<int(int,int)>f=[&](int last,int day)->int{
        if(day==0)
        {
            int maxi=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                maxi=max(maxi,v[0][task]);
            }
            return maxi;
        }
        if(dp[day][last]!=-1)
        return dp[day][last];
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(last!=task)
            maxi=max(maxi,f(task,day-1)+v[day][task]);
        }
        return dp[day][last]=maxi;
    };
      cout<<f(3,n-1)<<endl;   //TC:O(N*4)*3  SC:O(N)+O(N*4)




vector<vector<int>> dp1(n,vector<int>(4,0));
    dp1[0][0]=max(v[0][1],v[0][2]);
    dp1[0][1]=max(v[0][0],v[0][2]);
    dp1[0][2]=max(v[0][1],v[0][0]);
    dp1[0][3]=max({v[0][1],v[0][2],v[0][0]});

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp1[day][last]=0;
            int maxi=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=v[day][task]+dp[day-1][task];
                    dp1[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
cout<<dp1[n-1][3]<<endl;     //TC:O(N*4*3)  SC:O(N*4)

//Space optimisation
vector<int> arr(4,0);
    arr[0]=max(v[0][1],v[0][2]);
    arr[1]=max(v[0][0],v[0][2]);
    arr[2]=max(v[0][1],v[0][0]);
    arr[3]=max({v[0][1],v[0][2],v[0][0]});
    for(int day=1;day<n;day++)
    {
          vector<int> temp(4,0);
        for(int last=0;last<4;last++)
        {
            int maxi=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=v[day][task]+arr[task];
                   maxi=max(maxi,point);
                }
            }
            temp[last]=maxi;
        }
        for(int i=0;i<4;i++)
        arr[i]=temp[i];
    }
    cout<<arr[3]<<endl;  //SC: O(1)
}