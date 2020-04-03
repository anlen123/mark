///A
单点更新 加上
/*1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
*/
///刘华强
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include <cstdio>
#define Maxn 110000
int sum = 0;
struct LineTreeNode
{
	int val;
	int add;
	int l, r;
}tree[Maxn * 4];

void pushup(int x)
{
	int temp = x << 1;
	tree[x].val = tree[temp].val + tree[temp + 1].val;
}

void built(int l, int r, int x)
{
	tree[x].l = l;
	tree[x].r = r;
	tree[x].add = 0;
	if (l == r)
	{
		scanf("%d", &tree[x].val);
		return;
	}
	int temp = x << 1;
	int mid = (l + r) >> 1;
	built(l, mid, temp);
	built(mid + 1, r, temp + 1);
	pushup(x);
}
void pushdown(int x)
{
	int temp = x << 1;
	tree[temp].val += tree[x].add*(tree[temp].r - tree[temp].l + 1);
	tree[temp + 1].val += tree[x].add*(tree[temp + 1].r - tree[temp + 1].l + 1);

	tree[temp].add += tree[x].add;
	tree[temp + 1].add += tree[x].add;
	tree[x].add = 0;
}
void query(int l, int r, int L, int R, int x)
{
	if (L > r || R < l)
		return;
	if (L <= l && r <= R)
	{
		sum += tree[x].val;
		return;
	}
	if (tree[x].add)
		pushdown(x);
	int temp = x << 1;
	int mid = (l + r) >> 1;
	query(l, mid, L, R, temp);
	query(mid + 1, r, L, R, temp + 1);
}

void update(int l, int r, int L, int R, int c, int x)
{
	if (L > r || R < l)
		return;
	if (L <= l && r <= R)
	{
		tree[x].val += (r - l + 1)*c;
		tree[x].add += c;
		return;
	}
	if (tree[x].add)
		pushdown(x);
	int temp = x << 1;
	int mid = (l + r) >> 1;
	update(l, mid, L, R, c, temp);
	update(mid + 1, r, L, R, c, temp + 1);
	pushup(x);
}
int main()
{
	int n;
	int t;
	int ans = 0;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		printf("Case %d:\n", ++ans);
		built(1, n, 1);
		char ss[10];
		while (~scanf("%s", ss)) {
			if (ss[0] == 'E')break;
			else if (ss[0] == 'Q')
			{
				int L, R;
				scanf("%d%d", &L, &R);
				sum = 0;
				query(1, n, L, R, 1);
				printf("%d\n", sum);
			}
			else
			{
				int L, c;
				scanf("%d%d", &L, &c);
				if (ss[0] == 'S') {
					c = -c;
				}
				update(1, n, L, L, c, 1);
			}
		}
	}
	return 0;
}
///方
/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50010;
int a[maxn],ans;
struct node
{
    int val;
};
node TTree[maxn<<2];
void pushup(int index)
{
    int tmp=index<<1;
    TTree[index].val=TTree[tmp].val+TTree[tmp+1].val;
}
void build(int l,int r,int index)
{
    if(l==r)
    {
        scanf("%d",&TTree[index].val);
        //Tree[index].val=a[l];
        //Tree[index].val=a[index];
        //printf("%d ",TTree[index].val);
        return ;
    }
    int mid=(l+r)>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void query(int l,int r,int L,int R,int index)
{
    if(R<l||L>r)
        return ;
    if(L<=l&&r<=R)
    {
        ans+=TTree[index].val;
    }
    else
    {
        int mid=(l+r)>>1;
        int tmp=index<<1;
        query(l,mid,L,R,tmp);
        query(mid+1,r,L,R,tmp+1);
    }
}
void updata(int l,int r,int k,int index,int num)
{
    if(k>r||k<l)
        return ;
    if(l == r)
    {
        TTree[index].val += num;
        //scanf("%d",&TTree[index].val);
    }
    else
    {
        int mid=l+r>>1;
        int tmp=index<<1;
        updata(l,mid,k,tmp,num);
        updata(mid+1,r,k,tmp+1,num);
        pushup(index);
    }
}
int main()
{
    int t,cnt=1,n;
    scanf("%d",&t);
    for(int cnt=1; cnt<=t; cnt++)
    {
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",cnt);
        char str[10];
        while(scanf("%s",str))
        {
            if(str[0]=='E')
                break;
            int i,j;
            scanf("%d %d",&i,&j);
            if(str[0]=='Q')
            {
                ans=0;
                query(1,n,i,j,1);
                printf("%d\n",ans);
            }
            else if(str[0]=='A')
                updata(1,n,i,1,j);
            else
                updata(1,n,i,1,-j);
        }
    }
    return 0;
}
///B
/*5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5
*/
单点更新，求最大
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int ans;
struct node
{
    int val;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=max(Tree[temp].val,Tree[temp+1].val);
}
void build(int l,int r,int index)
{
    if(l==r)
    {
        scanf("%d",&Tree[index].val);
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void query(int l,int r,int L,int R,int index)
{
    if(l>R||r<L)
        return ;
    if(l>=L&&r<=R)
    {
        ans=max(ans,Tree[index].val);
    }
    else
    {
        int mid=l+r>>1;
        int temp=index<<1;
        query(l,mid,L,R,temp);
        query(mid+1,r,L,R,temp+1);
    }
}
void updata(int l,int r,int index,int k,int num)
{
    if(l>k||r<k)
        return ;
    if(l==r)
        Tree[index].val=num;
    else
    {
        int mid=l+r>>1;
        int temp=index<<1;
        updata(l,mid,temp,k,num);
        updata(mid+1,r,temp+1,k,num);
        pushup(index);
    }
}

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        scanf("%d",&m);
        build(1,n,1);
        while(m--)
        {
            char ch[5];
            int a,b;
            scanf("%s %d %d",ch,&a,&b);
            getchar();
            if(ch[0]=='Q')
            {
                ans=0;
                //printf("sssss");
                query(1,n,a,b,1);
                printf("%d\n",ans);
            }
            else
            {
                updata(1,n,1,a,b);
            }
        }
    }
    return 0;
}

///E
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int ans;
struct node
{
    int l,r;
    int val;
    int vis;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=Tree[temp].val+Tree[temp+1].val;
}
void build(int l,int r,int index)
{
    Tree[index].vis=0;
    Tree[index].val=1;
    Tree[index].l=l;
    Tree[index].r=r;
    if(l==r)
    {
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void pushdown(int index)
{
    int temp=index<<1;
    Tree[temp].val=Tree[index].vis*(Tree[temp].r-Tree[temp].l+1);
    Tree[temp+1].val=Tree[index].vis*(Tree[temp+1].r-Tree[temp+1].l+1);
    Tree[temp].vis=Tree[index].vis;
    Tree[temp+1].vis=Tree[index].vis;
    Tree[index].vis=0;
}
void updata(int l,int r,int L,int R,int num,int index)
{
    if(l>R||r<L)
        return ;
    if(L<=l&&r<=R)
    {
        Tree[index].val=(r-l+1)*num;
        Tree[index].vis=num;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    updata(l,mid,L,R,num,temp);
    updata(mid+1,r,L,R,num,temp+1);
    pushup(index);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        //ans=0;
        int n,m;
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            int a,b,k;
            scanf("%d %d %d",&a,&b,&k);
            updata(1,n,a,b,k,1);
        }
        //query(1,n,1,n,1);
        printf("Case %d: The total value of the hook is %d.\n",i,Tree[1].val);
    }
    return 0;
}
///M
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int ans=0;
struct node
{
    int val;
    int vis,l,r;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=Tree[temp].val+Tree[temp+1].val;
}
void build(int l,int r,int index)
{
    Tree[index].vis=0;
    Tree[index].l=l;
    Tree[index].r=r;
    Tree[index].val=0;
    if(l==r)
    {
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void pushdown(int index)
{
    int temp=index<<1;
    Tree[temp].val+=Tree[index].vis*(Tree[temp].r-Tree[temp].l+1);
    Tree[temp+1].val+=Tree[index].vis*(Tree[temp+1].r-Tree[temp+1].l+1);
    Tree[temp].vis+=Tree[index].vis;
    Tree[temp+1].vis+=Tree[index].vis;
    Tree[index].vis=0;
}
void updata(int l,int r,int L,int R,int index)
{
    if(l>R||r<L)
        return ;
    if(L<=l&&r<=R)
    {
        Tree[index].val+=(r-l+1);
        Tree[index].vis+=1;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    updata(l,mid,L,R,temp);
    updata(mid+1,r,L,R,temp+1);
    pushup(index);
}

void query(int l,int r,int num,int index)
{
    if(l>num||r<num)
        return ;
    if(l==num && r == num)
    {
        ans=Tree[index].vis;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    query(l,mid,num,temp);
    query(mid+1,r,num,temp+1);
}

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        build(1,n,1);
        int a,b;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a,&b);
            updata(1,n,a,b,1);
        }
        for(int i=1; i<=n; i++)
        {
            ans=0;
            query(1,n,i,1);
            if(i>1)
                printf(" ");
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}/*
///N
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long maxn=1e5+100;
long long ans;
struct node
{
    long long val;
    int l,r;
    long long vis;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=Tree[temp].val+Tree[temp+1].val;
}
void build(int l,int r,int index)
{
    Tree[index].vis=0;
    Tree[index].l=l;
    Tree[index].r=r;
    if(l==r)
    {
        scanf("%lld",&Tree[index].val);
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void pushdown(int index)
{
    int temp=index<<1;
    Tree[temp].val+=Tree[index].vis*(Tree[temp].r-Tree[temp].l+1);
    Tree[temp+1].val+=Tree[index].vis*(Tree[temp+1].r-Tree[temp+1].l+1);
    Tree[temp].vis+=Tree[index].vis;
    Tree[temp+1].vis+=Tree[index].vis;
    Tree[index].vis=0;
}
void updata(int l,int r,int L,int R,int num,int index)
{
    if(l>R||r<L)
        return ;
    if(L<=l&&r<=R)
    {
        Tree[index].val+=(r-l+1)*num;
        Tree[index].vis+=num;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    updata(l,mid,L,R,num,temp);
    updata(mid+1,r,L,R,num,temp+1);
    pushup(index);
}
void query(int l,int r,int L,int R,int index)
{
    if(l>R||r<L)
        return ;
    if(l>=L&&r<=R)
    {
        ans+=Tree[index].val;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    query(l,mid,L,R,temp);
    query(mid+1,r,L,R,temp+1);
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            char s[5];
            int a,b,k;
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d %d",&a,&b);
                ans=0;
                query(1,n,a,b,1);
                printf("%lld\n",ans);
            }
            else
            {
                scanf("%d %d %d",&a,&b,&k);
                updata(1,n,a,b,k,1);
            }
        }
    }
    return 0;
}
///I
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int ans1,ans2;
int flag;
struct node
{
    int val;
    int lef,rig;
};
node Tree[maxn<<2];

void pushup(int index)
{
    int temp=index<<1;
    Tree[index].lef=max(Tree[temp].lef,Tree[temp+1].lef);
    Tree[index].rig=min(Tree[temp].rig,Tree[temp+1].rig);
}
void build(int l,int r,int index)
{
    if(l==r)
    {
        scanf("%d",&Tree[index].val);
        Tree[index].lef=Tree[index].val;
        Tree[index].rig=Tree[index].val;
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}

void query(int l,int r,int L,int R,int index)
{
    if(l>R||r<L)
        return ;
    if(l>=L&&r<=R)
    {
        ans1=min(ans1,Tree[index].rig);
        ans2=max(ans2,Tree[index].lef);
        return ;
    }
    else
    {
        int mid=l+r>>1;
        int temp=index<<1;
        query(l,mid,L,R,temp);
        query(mid+1,r,L,R,temp+1);
    }
}

int main()
{
    int n,k,cnt=1;
    while(~scanf("%d %d",&n,&k))
    {
        flag=0;
        build(1,n,1);
        int s,m=n-k;
        for(int i=1; i<=m+1; i++)
        {
            s=i+k-1;
            ans1=99999999;
            query(1,n,i,s,1);
            printf("%d",ans1);
            if(i!=m+1)
                printf(" ");
        }
        printf("\n");
        for(int i=1; i<=m+1; i++)
        {
            s=i+k-1;
            ans2=-99999999;
            query(1,n,i,s,1);
            printf("%d",ans2);
            if(i!=m+1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
///D
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int ans;
struct node
{
    int l,r;
    int val;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=max(Tree[temp].val,Tree[temp+1].val);
}
void build(int l,int r,int index,int w)
{
    Tree[index].l=l;
    Tree[index].r=r;
    Tree[index].val=w;
    if(Tree[index].l==Tree[index].r)
        return ;
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp,w);
    build(mid+1,r,temp+1,w);
    pushup(index);
}

void query(int index,int a)
{
    if(Tree[index].l==Tree[index].r)
    {
        ans=Tree[index].l;
        Tree[index].val-=a;
        return ;
    }
    int temp=index<<1;
    if(a<=Tree[temp].val)
        query(temp,a);
    else
        query(temp+1,a);
    pushup(index);
}

int main()
{
    int h,w,n;
    while(~scanf("%d %d %d",&h,&w,&n))
    {
        int tmp;
        tmp=n<h?n:h;
        build(1,tmp,1,w);
        while(n--)
        {
            int a;
            scanf("%d",&a);
            if(Tree[1].val>=a)
            {
                ans=-1;
                query(1,a);
                printf("%d\n",ans);
            }
            else
                printf("-1\n");
        }
    }q
    return 0;
}

///C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5010;
int a[maxn];
struct node
{
    int l,r;
    int val;
} Tree[50000];
void build(int index,int x,int y)
{
    Tree[index].l=x;
    Tree[index].r=y;
    Tree[index].val=0;
    if(x==y)
        return ;
    int mid=(x+y)>>1;
    int temp=index<<1;
    build(temp,x,mid);
    build(temp+1,mid+1,y);
}
void updata(int index,int x)
{
    int l=Tree[index].l;
    int r=Tree[index].r;
    if(x==l&&x==r)
    {
        Tree[index].val=1;
        return ;
    }
    int mid=(l+r)>>1;
    int temp=index<<1;
    if(x<=mid)
        updata(temp,x);
    else
        updata(temp+1,x);
    Tree[index].val= Tree[temp].val+Tree[temp+1].val;
}
int query(int index,int x,int y)
{
    int l=Tree[index].l;
    int r=Tree[index].r;
    int mid=l+r>>1;
    int temp=index<<1;
    int ans=0;
    if(x==l&&y==r)
    {
         //printf("l=%d r=%d index=%d\n",l,r,index);
         return Tree[index].val;
    }

    if(x<=mid)
        ans+=query(temp,x,min(mid,y));
    if(y>mid)
        ans+=query(temp+1,max(mid+1,x),y);
    return ans;
}
int main()
{
    int n,temp1;
    while(~scanf("%d",&n))
    {
        build(1,0,n);
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            updata(1,a[i]);
            sum+=query(1,a[i]+1,n);
        }
        temp1=sum;
        for(int i=1; i<n; i++)
        {
            sum=sum+(n - 1 - a[i])-a[i];
            temp1=min(temp1,sum);
        }
        printf("%d\n",temp1);
    }
    return 0;
}
///K
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000010;
int n,m;
struct node
{
    int l,r,color;
    int cover;
} t[maxn<<2];

void push_up(int x)
{
    int temp=x<<1;
    t[x].color=t[temp].color|t[temp+1].color;
    printf("temp=%d t[temp].color=%d  t[temp+1].color=%d\n",temp,t[temp].color,t[temp+1].color);
    printf("x=%d  t[x].color=%d\n",x,t[x].color);
}

void push_down(int x)
{
    int temp=x<<1;
    t[temp].cover=t[x].cover;
    t[temp+1].cover=t[x].cover;
    t[x].cover=0;
    t[temp].color=t[x].color;
    t[temp+1].color=t[x].color;
}

void build(int l,int r,int x)
{
    t[x].l=l;
    t[x].r=r;
    t[x].cover=0;
    if(l==r)
    {
        t[x].color=2;
        t[x].cover=0;
        return ;
    }
    int mid=(l+r)>>1;
    int temp=x<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    push_up(x);
}

void updata(int x,int l,int r,int color)
{
    //完全覆盖
    if(t[x].l==l&&t[x].r==r)
    {
        t[x].color=color;
        t[x].cover=color;
        return ;
    }
    //下放懒标记
    if(t[x].cover)
        push_down(x);
    int mid=(t[x].l+t[x].r)>>1;
    int temp=x<<1;
    if(r<=mid)//更新左边
        updata(temp,l,r,color);
    else if(l>mid)//更新右边
        updata(temp+1,l,r,color);
    else
    {
        updata(temp,l,mid,color);
        updata(temp+1,mid+1,r,color);
    }
    push_up(x);
}

int Query(int x,int l,int r)
{
    if(l==t[x].l&&t[x].r==r)
    {
        return t[x].color;
    }
    if(t[x].cover)
        push_down(x);
    int mid=(t[x].l+t[x].r)>>1;
    int temp=x<<1;
    if(r<=mid)
    {
        return Query(temp,l,r);
    }
    else if(l>mid)///要查询的区间不被当前区间完全包括，被分成了当前区间的左右孩子
    {
        return Query(temp+1,l,r);
    }
    else
    {
        return Query(temp,l,mid)|Query(temp+1,mid+1,r);
    }
}

int main()
{
    int from,to,color;
    int a[35];
    while(~scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        build(1,n,1);
        char s[2];
        for(int i=1; i<=m; i++)
        {
            scanf("%s",s);
            if(s[0]=='P')
            {
                scanf("%d %d %d",&from,&to,&color);
                updata(1,from,to,(1<<(color-1)));///1在哪个位置上表明有几种颜色
            }
            else
            {
                scanf("%d %d",&from,&to);
                int ans=Query(1,from,to);
                int k=0;
                for(int j=0; j<30; j++)
                {
                    if(ans&(1<<j))
                        a[k++]=j+1;
                }
                for(int i=0; i<k; i++)
                {
                    if(i!=0)
                        printf(" ");
                    printf("%d",a[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int ans=0;
struct node
{
    int val;
    int vis,l,r;
};
node Tree[maxn<<2];
void pushup(int index)
{
    int temp=index<<1;
    Tree[index].val=Tree[temp].val+Tree[temp+1].val;
}
void build(int l,int r,int index)
{
    Tree[index].vis=0;
    Tree[index].l=l;
    Tree[index].r=r;
    if(l==r)
    {
        scanf("%d",&Tree[index].val);
        return ;
    }
    int mid=l+r>>1;
    int temp=index<<1;
    build(l,mid,temp);
    build(mid+1,r,temp+1);
    pushup(index);
}
void pushdown(int index)
{
    int temp=index<<1;
    Tree[temp].val=Tree[index].vis*(Tree[temp].r-Tree[temp].l+1);
    Tree[temp+1].val=Tree[index].vis*(Tree[temp+1].r-Tree[temp+1].l+1);
    Tree[temp].vis=Tree[index].vis;
    Tree[temp+1].vis=Tree[index].vis;
    Tree[index].vis=0;
}
/*void pushdown(int index)
{
    int temp=index<<1;
    Tree[temp].val+=Tree[index].vis*(Tree[temp].r-Tree[temp].l+1);
    Tree[temp+1].val+=Tree[index].vis*(Tree[temp+1].r-Tree[temp+1].l+1);
    Tree[temp].vis+=Tree[index].vis;
    Tree[temp+1].vis+=Tree[index].vis;
    Tree[index].vis=0;
}*/
void updata(int l,int r,int k,int num,int index)
{
    if(l>k||r<k)
        return ;
    if(l==r)
    {
        Tree[index].val=num;
        Tree[index].vis+=1;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    updata(l,mid,k,num,temp);
    updata(mid+1,r,k,num,temp+1);
    pushup(index);
}

void query(int l,int r,int num,int index)
{
    if(l>num||r<num)
        return ;
    if(l==num && r == num)
    {
        ans=Tree[index].val;
        return ;
    }
    if(Tree[index].vis)
        pushdown(index);
    int mid=l+r>>1;
    int temp=index<<1;
    query(l,mid,num,temp);
    query(mid+1,r,num,temp+1);
}

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        build(1,n,1);
        int a,b;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a,&b);
            updata(1,n,a,b,1);
        }
        for(int i=1; i<=n; i++)
        {
            ans=0;
            query(1,n,i,1);
            if(i>1)
                printf(" ");
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}
