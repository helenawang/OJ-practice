#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
struct Point
{
    double x,y,z;
    double r;
}p[MAX_N];
double dis(Point p1,Point p2)
{
    return double(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z)));
}

struct Edge
{
    int u,v;
    double w;
}e[MAX_N*MAX_N];
bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

double kruscal()
{
    double ans=0;
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
    freopen("2031.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z,&p[i].r);
        m=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                e[m].u=i;
                e[m].v=j;
                e[m].w=dis(p[i],p[j])-p[i].r-p[j].r;
                if(e[m].w<1e-10) e[m].w=0;//¸¡µãÊýÎó²î
                m++;
            }
        sort(e,e+m,cmp);
        printf("%.3f\n",kruscal());//POJÆÀ²â»ú
    }
    return 0;
}
