#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=2e5+5;
const int B=320;
int diff[MAXN][B];

void solve() 
{
    int n,k;
    cin>>n>>k;
    int b=int(sqrt(n));
    vi cnt(n+1,0);

    for(int i=0;i<k;i++)
    {
        int a,l,d;
        cin>>a>>l>>d;
        if(d>b)
        {
            while(l--)
            {
                cnt[a]++;
                a+=d;
            }
        }
        else
        {
            diff[a][d]++;
            diff[a+l*d][d]--;
        }
    }

    for(int d=1;d<=b;d++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>=d) diff[i][d]+=diff[i-d][d];
            cnt[i]+=diff[i][d];
        }
    }

    for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}