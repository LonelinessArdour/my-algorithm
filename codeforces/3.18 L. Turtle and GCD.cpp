https://codeforces.com/gym/104669/problem/L

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
    ll a,b;
    cin>>a>>b;

    ll sum=b*(2*a+b-1)/2;
    vl divisions;
    for(ll d=1;d*d<=sum;d++)
    {
        if(sum%d==0)
        {
            divisions.push_back(d);
        }
    }
    for(int i=divisions.size()-1;i>=0;i--)
    {
        ll d=divisions[i];
        if(sum/d==d) continue;
        divisions.push_back(sum/d);
    }

    reverse(divisions.begin(),divisions.end());
    for(ll d:divisions)
    {
        ll mink=0,maxk=0;
        //重点：枚举子集大小，mink和sumk表示子集和的max和min
        //显然子集和在mink与maxk之间可以取任意值
        for(ll k=1;k<b;k++)
        {
            mink+=a+k-1;
            maxk+=a+b-k;

            if(maxk/d*d>=mink)
            {
                cout<<d<<endl;
                return;
            }
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