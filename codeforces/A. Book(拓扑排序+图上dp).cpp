//https://codeforces.com/contest/1572/problem/A

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
    int n;
    cin>>n;
    vector<vi> adj(n+1);
    vi dp(n+1,INT_MAX);
    vi in(n+1,0);

    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        in[i]=k;
        if(k==0)
        {
            dp[i]=1;
        }
        else
        {
            for(int j=0;j<k;j++)
            {
                int a;
                cin>>a;
                adj[a].push_back(i);
            }
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }

    //核心错误点修正：判断图上是否有环
    int cnt=0;
    while(!q.empty())
    {
        cnt++;
        int u=q.front();
        int curr=dp[u];
        q.pop();

        for(int v:adj[u])
        {
            int next;
            if(v>u) next=curr;
            else next=curr+1;

            if(dp[v]==INT_MAX) dp[v]=next;
            else dp[v]=max(dp[v],next);

            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    
    if(cnt!=n)
    {
        cout<<-1<<endl;
        return;
    }

    int ans=-1;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}