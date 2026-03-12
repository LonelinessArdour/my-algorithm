#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9+7;
const int MAXN = 3e6+5;

ll fact[MAXN], inv_fact[MAXN];
ll quick_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp)
    {
        if(exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    inv_fact[MAXN - 1] = quick_pow(fact[MAXN - 1], MOD - 2);
    for(int i = MAXN - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll ncr(ll n, ll r)
{
    if(r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

void solve()
{
    ll b,g,x,y; cin >> b >> g >> x >> y;
    if(x + y > g)
    {
        cout<<0<<'\n';
        return;
    }

    ll ans = (ncr(b+g,b)-ncr(b+x+y-1,b)+MOD)%MOD;
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int t; cin >> t;
    while(t--) solve();
}