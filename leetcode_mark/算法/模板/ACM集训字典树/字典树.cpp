#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
///C
const int maxn=1e6+10;
int cur;
struct node
{
    int data[27];
    int num;
    void init()
    {
        for(int i=0; i<27; i++)
        {
            data[i]=-1;
        }
        num=0;
    }
} T[maxn];
void CreatTree(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
        }
        p=T[p].data[x];
        printf("%d\n",p);
        T[p].num++;
    }
}
int Query(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        if(T[p].data[x]==-1)
            return 0;
        p=T[p].data[x];
    }
    return T[p].num;
}
int main()
{
    T[0].init();
    char str[15];
    cur=1;
    while(gets(str)&&str[0]!='\0')
    {
        int len=strlen(str);
        CreatTree(str,len);
    }
    while(gets(str)!=NULL)
    {
        int len1=strlen(str);
        int ans=Query(str,len1);
        printf("%d\n",ans);
    }
    return 0;
}/*
///D
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6+10;
int cur,cnt;
char str1[20];
struct Tree
{
    int data[27];
    int num;
    void init()
    {
        for(int i=0; i<27; i++)
            data[i]=-1;
        num=0;
    }
} T[maxn];
void Creat(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';//1
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;///这个表示编号为P的第x个孩子的编号为cur
        }
        p=T[p].data[x];///T=T->next
        T[p].num++;
        //printf("%d\n",T[p].num);
    }
    if(T[p].num>cnt)
    {
        cnt=T[p].num;
        //printf("%d ",cnt);
        strcpy(str1,s);
    }
    //printf("\n");
}
int main()
{
    T[0].init();
    cur=1;
    int n;
    char str[20];
    while(~scanf("%d",&n)&&n)
    {
        cnt=-99;
        for(int i=0; i<n; i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            Creat(str,len);
        }
        printf("%s\n",str1);
    }
    return 0;
}
///A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=400010;
int cur,n,cnt,flag,sum;
struct Tree
{
    int data[15];
    int num,sign;
    void init()
    {
        for(int i=0; i<15; i++)
            data[i]=-1;
        num=0;
        sign=0;
    }
} T[maxn];
void CreatTree(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'0';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
        }
        p=T[p].data[x];
        T[p].num++;
        if(T[p].sign==1)
            flag=1;
        if(T[p].num>1&&i==len-1)
            flag=1;
    }
    if(T[p].sign==0)
        T[p].sign=1;
}
int main()
{
    int t;
    char str[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        T[0].init();
        cur=1,flag=0,sum=1;
        for(int i=0; i<n; i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            CreatTree(str,len);
            sum++;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e6;
char ans[15];
int cur;
struct Tree
{
    char S[15];
    int data[27];
    int num;
    void init()
    {
        for(int i=0; i<27; i++)
            data[i]=-1;
        num=0;
        strcpy(S,"eh");
    }
}T[maxn];
void CreatTree(char *s,char *str)
{
    int p=0;
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int x=str[i]-'a';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
            // strcpy(T[p].S,"eh");
        }
        p=T[p].data[x];
        T[p].num++;
    }
    strcpy(T[p].S,s);
}
void Query(char *s)
{
    int p=0;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        if(T[p].data[x]==-1)
        {
            strcpy(ans,"eh");
            break;
        }
        p=T[p].data[x];
    }
    strcpy(ans,T[p].S);
}
int main()
{
    char s1[15],s2[15],s3[15];
    int flag=0;
    cur=1;
    T[0].init();
    while(gets(s1)!=NULL&&s1[0]!='\0')
    {
        sscanf(s1,"%s %s", s2, s3);
        int len=strlen(s1);
        CreatTree(s2,s3);
    }
    while(gets(s1)!=NULL)
    {
        Query(s1);
        printf("%s\n",ans);
    }
    return 0;
}
///F
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=400010;
int cur,n,cnt,flag,sum;
struct TrieNode
{
    TrieNode *next[15];
    int ans,sign;
    TrieNode()
    {
        //flag = false;
        ans = 0;
        sign=0;
        for(int i = 0; i < 15; i ++)
            next[i] = NULL;
    }
}*head;
void Bulid(char *s)
{
    TrieNode *p = head;
    int len=strlen(s);
    for(int i = 0; s[i]; i ++)
    {
        int index = s[i] - '0';
        if(!p -> next[index])
            p -> next[index] = new TrieNode;
        p = p -> next[index];
        p -> ans++;
        //printf("ssss");
        if(p->sign==1)
            flag=1;
        else if(p->ans>1&&i==len-1)
            flag=1;
    }
    if(p->sign==0)
        p->sign=1;
    // p -> flag = true;
}
int SearchTrie(char *s)
{
    TrieNode *p = head;
    for(int i = 0; s[i]; i ++)
    {
        int index = s[i] - 'a';
        if(!p -> next[index])
        {
            // puts("False");
            return 0;
        }
        p = p -> next[index];
    }
    // puts("True");
    return p -> ans;
}
void DeleteTrie(TrieNode *head)
{
    TrieNode *p = head;
    for(int i = 0;  i < 15; i ++)
        if(p -> next[i] != NULL)
            DeleteTrie(p -> next[i]);
    delete p;
}
int main()
{
    int t;
    char str[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cur=1,flag=0,sum=1;
        head = new TrieNode;
        for(int i=0; i<n; i++)
        {
            scanf("%s",str);
            Bulid(str);

        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
        DeleteTrie(head);
    }
    return 0;
}
///H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=30010;
int cur,pos;
char s[1010][25];
struct node
{
    int data[27];
    int num;
    void init()
    {
        for(int i=0; i<27; i++)
        {
            data[i]=-1;
        }
        num=0;
    }
}T[maxn];
void CreatTree(char *s1,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s1[i]-'a';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
        }
        p=T[p].data[x];
        T[p].num++;
    }
    //printf("%d\n",T[p].num);
}
int Query(char *s1,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s1[i]-'a';
        if(T[p].data[x]==-1)
            return 0;
        p=T[p].data[x];
        if(T[p].num==1)
        {
            pos=i;
            break;
        }
    }
    return T[p].num;
}
int main()
{
    pos=1;;
    int k=0;
    while(~scanf("%s",s[k]))
    {
        k++;
    }
    cur=1;
    T[0].init();
    for(int i=0; i<k; i++)
    {
        int len=strlen(s[i]);
        CreatTree(s[i],len);
    }
    for(int i=0; i<k; i++)
    {
        printf("%s ",s[i]);
        int len1=strlen(s[i]);
        int ans=Query(s[i],len1);
        //printf("%d\n",ans);
        if(ans==1)
        {
            for(int j=0;j<=pos;j++)
                printf("%c",s[i][j]);
        }
        else
            printf("%s",s[i]);
        printf("\n");
    }
    return 0;
}
///E
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10010000;
int cur,k;
struct Tree
{
    char S[15];
    int data[27];
    int num,sign;
    void init()
    {
        for(int i=0; i<27; i++)
            data[i]=-1;
        num=0;
        sign=0;
    }
}T[maxn];
void CreatTree(char *s,char *str)
{
    int p=0;
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int x=str[i]-'a';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
        }
        p=T[p].data[x];
        T[p].num++;
    }
    strcpy(T[p].S,s);
    if(T[p].sign==0)
        T[p].sign=1;
}
void Query(char *s)
{
    int p=0;
    int len=strlen(s);
    //printf("%s333",s);
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        if(T[p].data[x]==-1)
        {
            if(i==len-1)
            {
                printf("%s",s);
                return ;
            }
        }
        p=T[p].data[x];
    }
    if(T[p].sign==0)
        printf("%s",s);
    else
        printf("%s",T[p].S);
}
int main()
{
    char s1[15],s2[15],s3[15],s4[3010];
    int flag=0;
    cur=1;
    T[0].init();
    scanf("%s",s1);
    while(~scanf("%s",s1))
    {
        if(!strcmp(s1,"END"))
            break;
        scanf("%s",s2);
        CreatTree(s1,s2);
    }
    scanf("%s",s1);
    getchar();
    while(gets(s4))
    {
        if(!strcmp(s4,"END"))
            break;
        k=0;
        char ans[3010]= {0};
        for(int i=0; s4[i]; i++)
        {
            if(s4[i]>='a'&&s4[i]<='z')
            {
                ans[k++]=s4[i];
            }
            else
            {
                ans[k]='\0';
                if(ans[0]!='\0')
                {
                    Query(ans);
                    ans[0]='\0',k=0;
                }
                printf("%c",s4[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
///J
#include <cstring>
#include <cstdio>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=50010;
int f[50010][30],d[50010][30];
int a[maxn];
void ST(int n)///预处理
{
    for(int i=1; i<=n; i++)
    {
        f[i][0]=a[i];
        d[i][0]=a[i];
    }
    for(int j=1; (1<<j)<=n; j++) ///枚举区间长度
    {
        for(int i=1; i+(1<<j)-1<=n; i++) ///枚举起点
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int l,int r)
{
    int k=trunc(log2( r-l+1 ));///向下取整
    return max(  f[l][k],  f[r-(1<<k)+1][k]   );
}
int RMQl(int l,int r)
{
    int k=trunc(log2( r-l+1 ));///向下取整
    return min(  d[l][k],  d[r-(1<<k)+1][k]   );
}
int main()
{
    int n,r,l,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    ST(n);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",RMQ(l,r)-RMQl(l,r));
    }
    return 0;
}
///N
#include <cstring>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6;
int a[maxn];
int b[maxn];
int f[200100][30];
void ST(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]!=a[i-1]||i==1)
            f[i][0]=1;
        else
            f[i][0]=f[i-1][0]+1;
    }
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
    int k=trunc(log2(r-l+1));///向下取整
    //printf("k=%d\n",k);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
    int n,q,l,r;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        ST(n);
        int temp=n;
        for(int i=temp; i>=1; i--)
        {
            if(a[temp]!=a[i])
            {
                temp=i;
                b[i]=temp;
            }
            else
                b[i]=temp;
            // printf("%d ",b[i]);
        }
        int ans=0;
        for(int i=1; i<=q; i++)
        {
            scanf("%d %d",&l,&r);
            if(a[l]==a[r])
                ans=r-l+1;
            else if(a[l]==a[l-1]&&l>1)
            {
                ans=max(b[l]-l+1,RMQ(b[l]+1,r));
                //printf("%d %d\n",b[l]-l+1,RMQ(b[l]+1,r));
            }
            else
                ans=RMQ(l,r);
            printf("%d\n",ans);
        }

    }
    return 0;
}
///K
#include <cstring>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
const int maxn=1e4+10;
int deep[maxn];       ///存深度
vector<int>G[maxn];  ///存节点
int vis[maxn] ;       ///dfs求深度时候的标记
int f[maxn][20];     ///预处理的倍增数组
void ST(int n)
{
    for(int j=1; j<20; j++)
        for(int i=1; i<=n; i++)
            f[i][j]=f[ f[i][j-1] ][j-1];
}
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        G[i].clear();
        f[i][0]=0;
    }
    memset(vis,0,sizeof(vis));
}
void DFS(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            deep[v]=deep[u]+1;
            DFS(v);
        }
    }
}

int LCA(int u,int v)
{
    if(deep[u]<deep[v])///默认u的深度大一点简化后面的问题
        swap(u,v);
    int h=deep[u]-deep[v];///求出高度差
    for(int i=0; i<20; i++)
    {
        if(h&(1<<i))///二级制位上存在1就提升 1<<i步
        {
            u=f[u][i];
        }
    }
    if(u==v)///如果u==v表示 u就是v下面的分支节点
        return u;
    for(int i=19; i>=0; i--) ///找到第一个不相同的节点
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];///第一个不相同的节点的上一个就是最近公共祖先
}

int main()
{
    int t,n,a,b,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init(n);
        for(int i=1; i<=n-1; i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            f[b][0]=a;
        }
        int root;
        for(int i=1; i<=n; i++)
        {
            if(f[i][0]==0)
            {
                root=i;
                deep[root]=1;
                vis[root]=1;
                break;
            }
        }
        DFS(root);
        ST(n);
        scanf("%d %d",&u,&v);
        int ans=LCA(u,v);
        printf("%d\n",ans);
    }
    return 0;
}
///O
#include <cstring>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
const int maxn=40100;
int f[maxn][20],dis[maxn],vis[maxn],deep[maxn];
struct node
{
    int to,step;
} s,w;
vector<node>G[maxn];
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        G[i].clear();
        dis[i]=0;
        vis[i]=0;
        deep[i]=0;
        f[i][0]=0;
    }
}
void ST(int n)
{
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i<=n; i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
void dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i].to;
        if(!vis[v])
        {
            vis[v]=1;
            dis[v]=dis[u]+G[u][i].step;
            deep[v]=deep[u]+1;
            f[v][0]=u;
            dfs(v);
        }
    }
}
int LCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);
    int h=deep[u]-deep[v];
    for(int i=0; i<20; i++)
    {
        if(h&(1<<i))///h&(1<<i)的值若存在1就进行倍增；
        {
            u=f[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=19; i>=0; i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
int main()
{
    int t,n,m,a,b,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        for(int i=1; i<n; i++)
        {
            scanf("%d %d %d",&a,&b,&k);
            s.to=b;
            s.step=k;
            w.to=a;
            w.step=k;
            G[a].push_back(s);
            G[b].push_back(w);
        }
        deep[1]=1;
        dis[1]=0;
        vis[1]=1;
        dfs(1);
        ST(n);
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            int ans=LCA(a,b);
            printf("%d\n",dis[b]+dis[a]-2*dis[ans]);
        }
    }
    return 0;
}
///G
#include <cstring>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
int f[1010][20];
char s[1010];
char ans[1010];
int Min(int x,int y)
{
    return s[x] <= s[y] ? x : y;
}

void init(int len)
{
    for(int i=0; i<=len; i++)
        f[i][0]=i;
    for(int j=1; (1<<j)<=len; j++)
        for(int i=0; i+(1<<j)-1<len; i++)
            f[i][j]=Min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
    int k=trunc(log2(r-l+1));
    return Min(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
    int m;
    while(~scanf("%s %d",s,&m))
    {
        int len=strlen(s);
        init(len);
        int temp=len-m;
        int pos=0,cnt=0;
        for(int i=0; i<temp; i++)
        {
            pos=RMQ(pos,m);
            ans[cnt++]=s[pos++];
            m++;
        }
        ans[cnt]='\0';
        int i;
        for(i=0; i<cnt; i++)
        {
            if(ans[i]!='0')
                break;
        }
        if(i==cnt)
            printf("0\n");
        else
        {
            for(int j=i;j<cnt;j++)
                printf("%c",ans[j]);
            printf("\n");
        }
    }
    return 0;
}
///L
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=80050;
int f[maxn][30],vis[maxn],dis[maxn],deep[maxn];
struct node
{
    int to,step;
} s,w;
vector<node>g[maxn];
void init(int n)
{
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    memset(deep,0,sizeof(deep));
    memset(dis,0,sizeof(dis));
    for(int i=0; i<=n; i++)
        g[i].clear();
}
void ST(int n)
{
    for(int j=1; j<30; j++)
        for(int i=1; i<=n; i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
void dfs(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].to;
        if(!vis[v])
        {
            vis[v]=1;
            deep[v]=deep[u]+1;
            dis[v]=dis[u]+g[u][i].step;
            f[v][0]=u;
            dfs(v);
        }
    }
}
int LCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);
    int h=deep[u]-deep[v];
    for(int i=0;i<30;i++)
    {
        if(h&(1<<i))
        {
            u=f[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=29;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        init(n);
        char s1[10];
        int a,b,d;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d %s",&a,&b,&d,s1);
            s.to=b;
            s.step=d;
            w.to=a;
            w.step=d;
            g[a].push_back(s);
            g[b].push_back(w);
        }
        dis[1]=0;
        vis[1]=1;
        deep[1]=1;
        dfs(1);
        ST(n);
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&a,&b);
            int ans=LCA(a,b);
            printf("%d\n",dis[a]+dis[b]-2*dis[ans]);
        }
    }
    return 0;
}
///M
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=10010;
int f[maxn][30],vis[maxn],dis[maxn],deep[maxn],fa[maxn];
struct node
{
    int to,step;
} s,w;
vector<node >g[maxn];
void init(int n)
{
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    memset(deep,0,sizeof(deep));
    memset(dis,0,sizeof(dis));
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
        fa[i]=i;
    }

}
void ST(int n)
{
    for(int j=1; j<30; j++)
        for(int i=1; i<=n; i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
void dfs(int u)
{
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i].to;
        if(!vis[v])
        {
            vis[v]=1;
            deep[v]=deep[u]+1;
            dis[v]=dis[u]+g[u][i].step;
            f[v][0]=u;
            dfs(v);
        }
    }
}
int LCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);
    int h=deep[u]-deep[v];
    for(int i=0; i<30; i++)
    {
        if(h&(1<<i))
        {
            u=f[u][i];
        }
    }
    if(u==v)
        return u;
    for(int i=29; i>=0; i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
void mix(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        fa[yy]=xx;
    }
}
int main()
{
    int n,m,c;
    while(~scanf("%d %d %d",&n,&m,&c))
    {
        init(n);
        int a,b,k;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&a,&b,&k);
            mix(a,b);
            s.to=b,s.step=k;
            w.to=a,w.step=k;
            g[a].push_back(s);
            g[b].push_back(w);
        }
        for(int i=1; i<=n; i++)
        {
            if(fa[i]==i)
            {

                vis[i]=1;
                dis[i]=0;
                deep[i]=1;
                dfs(i);
            }
        }
        ST(n);
        for(int i=0; i<c; i++)
        {
            scanf("%d %d",&a,&b);
            if(Find(a)!=Find(b))
                printf("Not connected\n");
            else
            {
                int ans=LCA(a,b);
                printf("%d\n",dis[a]+dis[b]-2*dis[ans]);
            }
        }
    }
    return 0;
}*/
