//https://acm.hdu.edu.cn/contest/problem?cid=1212&pid=1002
#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct option
{
    int op;
    int x,y;
};

void solve()
{
    int n; cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vi ans;
    int m; cin>>m;
    vector<option> ops(n+m);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        ops[i]={2,a[i],0};
    }
    for(int i=n;i<n+m;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {   
            int x,y; cin>>x>>y;
            ops[i]={op,x,y};
        }
        else
        {
            int x; cin>>x;
            ops[i]={op,x,0};
        }
    }

    for(int i=n+m-1;i>=0;i--)
    {
        int op=ops[i].op;
        int x=ops[i].x;
        int y=ops[i].y;

        if(op==1)
        {
            if(mp.find(y)!=mp.end()) mp[x]=mp[y];
            else mp[x]=y;
        }
        else if(op==2)
        {
            if(mp.find(x)!=mp.end()) ans.push_back(mp[x]);
            else ans.push_back(x);
        }
        else
        {
            mp[x]=-1;
        }
    }

    for(int i=ans.size()-1;i>=0;i--)
    {
        if(ans[i]!=-1)
            cout<<ans[i]<<" ";
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