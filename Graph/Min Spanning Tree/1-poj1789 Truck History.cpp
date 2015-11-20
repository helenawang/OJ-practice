#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=2005;

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

char truck[MAX_N][10];
int n,m;
struct Edge
{
    int u,v,w;
}e[MAX_N*MAX_N];
bool cmp(const Edge e1,const Edge e2)
{
    return e1.w<e2.w;
}

int kruscal()
{
    int ans=0;
    init();
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
    freopen("1789.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%s",truck[i]);
        m=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cnt=0;
                for(int t=0;t<7;t++)
                    if(truck[i][t]!=truck[j][t]) cnt++;
                e[m].u=i;
                e[m].v=j;
                e[m].w=cnt;
                m++;
            }
        }
        sort(e,e+m,cmp);
        printf("The highest possible quality is 1/%d.\n",kruscal());
    }
    return 0;
}
