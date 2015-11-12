#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX_N=100;
int n,m,k;
int sx,sy,goal;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int b[]={1,2,4,8,16};//原作者的写法，这个数组有大用~
char G[MAX_N+2][MAX_N+2];
int vis[MAX_N+2][MAX_N+2][20];//第三维是状压，表示当前已得宝藏状态 1111~0000
char str[105];

struct Node
{
    int x,y,step,get;//走到这一点的步数，到这一点已得宝藏状态
    Node(){}
    Node(int xx,int yy,int ss,int gg):x(xx),y(yy),step(ss),get(gg){}
};

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<Node> que;
    que.push(Node(sx,sy,0,0));
    vis[sx][sy][0]=1;
    while(!que.empty())
    {
        Node cur=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(G[nx][ny]=='#') continue;

            Node next(nx,ny,cur.step+1,cur.get);
            if(G[nx][ny]<=8) next.get|=G[nx][ny];//找到一处宝藏，追加到当前宝藏状态
            if(vis[nx][ny][next.get]) continue;//同一点同一宝藏状态，只入队一次
            vis[nx][ny][next.get]=1;
            if(next.get==goal) return next.step;//找到全部宝藏，返回
            que.push(next);
        }
    }
    return -1;
}

int main()
{
    //freopen("1002.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            int cnt=1;
            for(int j=0;str[j]!='\0';j++)
            {
                if(str[j]=='#') G[i][cnt++]='#';
                else if(str[j]=='.') G[i][cnt++]='.';
                else if(str[j]=='@')
                {
                    G[i][cnt++]='@';
                    sx=i;
                    sy=cnt-1;
                }
            }
        }
        scanf("%d",&k);
        goal=b[k]-1;//通过k和b数组得到目标状态（1111，111，11，1，0之一）
        while(k--)
        {//按先后顺序，把每个宝藏所在点的状态设为（1，10，100，1000之一），b数组好6
            int x,y;
            scanf("%d%d",&x,&y);
            G[x][y]=b[k];
        }
        printf("%d\n",bfs());
    }
    return 0;
}
