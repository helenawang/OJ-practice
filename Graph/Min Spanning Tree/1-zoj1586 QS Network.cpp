#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N=1005;
const int INF=10000;
int T;
int n;
int price[MAX_N];
int G[MAX_N][MAX_N];
int vis[MAX_N];
int mincost[MAX_N];

int prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) mincost[i]=INF;
    mincost[0]=0;
    vis[0]=1;
    for(int i=0;i<n;i++)
    {
        mincost[i]=G[0][i];
    }
    while(1)
    {
        int u=-1;
        int min_e=INF;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&mincost[i]<min_e)
            {
                u=i;
                min_e=mincost[i];
            }
        }
        if(u==-1) break;
        vis[u]=1;
        ans+=min_e;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&mincost[i]>G[u][i])
                mincost[i]=G[u][i];
        }
    }
    return ans;
}

int main()
{
    freopen("1586.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&price[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&G[i][j]);
                G[i][j]+=price[i]+price[j];
            }
            G[i][i]=0;
        }
        printf("%d\n",prim());
    }
    return 0;
}
