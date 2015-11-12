#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N=205;
const double INF=2000;
int n;
int x[MAX_N],y[MAX_N];
int vis[MAX_N];
double mincost[MAX_N];
struct Edge
{
    int to;
    double cost;
    Edge(){}
    Edge(int tt,double cc):to(tt),cost(cc){}
};
vector<Edge> G[MAX_N];
int par[MAX_N];
typedef pair<double,int> P;//cost,to

double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double prim()
{
    double ans=0;
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++) mincost[i]=INF;
    mincost[0]=0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,0));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int u=p.second;
        ans=max(ans,p.first);//遇到终点前取出的边要么连接着到达终点的边，要么比到达终点的边短
        if(u==1) break;
        if(vis[u]||mincost[u]<p.first) continue;
        vis[u]=1;
        mincost[u]=p.first;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].to;
            if(vis[v]||mincost[v]<=G[u][i].cost) continue;
            mincost[v]=G[u][i].cost;
            par[v]=u;
            que.push(P(mincost[v],v));
        }
    }
    /*
    for(int i=1;i!=0;i=par[i])
        ans=max(ans,G[i][par[i]].cost);
        */
    return ans;
}

int main()
{
    freopen("2253.txt","r",stdin);
    int ca=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double temp=dis(x[i],y[i],x[j],y[j]);
                G[i].push_back(Edge(j,temp));
                G[j].push_back(Edge(i,temp));
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",ca++,prim());
    }
    return 0;
}

