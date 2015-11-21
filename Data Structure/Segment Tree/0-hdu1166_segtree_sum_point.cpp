//SegmentTree_value_sum.cpp
//�������
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=50005;
int n;//ԭ����Ԫ�ظ���
int a[MAX_N];//ԭ����,�±�0~n������n+1����
int m[MAX_N*4];//�߶����ڵ����飬�±��1��ʼ����ά������ͣ�
int p[MAX_N];//��ԭ���鶨λ�����ڽڵ�

//��ʼ��
//�ⲿ���ã�init(1,0,n-1,a,m,p)
void init(int cur,int b,int e,int* A,int* M,int* P)
{//cur--��ǰ�ڵ㣬[b,e]--cur�ĸ������䣬ԭ���飬�ڵ�����
    if(b>=e)
    {
        M[cur]=A[e];
        P[e]=cur;
    }
    else
    {
        init(cur*2,b,(b+e)/2,A,M,P);
        init(cur*2+1,(b+e)/2+1,e,A,M,P);
        M[cur]=M[cur*2]+M[cur*2+1];
    }
    return ;
}
//����Ͳ�ѯ
//�ⲿ����query(1,0,n-1,a,m,l,r)
int query(int cur,int b,int e,int* A,int* M,int l,int r)
{//[l,r]--Ŀ������
    if(r<b||e<l) return 0;
    if(l<=b&&e<=r) return M[cur];
    int p1=query(cur*2,b,(b+e)/2,A,M,l,r);
    int p2=query(cur*2+1,(b+e)/2+1,e,A,M,l,r);
    return p1+p2;
}
//�������
//�ⲿ����update(k,x,a,m,p)
void update(int k,int x,int* A,int* M,int* P)
{
    A[k]+=x;
    int cur=P[k];
    M[cur]+=x;
    while(cur>0)
    {
        cur/=2;
        M[cur]=M[cur*2]+M[cur*2+1];
    }
}

int T;
int main()
{
    freopen("1166.txt","r",stdin);
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        memset(a,0,sizeof(a));
        printf("Case %d:\n",ca);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        init(1,0,n-1,a,m,p);
    /*
        for(int i=1;i<=31;i++)
        {
            printf("%d %d\n",i,m[i]);
        }
        for(int i=0;i<n;i++)
        {
            printf("%d %d\n",i,p[i]);
        }
    */
        char comm[20];
        while(scanf("%s",comm)!=EOF)
        {
            if(comm[0]=='E') break;
            else if(comm[0]=='Q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,0,n-1,a,m,l-1,r-1));
            }
            else if(comm[0]=='A')
            {
                int k,x;
                scanf("%d%d",&k,&x);
                update(k-1,x,a,m,p);
            }
            else if(comm[0]=='S')
            {
                int k,x;
                scanf("%d%d",&k,&x);
                update(k-1,-x,a,m,p);
            }
        }
    }
    return 0;
}
