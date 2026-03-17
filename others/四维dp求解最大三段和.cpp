//https://acm.hdu.edu.cn/contest/problem?cid=1212&pid=1007

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF=1e18;

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    //dp[i][j][k]表示前i个数最大子段和，j表示当前选了几个子段，k表示当前子段是否已经选了数，0表示没有选，1表示已经选
    vector<vector<vl>> dp(n+1, vector<vl>(4, vl(2, -INF)));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=3;j++)
        {
            dp[i][j][0]=max({dp[i][j][0],dp[i-1][j][0],dp[i-1][j][1]});
            if(j>0)
            {
                if(j!=2&&dp[i-1][j][1]!=-INF)
                {
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]+a[i-1]);
                }

                if(dp[i-1][j-1][0]!=-INF)
                {
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][0]+a[i-1]);
                }
            }
        }
    }
    cout<<max(dp[n][3][0],dp[n][3][1])<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) solve();
}
