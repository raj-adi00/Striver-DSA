#include <bits/stdc++.h>
using namespace std;
//  PATTERN 1
// O(N*N)
/*
 void nForest(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<"*"<<" ";
        cout<<endl;
    }
}
*/

//    PATTERN 2
// O(N*N)
/*
void nForest(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<"* ";
        cout<<endl;
    }
}
*/

//   PATTERN 3
//  O(N*N)
/*
void nTriangle(int n)
{
    // Write your code here
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}
*/

//   PATTERN 4
//  O(N*N)
/*
void triangle(int n) {
    // Write your code here
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<i<<" ";
        cout<<endl;
    }
}
*/

//   PATTERN 5
//  O(N*N)
/*
void seeding(int n) {
    // Write your code here.
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<"* ";
        cout<<endl;
    }
}
*/

//   PATTERN 6
//  O(N*N)
/*
void nNumberTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        cout<<j<<" ";
        cout<<endl;
    }
}
*/

//   PATTERN 7
//  O(N*N)
/*
void nStarTriangle(int n) {
    // Write your code here.
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n+i;j++)
        {
            if(j<=n-i-1)
            cout<<" ";
            else
            cout<<"*";
        }
        cout<<endl;
    }
}
*/
/*
void pattern7(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n-i-1;j++)
        cout<<" ";
        for(int j=1;j<=2*i+1;j++)
        cout<<"*";
        cout<<endl;
    }
}
*/

//   PATTERN 8
/*
void nStarTriangle(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * (n - i) - 1; j++)
            cout << "*";
        cout << endl;
    }
}
*/

//   PATTERN 9
/*
void nStarDiamond(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 1; j--)
            cout << " ";
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "*";
        cout << endl;
    }
}
*/

//   PATTERN 10
/*
void nStarTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        cout<<"*";
        cout<<endl;
    }
}
*/
/*
void nStarTriangle(int n) {
    // Write your code here.
  for(int i=1;i<=2*n-1;i++)
  {
      if(i<=n)
      {
         for(int j=1;j<=i;j++)
         cout<<"*";
      }
      else{
          for(int j=1;j<=n-(i-n);j++)
          cout<<"*";
      }
      cout<<endl;
  }
}
*/

//   PATTERN 11
/*
void nBinaryTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        int p;
        if(i%2==0)
        p=0;
        else
        p=1;
        for(int j=1;j<=i;j++)
        {
            cout<<p<<" ";
            p=1-p;
        }
        cout<<endl;
    }
}
*/

//   PATTERN 12
void numberCrown(int n)
{
    // Write your code here.
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= i; j++)
            cout << j;
        int start = j - 1;
        /*
        // Approah 1
        while (j <= n)
        {
            cout << " ";
            j++;
        }
        j = start + 1;
        while (j <= n)
        {
            cout << " ";
            j++;
        }
        */
        //    Approach 2
        j = 1;
        while (j <= 2 * (n - i))
        {
            cout << " ";
            j++;
        }
        while (start >= 1)
        {
            cout << start;
            start--;
        }
        cout << endl;
    }
}

//   PATTERN 13
/*
void nNumberTriangle(int n) {
    // Write your code here.
    int print=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<print++<<" ";
        cout<<endl;
    }
}
*/

//   PATTERN 14
/*
void nLetterTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
          char ch='A';
        for(int j=1;j<=i;j++)
        {
            cout<<ch++<<" ";
        }
        cout<<endl;
    }
}
*/
/*
void nLetterTriangle(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
         for(char ch='A';ch<='A'+i-1;ch++)
         cout<<ch<<" ";
         cout<<endl;
    }
}
*/

//   PATTERN 15
/*
void nLetterTriangle(int n) {
    // Write your code here.
    for(int i=n;i>=1;i--)
    {
        for(char ch='A';ch<='A'+i-1;ch++)
        cout<<ch<<" ";
        cout<<endl;
    }
}
*/
//   PATTERN 16
/*
void alphaRamp(int n) {
    // Write your code here.
    for(char ch='A';ch<'A'+n;ch++)
    {
        for(char c='A';c<=ch;c++)
        cout<<ch<<" ";
        cout<<endl;
    }
}
*/

//   PATTERN 17
/*
void alphaHill(int n)
{
    // Write your code here.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        char ch = 'A';
        for (ch = 'A'; ch <= 'A' + i - 1; ch++)
            cout << ch;
        ch -= 2;
        while (ch >= 'A')
        {
            cout << ch;
            ch--;
        }
        cout << endl;
    }
}
*/
/*
void alphaHill(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i - 1; j++)
            cout << " ";
        char ch = 'A';
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            if (j < i + 1)
                cout << ch++;
            else if (j == i + 1)
                cout << ch;
            else
                cout << --ch;
        }
        cout << endl;
    }
}
*/

//   PATTERN 18
/*
void alphaTriangle(int n) {
    // Write your code here.
    for(int i=n-1;i>=0;i--)
    {
        char ch='A'+n-1;
        int j=i;
        while(j<=n-1)
        {
            cout<<ch<<" ";
            j++;
            ch--;
        }
        cout<<endl;
    }
}
*/

//   PATTERN 19
/*
void symmetry(int n)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= n)
        {
            for (int j = 1; j <= n - i + 1; j++)
                cout << "*";
            for (int j = 1; j <= 2 * (i - 1); j++)
                cout << " ";
            for (int j = 1; j <= n - i + 1; j++)
                cout << "*";
        }
        else
        {
            for (int  j = n + 1; j <= i; j++)
                cout << "*";
            for (int j = 1; j <= 2 * (2 * n - i); j++)
            {
                cout << " ";
            }
            for (int j = n + 1; j <= i; j++)
                cout << "*";
        }
        cout << endl;
    }
}
*/

//   PATTERN 20
/*
void symmetry(int n) {
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=1;j<=2*(n-i);j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<"*";
        for(int j=2*n;j>=2*i;j--)
        cout<<" ";
         for(int j=1;j<=i;j++)
        cout<<"*";
        cout<<endl;
    }
}
*/
/*
void pattern20(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars=i;
        if(i>n)
        stars=2*n-i;
        for (int j = 1; j <= stars; j++)
            cout << "*";
        for (int j = 1; j <= space; j++)
            cout << " ";
        if (i < n)
            space -= 2;
        else
            space += 2;
        for (int j = 1; j <= stars; j++)
            cout << "*";
            cout<<endl;
    }
}
*/

//   PATTERN 21
/*
void pattern21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if(i==1||i==n)
        {
            for(int j=1;j<=n;j++)
            cout<<"* ";
        }
        else{
            for(int j=1;j<=n;j++)
            {
                if(j==1||j==n)
                cout<<"* ";
                else
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
*/
//   PATTERN 22
void getNumberPattern(int n)
{
    // Write your code here.
    int repeated = 2 * n - 1;
    int seq = 0;
    int p=n;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int start = n;
        for (int j = 0; j < seq; j++)
            cout << start--;
        for (int j = 1; j <= repeated; j++)
            cout << p;
            start=p+1;
            for(int j=repeated+seq+1;j<=2*n-1;j++)
            cout<<start++;
        if (i < n-1)
        {
            p-=1;
            seq += 1;
            repeated -= 2;
        }
        else
        {
            if(i==n-1)
            repeated=1;
            p+=1;
            seq -= 1;
            repeated += 2;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    getNumberPattern(n);
}