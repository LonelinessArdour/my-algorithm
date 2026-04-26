//https://codeforces.com/contest/2225/problem/D
// 思路：
// 设前缀异或 P(i)=1^2^...^i，则区间 [l,r] 的异或为 P(r)^P(l-1)。
// 要求区间异或为 0，等价于 P(r)=P(l-1)。
// 又因为区间必须包含 x，所以 l-1 只能在 [0, x-1]，r 只能在 [x, n]。
// 于是只需统计两边前缀异或值为 0 和 1 的个数，答案为：
// left0 * right0 + left1 * right1。
// 前缀异或 1..i 的值只和 i mod 4 有关，因此可以 O(1) 计算。

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=998244353;

ll xor_sum(ll n) {
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}

void solve() 
{
    ll n,x;
    cin>>n>>x;

    ll left0=(x/4+1)%MOD;
    ll right0=((n+1)/4-x/4)%MOD;
    ll left1=((x+2)/4)%MOD;
    ll right1=((n+3)/4-(x+2)/4)%MOD;
    cout<<(left0*right0%MOD+left1*right1%MOD)%MOD<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1; cin>>t;
    while(t--) solve();
}