#include <cstdio>
#include <algorithm>
using namespace std;

struct Status
{
    int x,y,d,h;//坐标，方向。当前时间
}st,sj;

int n,k;
char dir_t,dir_j;
int speed_t,speed_j;
int turn_t,turn_j;

void go_next(Status &s,int speed)
{
    s.h++;
    int cnt=0;
    switch(s.d)//由于speed<n，所以最多只碰壁折返一次
    {
    case 0:
        while(s.y<n&&cnt<speed){s.y++; cnt++;}
        if(cnt<speed)
        {
            s.y-=speed-cnt;
            s.d=2;
        }break;
    case 1:
        while(s.x>1&&cnt<speed){s.x--; cnt++;}
        if(cnt<speed)
        {
            s.x+=speed-cnt;
            s.d=3;
        }break;
    case 2:
        while(s.y>1&&cnt<speed){s.y--; cnt++;}
        if(cnt<speed)
        {
            s.y+=speed-cnt;
            s.d=0;
        }break;
    case 3:
        while(s.x<n&&cnt<speed){s.x++; cnt++;}
        if(cnt<speed)
        {
            s.x-=speed-cnt;
            s.d=1;
        }
    }
}

int main()
{
    freopen("4452.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        getchar();
        scanf("%c",&dir_t);
        scanf("%d%d",&speed_t,&turn_t);
        getchar();
        scanf("%c",&dir_j);
        scanf("%d%d",&speed_j,&turn_j);
        scanf("%d",&k);

        st.x=st.y=1;
        st.h=sj.h=0;
        sj.x=sj.y=n;
        st.d=turn_t;
        sj.d=turn_j;
        switch(dir_t)
        {
            case 'E':st.d=0;break;
            case 'N':st.d=1;break;
            case 'W':st.d=2;break;
            case 'S':st.d=3;break;
        }
        switch(dir_j)
        {
            case 'E':sj.d=0;break;
            case 'N':sj.d=1;break;
            case 'W':sj.d=2;break;
            case 'S':sj.d=3;break;
        }

        while(k--)
        {
            if(st.x==sj.x&&st.y==sj.y)
                swap(st.d,sj.d);
            else
            {
                if(st.h!=0&&st.h%turn_t==0)
                    st.d=(st.d+1)%4;
                if(sj.h!=0&&sj.h%turn_j==0)
                    sj.d=(sj.d+1)%4;
            }
            go_next(st,speed_t);
            go_next(sj,speed_j);
        }
        printf("%d %d\n",st.x,st.y);
        printf("%d %d\n",sj.x,sj.y);
    }
    return 0;
}
