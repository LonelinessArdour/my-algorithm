//https://acm.hdu.edu.cn/contest/submit?cid=1199&pid=1001

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;

void solve() 
{
    int n; ll m;
    cin>>n>>m;
    vl a(n),b(n+1);
    for(auto &v:a) cin>>v;
    for(auto &v:b) cin>>v;

    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    vector<i128> prev(n+1,0), suf(n+2,0);

    for(int i=1;i<=n;i++) prev[i]=prev[i-1]+(i128)a[i-1]*b[i-1];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(i128)a[i-1]*b[i];
    if(prev[n]>=m)
    {
        cout<<0<<endl;
        return;
    }

    ll ans=1e18;
    for(int k=0;k<=n;k++)
    {
        i128 need=(i128)m-suf[k+1]-prev[k];
        if(need<=0)
        {
            ans=0;
            break;
        }
        i128 v=(need+b[k]-1)/b[k];
        if(v<ans) ans=(ll)v;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}