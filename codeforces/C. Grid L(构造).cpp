//https://codeforces.com/contest/2220/problem/C
//解题方法：通过配方法将问题转化为对 targ=2p+4q+1=(2m+1)(2n+1) 的因式分解，
//找到两个≥3 的奇数因子 a,b，
//验证 q 不超过网格较小直角数后输出 n=(a-1)/2、m=(b-1)/2

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
    ll p,q;
    cin>>p>>q;
    ll targ=2*p+4*q+1;

    for(ll a=3;a*a<=targ;a++)
    {
        if(targ%a!=0) continue;
        ll b=targ/a;
        if(a%2==0||b%2==0) continue;

        ll n=(a-1)/2;
        ll m=(b-1)/2;
        ll h=(n+1)*m;
        ll w=(m+1)*n;
        if(q>min(h,w)) continue;

        cout<<n<<' '<<m<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}