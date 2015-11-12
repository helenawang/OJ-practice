#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=200;

struct Position
{
    int x,y;
}vul_pos[15];

int b[16];
int n,m;
int goal;
int special;
char G[MAX_N+2][MAX_N+2];
char str[205];
int vul_cnt,ans;
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};//从第一象限到第四象限

int lightable(int x,int y)
{
    if(x>=1&&y>=1&&x<=n&&y<=m&&G[x][y]=='#') return 0;
    return 1;
}

void dfs(int k,int sum,int status)//当前递归深度（该判断第几个vul点），用了几盏灯，vul区域被点亮的状态
{
    if(sum>=ans) return ;//找最少用几盏灯
    if(status==goal) {ans=sum; return ;}
    if(k>=vul_cnt) return ;//已达叶节点

    dfs(k+1,sum,status);//这一点不放灯

    for(int i=k;k<vul_cnt;k++)
    {
        if(i==special) continue;
        int x1=vul_pos[i].x+dx[0];
        int y1=vul_pos[i].y+dy[0];
        if(!lightable(x1,y1)) continue;
        int x2=vul_pos[i].x+dx[1];
        int y2=vul_pos[i].y+dy[1];
        if(!lightable(x2,y2)) continue;

        int s=status|b[i];//这一点放灯
        for(int j=0;j<vul_cnt;j++)
        {
            if(vul_pos[j].x==x1&&vul_pos[j].y==y1) s|=b[j];
            else if(vul_pos[j].x==x2&&vul_pos[j].y==y2) s|=b[j];
        }
        dfs(k+1,sum+1,s);
    }
    return ;
}
int main()
{
    freopen("4770.txt","r",stdin);
    b[0]=1;
    for(int i=1;i<=15;i++)
    {
        b[i]=b[i-1]<<1;
    }
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        vul_cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            for(int j=1;j<=m;j++)
            {
                G[i][j]=str[j-1];
                if(G[i][j]=='.')
                {
                    vul_pos[vul_cnt].x=i;
                    vul_pos[vul_cnt].y=j;
                    vul_cnt++;
                }
            }
        }
        if(vul_cnt==0)
        {
            printf("0\n");
            continue;
        }

        goal=b[vul_cnt]-1;
        ans=1666666;
        dfs(0,0,0);
        for(int i=0;i<vul_cnt;i++)//枚举特殊的那盏灯
        {
            int status;
            special=i;
            for(int j=1;j<4;j++)
            {
                int x1=vul_pos[i].x+dx[j];
                int y1=vul_pos[i].y+dy[j];
                if(!lightable(x1,y1)) continue;
                int x2=vul_pos[i].x+dx[(j+1)%4];
                int y2=vul_pos[i].y+dy[(j+1)%4];
                if(!lightable(x2,y2)) continue;

                status=b[i];//此点可以此方向放灯
                for(int k=0;k<vul_cnt;k++)//更新点亮状态
                {
                    if(vul_pos[k].x==x1&&vul_pos[k].y==y1) status|=b[k];
                    else if(vul_pos[k].x==x2&&vul_pos[k].y==y2) status|=b[k];
                }
                dfs(0,1,status);
            }
        }
        if(ans==1666666) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
