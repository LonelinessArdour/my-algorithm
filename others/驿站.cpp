//https://acm.hdu.edu.cn/contest/problem?cid=1201&pid=1002
//将风险值转换为路径长，从而将本题转换为最短路问题

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
    int n,m;
    cin>>n>>m;
    vector<vi> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vi dp(n+1,INT_MAX);
    dp[1]=1;

    priority_queue<pii,vector<pii>,greater<>> pq;
    pq.push({1,1});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();

        int u=it.second;
        int curr_risk=it.first;

        if(curr_risk>dp[u]) continue;

        for(int &v:adj[u])
        {
            int new_risk=max(curr_risk,v);
            if(new_risk<dp[v])
            {
                dp[v]=new_risk;
                pq.push({new_risk,v});
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==INT_MAX) cout<<-1<<' ';
        else cout<<dp[i]<<' ';
    }
    cout<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}