//https://atcoder.jp/contests/abc451/tasks/abc451_e

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 3005;
struct Edge
{
    int u, v, w;
};

vi rank_;
vi parent;
vector<Edge> edges;
vector<pii> adj[MAXN];

int find(int u)
{
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int x, int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(rank_[x]<rank_[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        if(rank_[x]==rank_[y]) rank_[x]++;
    }
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void kruskal(int n)
{
    sort(edges.begin(), edges.end(), cmp);
    rank_.resize(n+1,0);
    parent.resize(n+1);
    for(int i=1;i<=n;i++) parent[i]=i;

    int cnt=0;
    for(Edge e:edges)
    {
        if(cnt==n-1) break;
        int u=e.u, v=e.v, w=e.w;
        if(find(u)!=find(v))
        {
            cnt++;
            unite(u,v);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
}

void solve() 
{
    int n;
    cin>>n;
    vector<vi> a(n+1, vi(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int w;
            cin>>w;
            
            a[i][j]=w;
            a[j][i]=w;
            edges.push_back({i,j,w});
            edges.push_back({j,i,w});
        }
    }
    kruskal(n);

    vector<vi> dist(n+1, vi(n+1, -1));
    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        q.push(i);
        dist[i][i]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto it:adj[u])
            {
                int v=it.first, w=it.second;
                if(dist[i][v]==-1)
                {
                    dist[i][v]=dist[i][u]+w;
                    q.push(v);
                }
            }   
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]!=a[i][j])
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}