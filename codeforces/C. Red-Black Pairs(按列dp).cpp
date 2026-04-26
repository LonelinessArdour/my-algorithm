//https://codeforces.com/contest/2225/problem/C
/*
从右往左按列dp
*/

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
    string s1,s2;
    cin>>s1>>s2;
    s1=' '+s1;
    s2=' '+s2;

    vi dp(n+2,0);
    if(s1[n]!=s2[n]) dp[n]=1;
    for(int col=n-1;col>=1;col--)
    {
        int cost1=(s1[col]!=s2[col]);
        int cost2=(s1[col]!=s1[col+1])+(s2[col]!=s2[col+1]);
        dp[col]=min(dp[col+1]+cost1,dp[col+2]+cost2);
    }
    cout<<dp[1]<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
}