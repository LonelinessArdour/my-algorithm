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
    ll n,l,r;
    cin>>n>>l>>r;
    vl a(n+1,0);
    for(ll& v:a) cin>>v;

    vl dp(n+1,LLONG_MIN);
    dp[0]=a[0];

    deque<pll> maxdq;
    for(int i=l;i<=n;i++)
    {
        int lj=i-r;
        int rj=i-l;
        while(!maxdq.empty()&&maxdq.back().first<dp[rj]) maxdq.pop_back();
        maxdq.push_back({dp[rj],rj});

        ll curr_max=maxdq.front().first;
        if(curr_max!=LLONG_MIN) dp[i]=a[i]+curr_max;

        while(!maxdq.empty()&&maxdq.front().second<=lj) maxdq.pop_front();
    }
    
    ll ans=LLONG_MIN;
    for(int i=n-r+1;i<=n;i++) ans=max(ans,dp[i]);
    if(ans==LLONG_MIN) ans=0;
    cout<<ans;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}