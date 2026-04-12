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
    int n;
    cin>>n;
    vl x(n),e(n);
    for(int i=0;i<n;i++) cin>>x[i]>>e[i];

    vector<pll> point(n);
    for(int i=0;i<n;i++) 
    {
        point[i].first=e[i]+x[i];
        point[i].second=e[i]-x[i];
    }
    sort(point.begin(),point.end());

    deque<ll> mindq;
    for(int i=0;i<n;i++)
    {
        while(!mindq.empty()&&mindq.back()<=point[i].second) mindq.pop_back();
        mindq.push_back(point[i].second);
    }
    cout<<mindq.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}