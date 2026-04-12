//https://acm.hdu.edu.cn/contest/problem?cid=1200&pid=1008

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int cmp(int a, int b)
{
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        if(a%10==b%10) cnt++;
        a/=10;
        b/=10;
    }
    return cnt;
}

void solve() 
{
    int n; cin>>n;
    vector<pii> guess(n);
    for(int i=0;i<n;i++)
    {
        string s; int k;
        cin>>s>>k;
        guess[i]={stoi(s),k};
    }

    for(int i=0;i<10000;i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            int s=guess[j].first;
            int k=guess[j].second;

            if(cmp(i,s)!=k)
            {
                flag=false;
                break;
            }
        }
        
        if(flag)
        {
            cout<<setw(4)<<setfill('0')<<i<<endl;
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