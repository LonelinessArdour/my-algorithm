//https://codeforces.com/contest/1968/problem/D

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=2e5+5;

//按环分块
int bel=1;
vl blocks[3];
ll sum1[MAXN],sum2[MAXN];

//初始图相关
int adj[MAXN],a[MAXN];
bool vis[MAXN];
ll n,k,pb,ps;

void dfs(int u)
{
    for(int i=1;i<=n;i++) vis[i]=true;
    int curr=u;
    while(true)
    {
        vis[curr]=true;
        int next=adj[curr];
        blocks[bel].push_back(a[curr]);

        if(vis[next]) break;
        curr=next; 
    }
}

void solve() 
{
    cin>>n>>k>>pb>>ps;
    for(int i=1;i<=n;i++) cin>>adj[i];
    for(int i=1;i<=n;i++) cin>>a[i];

    bel=1;
    blocks[1].clear();
    blocks[1].push_back(0);
    dfs(pb);

    bel++;
    blocks[2].clear();
    blocks[2].push_back(0);
    dfs(ps);

    int cnt1=blocks[1].size()-1, cnt2=blocks[2].size()-1;
    for(int i=1;i<=cnt1;i++) sum1[i]=sum1[i-1]+blocks[1][i];
    for(int i=1;i<=cnt2;i++) sum2[i]=sum2[i-1]+blocks[2][i];

    ll max1=-1,max2=-1;
    for(int i=1;i<=cnt1;i++)
    {
        if(k-i<0) break;
        ll curr=sum1[i-1]+blocks[1][i]*(k-i+1);
        max1=max(curr,max1);
    }
    for(int i=1;i<=cnt2;i++)
    {
        if(k-i<0) break;
        ll curr=sum2[i-1]+blocks[2][i]*(k-i+1);
        max2=max(curr,max2);
    }

    if(max1>max2) cout<<"Bodya"<<endl;
    else if(max1<max2) cout<<"Sasha"<<endl;
    else cout<<"Draw"<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}