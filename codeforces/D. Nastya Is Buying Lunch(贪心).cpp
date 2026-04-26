//https://codeforces.com/contest/1136/problem/D

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=3e5+5;
vi p;
vector<pii> exg[MAXN];
int pos[MAXN];

void solve() 
{
    int n,m;
    cin>>n>>m;

    p.resize(n+1,0);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) pos[p[i]]=i;
    int pn=p[n];

    vector<vi> rev(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        rev[v].push_back(u);
    }

    vi cnt(n+1,0);
    vector<bool> used(n+1,false);
    int needSize=0;

    auto add_to_need=[&](int y)
    {
        used[y]=true;
        needSize++;
        for(int u:rev[y]) cnt[u]++;
    };

    add_to_need(pn);

    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        int u=p[i];
        if(cnt[u]==needSize) ans++;
        else add_to_need(u);
    }
    cout<<ans<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    while(t--) solve();
}