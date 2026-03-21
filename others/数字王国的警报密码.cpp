//https://acm.hdu.edu.cn/contest/problem?cid=1197&pid=1002

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
    int n,k;
    cin>>n>>k;

    if(n>=k)
    {
        cout<<-1<<endl;
        return;
    }

    vl sum(2,0);
    vector<bool> m(k+1,false);
    int index=1;
    ll i=0;
    while(true)
    {
        i++;
        if(index>n) break;
        
        sum[index]=sum[index-1]+i;
        ll MOD=sum[index]%k;
        if(MOD==0) continue;

        if(!m[MOD])
        {
            m[MOD]=true;
            sum.push_back(0);

            cout<<i<<' ';
            index++;
        }
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