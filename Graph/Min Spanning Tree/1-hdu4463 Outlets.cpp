#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N=55;
const double INF=2000;

struct Point
{
    int x,y;
}a[MAX_N];

double dis(Point& p1, Point& p2)
{
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int n;
int nike,apple;
double cost[MAX_N][MAX_N];//�ڽӾ��󣨸����ڳ���ͼ��
double mincost[MAX_N];//���ϵ���i����̾���
int used[MAX_N];

double prim()
{
    double res;
    for(int i=0;i<n;i++)
    {
        mincost[i]=INF;
        used[i]=0;
    }//��nike,apple��������뼯�ϣ�����������������ĵ��mincost
    mincost[nike]=mincost[apple]=0;
    used[nike]=used[apple]=1;
    res=cost[nike][apple];
    for(int i=0;i<n;i++)
    {
        mincost[i]=min(mincost[i],cost[nike][i]);
    }
    for(int i=0;i<n;i++)
    {
        mincost[i]=min(mincost[i],cost[i][apple]);
    }
    while(1)
    {
        int v=-1;
        for(int i=0;i<n;i++)//�ҵ����������mincost��С�ĵ�
        {
            if(!used[i]&&(v==-1||mincost[i]<mincost[v]))
                v=i;
        }
        if(v==-1) break;//�����ڸ�Ȩ��
        used[v]=1;
        res+=mincost[v];//���뼯�ϣ�������������ĵ�
        for(int i=0;i<n;i++)
        {
            mincost[i]=min(mincost[i],cost[i][v]);
        }
    }
    return res;
}


int main()
{
    freopen("4463.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        scanf("%d%d",&nike,&apple);
        nike--;
        apple--;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i=0;i<n;i++)//���������룬�õ��ڽӾ���
        {
            cost[i][i]=0;
            for(int j=i+1;j<n;j++)
                cost[i][j]=cost[j][i]=dis(a[i],a[j]);
        }
        printf("%.2lf\n",prim());
    }
    return 0;
}
