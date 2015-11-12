#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_M=1000000;
const int MAX_N=55;

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
    if(x!=y) par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int n,m;
struct Edge
{
    int u,v,w;
}e[MAX_M];

bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
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
    freopen("1287.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m,cmp);
        printf("%d\n",kruscal());
    }
    return 0;
}
