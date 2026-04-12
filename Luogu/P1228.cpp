#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void divide(ll x1, ll y1, ll x2, ll y2, ll n)
{
    if(n==1) return;
    ll s=n/2;
    if(x1-x2 < s)
    {
        if(y1-y2 < s) // 左上
        {
            cout<<x2+s<<' '<<y2+s<<' '<<1<<endl;
            divide(x1,y1,x2,y2,s);
            divide(x2+s-1,y2+s,x2,y2+s,s);
            divide(x2+s,y2+s-1,x2+s,y2,s);
            divide(x2+s,y2+s,x2+s,y2+s,s);
        }
        else // 右上
        {
            cout<<x2+s<<' '<<y2+s-1<<' '<<2<<endl;
            divide(x2+s-1,y2+s-1,x2,y2,s);
            divide(x1,y1,x2,y2+s,s);
            divide(x2+s,y2+s-1,x2+s,y2,s);
            divide(x2+s,y2+s,x2+s,y2+s,s);
        }
    }
    else
    {
        if(y1-y2 < s)
        {
            cout<<x2+s-1<<' '<<y2+s<<' '<<3<<endl;
            divide(x2+s-1,y2+s-1,x2,y2,s);
            divide(x2+s-1,y2+s,x2,y2+s,s);
            divide(x1,y1,x2+s,y2,s); 
            divide(x2+s,y2+s,x2+s,y2+s,s);
        }
        else
        {
            cout<<x2+s-1<<' '<<y2+s-1<<' '<<4<<endl;
            divide(x2+s-1,y2+s-1,x2,y2,s);
            divide(x2+s-1,y2+s,x2,y2+s,s);
            divide(x2+s,y2+s-1,x2+s,y2,s);
            divide(x1,y1,x2+s,y2+s,s);
        }
    }
}

void solve()
{
    ll k,x,y;
    cin>>k>>x>>y;
    ll n=ll(pow(2,k));
    divide(x,y,1,1,n);

}    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}