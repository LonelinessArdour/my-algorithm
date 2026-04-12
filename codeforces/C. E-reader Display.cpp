//https://codeforces.com/problemset/problem/126/C

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve() 
{
    int n;
    cin>>n;
    vector<vi> a(n+1,vi(n+1,0));
    vi b(n+1,0),d(n+1,0);
    for(int i=1;i<=n;i++)
    {
        string row;
        cin>>row;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=row[j-1]-'0';
        }
    }

    int ans=0;
    //处理上三角，从上到下，从右到左
    for(int i=1;i<=n;i++)
    {
        int op=0;
        for(int j=n;j>i;j--)
        {
            if(b[j]^op!=a[i][j])
            {
                op^=1;
                ans++;
                b[j]^=1;

                d[i]^=1;
                d[j]^=1;
            }
        }
    }

    b.assign(n+1,0);
    //处理下三角，从下到上，从左往右
    for(int i=n;i>=1;i--)
    {
        int op=0;
        for(int j=1;j<i;j++)
        {
            if(b[j]^op!=a[i][j])
            {
                op^=1;
                ans++;
                b[j]^=1;

                d[i]^=1;
                d[j]^=1;
            }
        }
    }

    //处理主对角线
    for(int j=1;j<=n;j++)
    {
        if(d[j]!=a[j][j])
        {
            ans++;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}