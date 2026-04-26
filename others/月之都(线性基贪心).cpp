//https://acm.hdu.edu.cn/contest/problem?cid=1202&pid=1009

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int LOG=30;
int basis[LOG+1];

void insert_basis(int x)
{
    for(int i=LOG;i>=0;i--)
    {
        if(!(x & (1<<i))) continue;
        if(!basis[i])
        {
            basis[i]=x;
            return;
        }
        x^=basis[i];
    }
}

void solve() 
{
    memset(basis, 0, sizeof(basis));
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        int nw=u^v^w;
        insert_basis(nw);
    }

    int ans=1^n;
    for(int i=LOG;i>=0;i--)
    {
        if((ans^basis[i])<ans)
        {
            ans^=basis[i];
        }
    }
    cout<<ans<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
}