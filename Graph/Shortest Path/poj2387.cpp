#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N=1005;
const int MAX_M=2005;
const int INF=100000;
int n,m;
struct Edge
{
    int to,cost;
    Edge(){}
    Edge(int tt,int cc):to(tt),cost(cc){}
};
typedef pair<int,int> P;//mincost,to
vector<Edge> G[MAX_N];
int vis[MAX_N];
int mincost[MAX_N];

void dijkstra()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) mincost[i]=INF;
    mincost[n-1]=0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,n-1));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int u=p.second;
        if(vis[u]||mincost[u]<p.first) continue;
        vis[u]=1;
        mincost[u]=p.first;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].to;
            if(vis[v]||mincost[v]<mincost[u]+G[u][i].cost) continue;
            mincost[v]=mincost[u]+G[u][i].cost;
            que.push(P(mincost[v],v));
        }
    }
    return ;
}

int main()
{
    freopen("2387.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) G[i].clear();
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--; v--;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    dijkstra();
    printf("%d\n",mincost[0]);
    return 0;
}
