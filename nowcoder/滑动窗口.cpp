https://ac.nowcoder.com/acm/contest/129231/D

#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve()
{
    int n; cin>>n;
    vl a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    deque<ll> maxdq, mindq;
    int l=0, r=0;
    ll ans=0;
    while(r<n)
    {
        while(!maxdq.empty()&&a[maxdq.back()]<=a[r]) maxdq.pop_back();
        maxdq.push_back(r);
        while(!mindq.empty()&&a[mindq.back()]>=a[r]) mindq.pop_back();
        mindq.push_back(r);

        while(labs(a[maxdq.front()]-a[mindq.front()])>1)
        {
            l++;
            if(maxdq.front()<l) maxdq.pop_front();
            if(mindq.front()<l) mindq.pop_front();
        }
        ans+=r-l+1;
        r++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--) solve();
}