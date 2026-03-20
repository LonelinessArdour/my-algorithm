//https://codeforces.com/contest/2204/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=2e5+5;
vi adj[MAXN];
bool isTrue;
vi color(MAXN,-1);
ll blocksize[2];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        adj[i].clear();
        color[i]=-1;
    }
}

void dfs(int u, int c)
{
    blocksize[c]++;
    color[u]=c;
    for(int v:adj[u])
    {
        if(color[v]==-1)
        {
            dfs(v,1-c);
        }
        else if(color[v]==c)
        {
            isTrue=false;
        }
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    init(n);

    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        blocksize[0]=blocksize[1]=0;
        isTrue=true;
        if(color[i]==-1)
        {
            dfs(i,0);
        }

        if(isTrue)
        {
            //重点：取二分图块大小较大的那一个
            ans+=max(blocksize[0],blocksize[1]);
        }
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