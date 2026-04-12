#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;

const int MAXN=5e6+5;
int n,k;
int a[MAXN];

int partition(int l, int r)
{
    int pivot=a[l];
    int i=l;
    for(int j=l+1;j<=r;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[i]);
    return i;
}

int quickSelect(int l, int r)
{
    while(l<=r)
    {
        int pos=partition(l,r);
        if(pos==k) return a[pos];
        else if(pos>k) r=pos-1;
        else l=pos+1;
    }
    return a[r];
}

void solve() 
{
    cin>>n>>k; k++;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<quickSelect(1,n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}