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
    int n,s;
    cin>>n>>s;

    vector<bool> dp(s+1,false);
    //关键错误修正
    dp[0]=true;
    while(n--)
    {
        int a;
        cin>>a;
        for(int i=s;i>=a;i--) dp[i]=dp[i]||dp[i-a];
    }
    if(dp[s]) cout<<"YES";
    else cout<<"NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}