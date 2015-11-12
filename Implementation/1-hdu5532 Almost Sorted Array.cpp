#include <cstdio>
using namespace std;

const int MAX_N=100005;
const int MIN_A=1;
const int MAX_A=100000;
int T;
int n;
int in[MAX_N],de[MAX_N];
int flag;
int fix_cnt;

int main()
{
    freopen("5532.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&in[i]);
            de[i]=in[i];
        }

        //��������
        in[0]=MIN_A;
        in[n+1]=MAX_A;
        flag=1;//����ȥ�����һ��Ԫ�غ���������
        fix_cnt=0;
        for(int i=1;i<=n-1;i++)
        {
            if(in[i]<=in[i+1]) continue;
            fix_cnt++;//�������
            if(fix_cnt<=1&&in[i-1]<=in[i+1]) continue;
            flag=0;
            break;
        }
        if(flag)
        {
            printf("YES\n");
            continue;
        }
        flag=1;
        fix_cnt=0;
        for(int i=1;i<=n-1;i++)
        {
            if(in[i]<=in[i+1]) continue;
            fix_cnt++;//�ҹ�����
            if(fix_cnt<=1&&in[i]<=in[i+2]) continue;
            flag=0;
            break;
        }
        if(flag)
        {
            printf("YES\n");
            continue;
        }
        //��������
        de[0]=MAX_A;
        de[n+1]=MIN_A;
        flag=1;//����ȥ�����һ��Ԫ�غ����彵��
        fix_cnt=0;
        for(int i=1;i<=n-1;i++)
        {
            if(de[i]>=de[i+1]) continue;
            fix_cnt++;//�������
            if(fix_cnt<=1&&de[i-1]>=de[i+1]) continue;
            flag=0;
            break;
        }
        if(flag)
        {
            printf("YES\n");
            continue;
        }
        flag=1;
        fix_cnt=0;
        for(int i=1;i<=n-1;i++)
        {
            if(de[i]>=de[i+1]) continue;
            fix_cnt++;//�ҹ�����
            if(fix_cnt<=1&&de[i]>=de[i+2]) continue;
            flag=0;
            break;
        }
        if(flag)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}
