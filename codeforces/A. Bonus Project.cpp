//https://codeforces.com/problemset/problem/2038/A

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline ll vete(ll a, ll b, ll c) {
    return a-c*b;
}

void solve() 
{
    int n,k;
    cin>>n>>k;
    vl a(n),b(n);
    for(ll& v:a) cin>>v;
    for(ll& v:b) cin>>v;

    ll max_total=0;
    vl c_max(n);
    for(int i=0;i<n;i++)
    {
        c_max[i]=a[i]/b[i];
        max_total+=c_max[i];
    }
    if(max_total<k)
    {
        for(int i=0;i<n;i++)
        {
            cout<<0<<' ';
        }
        return;
    }

    vl suf(n+2,0);
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1]+c_max[i-1];
    }

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"suf"<<i<<":"<<suf[i]<<endl;
    // }

    ll remaining=k;
    vl ans(n+1,0);
    for(int i=1;i<=n;i++)
    {
        ll need=remaining-suf[i+1];
        if(need<0) need=0;
        ans[i]=need;
        remaining-=need;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}