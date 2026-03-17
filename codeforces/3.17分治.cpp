//https://codeforces.com/problemset/status?my=on

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;
int n;

ll divide(int l, int r, char ch='a')
{
    if(l==r)
    {
        if(s[l]!=ch) return 1;
        else return 0;
    }

    ll cost1=0,cost2=0;

    int mid1=(l+r)/2;
    for(int i=mid1;i>=l;i--)
    {
        if(s[i]!=ch)
        {
            cost1++;
        }
    }
    int mid2=mid1+1;
    for(int i=mid2;i<=r;i++)
    {
        if(s[i]!=ch)
        {
            cost2++;
        }
    }

    return min(cost1+divide(mid2,r,ch+1),cost2+divide(l,mid1,ch+1));
}

void solve()
{
    cin>>n;
    cin>>s;
    s=" "+s;

    ll ans=divide(1,n);
    cout<<ans<<endl;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();
}