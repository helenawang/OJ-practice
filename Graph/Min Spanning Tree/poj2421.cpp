#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=105;
int par[MAX_N];
void init()
{
    memset(par,-1,sizeof(par));
}
int find(int x)
{
    if(par[x]==-1) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int n,m;
int p;
int G[MAX_N][MAX_N];
struct Edge
{
    int u,v,w;
}e[MAX_N*MAX_N],ep[MAX_N*MAX_N];
bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

int kruscal()
{
    int ans=0;
    init();
    for(int i=0;i<p;i++)
    {
        unite(ep[i].u,ep[i].v);
        //ans+=ep[i].w;
    }
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
    freopen("2421.txt","r",stdin);
    scanf("%d",&n);
    m=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            e[m].u=i;
            e[m].v=j;
            e[m].w=G[i][j];
            m++;
        }
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ep[i].u=--u;
        ep[i].v=--v;
        ep[i].w=G[u][v];
    }
    sort(e,e+m,cmp);
    printf("%d\n",kruscal());
    return 0;
}
