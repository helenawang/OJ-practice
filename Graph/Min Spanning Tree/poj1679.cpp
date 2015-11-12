#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=105;
const int MAX_M=5005;

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

int t;
int n,m;
struct Edge
{
    int u,v,w;
}e[MAX_M];

bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

bool inter(Edge e1,Edge e2)
{
    if(e1.u==e2.u||e1.u==e2.v||e1.v==e2.u||e1.v==e2.v) return true;
    else return false;
}

int kruscal()
{
    int ans=0;
    init();
    ans+=e[0].w;
    unite(e[0].u,e[0].v);
    int cur_w=e[0].w;
    for(int i=1;i<m;i++)
    {
        if(same(e[i].u,e[i].v))
        {
            for(int j=i-1;e[j].w==e[i].w;j--)
            {
                if(inter(e[i],e[j]))//判两条边有无交点
                {
                    ans=-1;
                    break;
                }
            }
        }else
        {
            unite(e[i].u,e[i].v);
            ans+=e[i].w;
            cur_w=e[i].w;
        }
    }
    return ans;
}

int main()
{
    freopen("1679.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        if(n==1) {printf("0\n"); continue;}
        sort(e,e+m,cmp);
        int ans=kruscal();
        if(ans==-1)
            printf("Not Unique!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
