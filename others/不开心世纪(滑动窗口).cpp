//https://acm.hdu.edu.cn/contest/problem?cid=1202&pid=1007
//题目转换：维护一个滑动窗口
//当窗口内位于排列内所有的数都存在时，这是一个合法窗口
//此时将ans更新为min(ans, dq.size()-m)
//随后不断收缩左边界并重复上述操作
//直到该窗口不再合法

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
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    deque<int> dq;
    int have=0;
    vi cnt(m+1,0);

    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int curr=a[i];
        dq.push_back(curr);

        if(curr<=m)
        {
            cnt[curr]++;
            if(cnt[curr]==1) have++;
        }

        while(have>=m)
        {
            ans=min(ans,(int)dq.size()-m);

            int l=dq.front();
            dq.pop_front();

            if(l<=m)
            {
                cnt[l]--;
                if(cnt[l]==0) have--;
            }
        }
    }
    
    if(ans!=INT_MAX) cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
}