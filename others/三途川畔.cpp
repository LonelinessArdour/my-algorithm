//https://acm.hdu.edu.cn/contest/problem?cid=1198&pid=1004

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve()
{
    ll n,k;
    cin>>n>>k;

    for(int i=0;i<n-2;i++)
        cout<<1<<' ';
    ll s=k+n-1;
    for(ll a=2;(a-1)*(a-1)<=s;a++)
    {
        ll at=a-1;
        if(s%at==0)
        {
            cout<<a<<' '<<s/at+1<<endl;
            return;
        }
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