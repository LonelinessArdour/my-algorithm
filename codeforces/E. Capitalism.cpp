https://codeforces.com/problemset/problem/1450/E

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,m;

void solve() 
{
    cin>>n>>m;
    vector<vi> dist(n+1,vi(n+1,INT_MAX));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    vi u(m),v(m),w(m);
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        dist[u[i]][v[i]]=1;
        if(w[i]==0) dist[v[i]][u[i]]=1;
        else dist[v[i]][u[i]]=-1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    pii best={-1,1};
    for(int i=1;i<=n;i++)
    {
        //负环检测
        if(dist[i][i]<0)
        {
            cout<<"NO"<<endl;
            return;
        }

        for(int j=1;j<=n;j++)
        {
            best=max(best,{dist[i][j],i});
        }
    }

    int start=best.second;
    //非常巧妙的二分图判断方法
    for(int i=0;i<m;i++)
    {
        if(dist[start][u[i]]==dist[start][v[i]])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    cout<<best.first<<endl;
    for(int i=1;i<=n;i++) cout<<dist[start][i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}