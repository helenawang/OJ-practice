#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAX_N=55;
const double INF=2000;

struct Point
{
    int x,y;
}a[MAX_N];

double dis(Point& p1, Point& p2)
{
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct Edge
{
    int to;
    double cost;
    Edge(){}
    Edge(int tt,double cc):to(tt),cost(cc){}
};
typedef pair<double,int> P;//cost,to
int n;
int nike,apple;
double dis_na;
vector<Edge> G[MAX_N];
double mincost[MAX_N];//集合到点i的最短距离
int used[MAX_N];

double prim()
{
    double res=0;
    for(int i=0;i<n;i++)
    {
        mincost[i]=INF;
        used[i]=0;
    }//将nike,apple两个点加入集合，并将与它们相邻的边推入队列
    mincost[nike]=mincost[apple]=0;
    used[nike]=used[apple]=1;
    res=dis_na;
    priority_queue<P,vector<P>,greater<P> >que;
    for(int i=0;i<G[nike].size();i++)
    {
        int u=G[nike][i].to;
        if(used[u]||mincost[u]<G[nike][i].cost) continue;
        mincost[u]=G[nike][i].cost;
        que.push(P(mincost[u],u));
    }
    for(int i=0;i<G[apple].size();i++)
    {
        int u=G[apple][i].to;
        if(used[u]||mincost[u]<G[apple][i].cost) continue;
        mincost[u]=G[apple][i].cost;
        que.push(P(mincost[u],u));
    }
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(used[v]||mincost[v]<p.first) continue;
        mincost[v]=p.first;
        used[v]=1;
        res+=mincost[v];//加入集合，更新它所到达的点
        for(int i=0;i<G[v].size();i++)
        {
            int u=G[v][i].to;
            if(!used[u]&&mincost[u]>G[v][i].cost)
            {
                mincost[u]=G[v][i].cost;
                que.push(P(mincost[u],u));
            }
        }
    }
    return res;
}

int main()
{
    freopen("4463.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        scanf("%d%d",&nike,&apple);
        nike--;
        apple--;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<n;i++)//求两点间距离，得到表
        {
            for(int j=i+1;j<n;j++)
            {
                double temp=dis(a[i],a[j]);
                G[i].push_back(Edge(j,temp));
                G[j].push_back(Edge(i,temp));
                if(i==nike&&j==apple) dis_na=temp;
            }
        }
        printf("%.2lf\n",prim());
    }
    return 0;
}
