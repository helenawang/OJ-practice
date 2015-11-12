#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n,m,k;
typedef pair<int,int> P;
P pants[1005];//i号pant被p1引用first次,被p2引用second次
int p,p1,p2,p3;
int ans;

int main()
{
    freopen("4451.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if(n==0&&m==0&&k==0) break;
        ans=n*m*k;
        memset(pants,0,sizeof(pants));
        p1=p2=p3=0;
        scanf("%d",&p);
        char s1[10],s2[10];
        int n1,n2;
        for(int i=0;i<p;i++)
        {
            scanf("%s",s1);
            scanf("%d",&n1);
            scanf("%s",s2);
            scanf("%d",&n2);
            if(s1[0]=='c')
            {
                p1++;
                pants[n2].first++;
            }else if(s1[0]=='p')
            {
                p2++;
                pants[n1].second++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            p3+=pants[i].first*pants[i].second;
        }
        ans-=p1*k+p2*n-p3;
        printf("%d\n",ans);
    }
    return 0;
}

