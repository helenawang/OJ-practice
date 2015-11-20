#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
const int MAX_S=55;
const int MAX_N=105;
struct Point
{
    int x,y;
    Point(){}
    Point(int xx,int yy):x(xx),y(yy){}
};

struct Edge
{
    Point u,v;
    int w;
}e[MAX_N*MAX_N];
bool cmp(const Edge e1,const Edge e2)
{
    return e1.w<e2.w;
}

int par[(MAX_S<<7)+MAX_S];
void init()
{
    memset(par,-1,sizeof(par));
}
int find(int x)
{
    if(par[x]==-1) return x;
    return par[x]=find(par[x]);
}
void unite(Point p1,Point p2)
{
    int x=(p1.x<<7)+p1.y;
    int y=(p2.x<<7)+p2.y;
    x=find(x);
    y=find(y);
    if(x==y) return ;
    par[x]=y;
}

bool same(Point p1,Point p2)
{
    int x=(p1.x<<7)+p1.y;
    int y=(p2.x<<7)+p2.y;
    return find(x)==find(y);
}

int T;
int w,h;
int n,m;
char maze[MAX_S][MAX_S];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef pair<Point,int> P;
int vis[MAX_S][MAX_S];
int dis[(MAX_S<<7)+MAX_S][(MAX_S<<7)+MAX_S];

void bfs(int x,int y)
{
    int poi=(x<<7)+y;
    memset(vis,0,sizeof(vis));
    queue<P> que;//Point,step
    que.push(P(Point(x,y),0));
    vis[x][y]=1;
    while(!que.empty())
    {
        Point p=que.front().first;
        int step=que.front().second;
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            int npoi=(nx<<7)+ny;
            if(nx<0||ny<0||w<=nx||w<=ny||vis[nx][ny]) continue;
            if(maze[nx][ny]=='#'){vis[nx][ny]=1; continue;}
            if(dis[poi][npoi]||poi==npoi) continue;
            que.push(P(Point(nx,ny),step+1));
            vis[nx][ny]=1;
            if((maze[nx][ny]=='A'||maze[nx][ny]=='S')&&poi!=npoi)
            {
                e[m].u=Point(x,y);
                e[m].v=Point(nx,ny);
                dis[npoi][poi]=dis[poi][npoi]=e[m].w=step+1;
                m++;
            }
        }
    }
}

int kruscal()
{
    init();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            ans+=e[i].w;
        }
    }
    return ans;
}

int main()
{
    freopen("3026.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&w,&h);
        n=0;
        getchar();
        for(int i=0;i<h;i++)
        {
            fgets(maze[i],w,stdin);
            gets(maze[i+1]);
        }
        m=0;
        memset(dis,0,sizeof(dis));
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
                if(maze[i][j]=='A'||maze[i][j]=='S') bfs(i,j);
        }
/*
       for(int i=0;i<m;i++)
           printf("%d %d -> %d %d = %d\n",e[i].u.x,e[i].u.y,e[i].v.x,e[i].v.y,e[i].w);
*/
        sort(e,e+m,cmp);
        printf("%d\n",kruscal());
    }
    return 0;
}
