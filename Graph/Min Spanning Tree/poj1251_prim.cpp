#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=30;
const int INF=1000;
typedef pair<int,int> P;//cost,to
int n;
int ans;
struct Edge
{
    int to,cost;
    Edge(){}
    Edge(int tt,int cc):to(tt),cost(cc){}
};
vector<Edge> G[MAX_N];
int vis[MAX_N];
int mincost[MAX_N];

int prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++) mincost[i]=INF;
    priority_queue<P,vector<P>,greater<P> > que;
    mincost[1]=0;
    que.push(P(0,1));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(vis[v]||mincost[v]<p.first) continue;
        vis[v]=1;
        mincost[v]=p.first;
        ans+=mincost[v];
        for(int i=0;i<G[v].size();i++)
        {
            int u=G[v][i].to;
            if(!vis[u]&&mincost[u]>G[v][i].cost)
            {
                mincost[u]=G[v][i].cost;
                que.push(P(mincost[u],u));
            }
        }
    }
    return ans;
}

int main()
{
    freopen("1251.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            char s[2];
            scanf("%s",s);
            int k;
            scanf("%d",&k);
            while(k--)
            {
                char ad[2];
                scanf("%s",ad);
                int t,c;
                t=ad[0]-'A'+1;
                scanf("%d",&c);
                G[i].push_back(Edge(t,c));
                G[t].push_back(Edge(i,c));
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}

