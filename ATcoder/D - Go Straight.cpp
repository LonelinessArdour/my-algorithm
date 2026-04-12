//https://atcoder.jp/contests/abc453/tasks/abc453_d

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXH=1005;
int h,w;
char grid[MAXH][MAXH];
bool vis[MAXH][MAXH][4];
int sx,sy,ex,ey;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char dir_ch[4]={'R','L','D','U'};

struct node
{
    int x;
    int y;
    int d;
};

struct
{
    int x;
    int y;
    int pd;
}pre[MAXH][MAXH][4];

bool bfs()
{
    queue<node> q;
    q.push({sx,sy,-1});
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();

        int x=curr.x;
        int y=curr.y;
        int prev_d=curr.d;
        if(x==ex&&y==ey) return true;

        for(int i=0;i<4;i++)
        {
            if(grid[x][y]=='o'&&i!=prev_d) continue;
            if(grid[x][y]=='x'&&i==prev_d) continue;

            int nx=x+dir[i][0];
            int ny=y+dir[i][1];

            if(nx<=0||nx>h||ny<=0||ny>w||vis[nx][ny][i]) continue;
            if(grid[nx][ny]=='#') continue;

            vis[nx][ny][i]=true;
            pre[nx][ny][i]={x,y,prev_d};
            q.push({nx,ny,i});
        }
    }
    return false;
}

string get_path()
{
    int d=-1;
    for(int i=0;i<4;i++)
    {
        if(vis[ex][ey][i])
        {
            d=i;
            break;
        }
    }

    string res;
    int x=ex,y=ey;
    while(x!=sx||y!=sy)
    {
        res+=dir_ch[d];
        int px=pre[x][y][d].x;
        int py=pre[x][y][d].y;
        int pd=pre[x][y][d].pd;

        x=px,y=py,d=pd;
    }
    reverse(res.begin(),res.end());
    return res;
}

void solve() 
{
    memset(vis,false,sizeof(vis));
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        string row;
        cin>>row;
        row=' '+row;
        for(int j=1;j<=w;j++)
        {
            grid[i][j]=row[j];
            if(row[j]=='S') 
            {
                sx=i;
                sy=j;
            }
            if(row[j]=='G')
            {
                ex=i;
                ey=j;
            }
        }
    }

    if(!bfs()) cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        cout<<get_path();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}