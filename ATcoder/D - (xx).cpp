//https://atcoder.jp/contests/abc454/tasks/abc454_d

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
    string a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"Yes"<<endl;
        return;
    }

    int na=a.size();
    int nb=b.size();

    string new_a,new_b;
    for(int i=0;i<na;i++)
    {
        new_a+=a[i];
        if(new_a.size()>=4&&new_a.substr(new_a.size()-4)=="(xx)")
        {
            new_a.resize(new_a.size()-4);
            new_a+="xx";
        }
    }
    for(int i=0;i<nb;i++)
    {
        new_b+=b[i];
        if(new_b.size()>=4&&new_b.substr(new_b.size()-4)=="(xx)")
        {
            new_b.resize(new_b.size()-4);
            new_b+="xx";
        }
    }

    if(new_a==new_b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //cout<<endl;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}