//���������ֵ
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=200005;
int n,m;
int a[MAX_N];//ԭ����,�±�0~n-1������n����
int M[MAX_N*4];//�߶����ڵ����飬�±��1��ʼ����ά������ͣ�
int p[MAX_N];//��ԭ���鶨λ�����ڽڵ�

//��ʼ��
//�ⲿ���ã�init(1,0,n-1,a,p)
void init(int cur,int b,int e,int* A,int* P)
{//cur--��ǰ�ڵ㣬[b,e]--cur�ĸ������䣬ԭ���飬�ڵ�����
    if(b>=e)
    {
        M[cur]=A[e];
        P[e]=cur;
    }
    else
    {
        init(cur*2,b,(b+e)/2,A,P);
        init(cur*2+1,(b+e)/2+1,e,A,P);
        M[cur]=max(M[cur*2],M[cur*2+1]);
    }
    return ;
}
//�������ֵ��ѯ
//�ⲿ����query(1,0,n-1,a,l,r)
int query(int cur,int b,int e,int* A,int l,int r)
{//[l,r]--Ŀ������
    if(r<b||e<l) return 0;
    if(l<=b&&e<=r) return M[cur];
    int p1=query(cur*2,b,(b+e)/2,A,l,r);
    int p2=query(cur*2+1,(b+e)/2+1,e,A,l,r);
    return max(p1,p2);
}
//�������
//�ⲿ����update(k,x,a,p)
void update(int k,int x,int* A,int* P)
{
    A[k]=x;
    int cur=P[k];
    M[cur]=x;
    while(cur>0)
    {
        cur/=2;
        M[cur]=max(M[cur*2],M[cur*2+1]);
    }
}

int main()
{
    freopen("1754.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        init(1,0,n-1,a,p);
        char comm[5];
        while(m--)
        {
            scanf("%s",comm);
            if(comm[0]=='Q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,0,n-1,a,l-1,r-1));
            }
            else if(comm[0]=='U')
            {
                int k,x;
                scanf("%d%d",&k,&x);
                update(k-1,x,a,p);
            }
        }
    }
    return 0;
}
