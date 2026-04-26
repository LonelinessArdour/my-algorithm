//https://codeforces.com/contest/13/problem/E
/*
 * 分块解法（弹飞绵羊类问题）
 * 
 * 核心思想：将数组分成大小为 sqrt(n) 的块，预处理每个位置 i 在“跳出当前块”时的三项信息：
 *   jump[i] : 跳出当前块后第一个到达的位置（若直接跳出数组则为 n+1）
 *   step[i] : 跳出当前块所需要的步数
 *   last[i] : 跳出当前块前最后停留的位置（用于回答最后落点）
 * 
 * 查询(x) ：反复执行 ans_step += step[x], ans_last = last[x], x = jump[x] 直至 x > n
 * 修改(x, val) ：更新 a[x] 后，对 x 所在块从右向左重新 DP 计算 jump/step/last
 * 
 * 时间复杂度：O((n + m) * sqrt(n)) ，空间复杂度 O(n)
 */

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5 + 10;
const int BLOCK = 320;

int a[MAXN];
int jump[MAXN];
int step[MAXN];
int last[MAXN];
int bel[MAXN];
int L[MAXN],R[MAXN];
int n,m;

void rebuild(int x) 
{
    int id=bel[x];
    for (int i=R[id]; i>=L[id]; i--) 
    {
        int nxt=i+a[i];
        if (nxt>n) 
        {
            jump[i]=n+1;
            step[i]=1;
            last[i]=i;
        } 
        else if (bel[nxt]!=id) 
        {
            jump[i]=nxt;
            step[i]=1;
            last[i]=i;
        } 
        else 
        {
            jump[i]=jump[nxt];
            step[i]=step[nxt]+1;
            last[i]=last[nxt];
        }
    }
}

pii query(int x) 
{
    int res_step = 0;
    int res_last = 0;
    while(x<=n) 
    {
        res_step+=step[x];
        res_last=last[x];
        x=jump[x];
    }
    return {res_last,res_step};
}

void solve() 
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];

    int num=(n+BLOCK-1)/BLOCK;
    for (int i=1; i<=num;i++) 
    {
        L[i]=(i-1)*BLOCK+1;
        R[i]=min(i*BLOCK,n);
        for (int j=L[i];j<=R[i];j++) 
        {
            bel[j]=i;
        }
    }

    for(int i=1;i<=num;i++) rebuild(L[i]);

    while(m--)
    {
        int op, x, y;
        cin>>op;
        if(op==0)
        {
            cin>>x>>y;
            a[x]=y;
            rebuild(x);
        } 
        else 
        {
            cin>>x;
            auto ans=query(x);
            cout<<ans.first<<" "<<ans.second<<endl;
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