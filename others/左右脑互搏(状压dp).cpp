//https://acm.hdu.edu.cn/contest/problem?cid=1200&pid=1004
//建议作为状压dp模板题浏览

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
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int max_mask=(1<<n)-1;
    vi xor_sum(max_mask+1,0);
    for(int i=1;i<=max_mask;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                xor_sum[i]=xor_sum[i^(1<<j)]^a[j];
                break;
            }
        }
    }

    vector<bool> dp(max_mask+1,false);
    for(int i=1;i<=max_mask;i++)
    {
        for(int j=0;j<n;j++)
        {
            //保证a[j]在当前i表示的序列中存在
            if(!(i&(1<<j))) continue;

            //检查去除a[j]是否可行
            int remaining=xor_sum[i^(1<<j)];    //去除a[j]以后的状态
            if(remaining>=a[j]) continue;   //删除的这个数必须大于删除这个数后集合中剩余元素的异或和

            //如果删除a[j]以后对手为必输态，则i为必赢态
            if(!dp[i^(1<<j)])
            {
                dp[i]=true;
                break;
            }
        }
    }

    if(dp[max_mask]) cout<<"Left"<<endl;
    else cout<<"Right"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}