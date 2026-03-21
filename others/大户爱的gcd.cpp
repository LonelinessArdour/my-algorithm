https://acm.hdu.edu.cn/contest/problem?cid=1197&pid=1008

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=2e5+5;

int gcd(int a, int b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int lcm(int a, int b)
{
    return a/gcd(a,b)*b;
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vi b(n+1,1);
    for(int i=0;i<m;i++)
    {
        int x,y,g;
        cin>>x>>y>>g;
        b[x]=lcm(b[x],g);
        b[y]=lcm(b[y],g);
    }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<gcd(b[x],b[y])<<endl;
    }
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();
}