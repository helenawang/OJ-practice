#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=105;
const int INF=100005;
int n;
int G[MAX_N][MAX_N];
int mincost[MAX_N];
int vis[MAX_N];

int prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) mincost[i]=INF;
    mincost[0]=0;
    while(1)
    {
        int v=-1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&(v==-1||mincost[i]<mincost[v]))
                v=i;
        }
        if(v==-1) break;
        vis[v]=1;
        ans+=mincost[v];
        for(int i=0;i<n;i++)
        {
            mincost[i]=min(mincost[i],G[v][i]);
        }
    }
    return ans;
}

int main()
{
    freopen("1258.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&G[i][j]);
        printf("%d\n",prim());
    }
    return 0;
}
