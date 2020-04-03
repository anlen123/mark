///POJ 1321
/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char mapp[10][10];
int vis[10];
int cnt;
int n,k;
void dfs(int lie,int c)
{
    if(c==k)
    {
        cnt++;
        return ;
    }
    if(lie>=n)
        return ;
    for(int i=0;i<n;i++)
    {
        if(mapp[lie][i]=='#'&&!vis[i])
        {
            vis[i]=1;
            dfs(lie+1,c+1);
            vis[i]=0;
        }
    }
    dfs(lie+1,c);
}
int main()
{
    while(~scanf("%d %d",&n,&k)&&n!=-1&&k!=-1)
    {
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%s",mapp[i]);
        dfs(0,0);
        printf("%d\n",cnt);
    }
    return 0;
}
///POJ 1664
#include <stdio.h>
#include <stdlib.h>
int t,M,N;
int f(int m,int n)
{
    if(n==1||m==0)
        return 1;
    if(n>m)
        return f(m,m);
    else
    {
        return f(m,n-1)+f(m-n,n);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans;
        scanf("%d%d",&M,&N);
        ans=f(M,N);
        printf("%d\n",ans);

    }
    return 0;
}
///POJ 1915
#include <stdio.h>
#include <stdlib.h>
int T,L;
int sx,sy,ex,ey;
int xx[8]= {-2,-2,-1,-1,1,1,2,2};
int yy[8]= {-1,1,-2,2,-2,2,-1,1};
int map[400][400];
struct node
{
    int x,y;
    int step;
} q[400*400],s,e,v;
int check(int x,int y)
{
    if(x>=0&&x<L&&y>=0&&y<L&&map[x][y]!=1)
        return 1;
    return 0;

}
int bfs()
{
    int r=0,l=0;
    s.x=sx;
    s.y=sy;
    s.step=0;
    q[r++]=s;
    map[s.x][s.y]=1;
    while(l<r)
    {
        e=q[l++];
        if(e.x==ex&&e.y==ey)
            return e.step;
        int i;
        for(i=0; i<8; i++)
        {
            int X=e.x+xx[i];
            int Y=e.y+yy[i];
            if(check(X,Y))
            {
                map[X][Y]=1;
                v.x=X;
                v.y=Y;
                v.step=e.step+1;
                q[r++]=v;
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int ans;
        scanf("%d",&L);
        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&ex,&ey);
        if(sx==ex&&sy==ey)
        {
            printf("0\n");
        }
        else
        {
            memset(map,0,sizeof(map));
            ans=bfs();
            printf("%d\n",ans);
        }
    }
    return 0;
}
///POJ 2183
#include <stdio.h>
#include <stdlib.h>
int vis[10000];
int k;
int fun(int x)
{
    int temp,i;
    temp=x%100000/10;
    temp=(temp*temp)%1000000;
    k++;
    for(i=1; i<k; i++)
        if(temp==vis[i])
             return i;
    vis[k] = temp;
    fun(temp);
}
int main()
{
    int n,count=0;
    k=0;
    scanf("%d",&n);
    int ans=fun(n);
    printf("%d %d %d\n", vis[ans], k-ans, k);
    return 0;
}
POJ 1562
#include <stdio.h>
#include <stdlib.h>
int m,n;
int x1[8]={-1,-1,-1,0,0,1,1,1};
int y1[8]={-1,0,1,-1,1,-1,0,1};
char map[1000][1000];
int check(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n&&map[x][y]=='@')
        return 1;
    else
        return 0;
}
int dfs(int x,int y)
{
    int i;
    map[x][y]='*';
    for(i=0;i<8;i++)
    {
        int X=x+x1[i];
        int Y=y+y1[i];
        if(check(X,Y))
        {
            dfs(X,Y);
        }
    }

}
int main()
{
    int i,j,count;
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        count=0;
        for(i=0;i<m;i++)
            scanf("%s",&map[i]);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(map[i][j]=='@')
                {
                    dfs(i,j);
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
///POJ 1979
#include <stdio.h>
#include <stdlib.h>
int W,H,count;
char map[21][21];
int xx[4]= {-1,0,0,1};
int yy[4]= {0,-1,1,0};
int vis[100][100];
int check(int x,int y)
{
    if(x>=0&&x<H&&y>=0&&y<W&&map[x][y]=='.')
        return 1;
    return 0;
}
int dfs(int x,int y)
{
    int i;
    map[x][y]='#';
    vis[x][y]=1;
    if(vis[x][y]=1)
    {
        count++;
    }
    for(i=0; i<4; i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(check(X,Y)&&vis[X][Y]!=1)
        {

            dfs(X,Y);
        }
    }
    return count;
}
int main()
{
    while(~scanf("%d%d",&W,&H)&&W!=0&&H!=0)
    {
        int i,j;
        for(i=0; i<H; i++)
            scanf("%s",map[i]);
        int ans;
        count=0;
        memset(vis,0,sizeof(vis));
        for(i=0; i<H; i++)
        {
            for(j=0; j<W; j++)
            {
                if(map[i][j]=='@')
                {
                    ans=dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
///POJ 2676
#include <stdio.h>
#include <stdlib.h>
int flag;
int map[10][10];
int hang[10][10];
int lie[10][10];
int qu[10][10];
void dfs(int x,int y)
{
    int i,j,k;
    if(flag)
        return ;
    if(x==9&&y==0)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                printf("%d",map[i][j]);
            }
            printf("\n");
        }
        flag=1;
        return ;
    }
    if(map[x][y]!=0)
    {
        if(y>7)
            dfs(x+1,0);
        else
            dfs(x,y+1);
    }
    for(k=1; k<=9; k++)
    {
        int K=(x/3)*3+y/3;
        if(!hang[x][k]&&!lie[y][k]&&!qu[K][k]&&!map[x][y])
        {
            map[x][y]=k;
            hang[x][k]=1;
            lie[y][k]=1;
            qu[K][k]=1;
            if(y>7)
                dfs(x+1,0);
            else
                dfs(x,y+1);
            map[x][y]=0;
            hang[x][k]=0;
            lie[y][k]=0;
            qu[K][k]=0;
        }
    }
}
int main()
{
    int i,j,k;

    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(hang));
        memset(qu,0,sizeof(qu));
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                scanf("%1d",&map[i][j]);
                if(map[i][j])
                {
                    k=(i/3)*3+j/3;
                    hang[i][map[i][j]]=1;
                    lie[j][map[i][j]]=1;
                    qu[k][map[i][j]]=1;
                }
            }
        }
        flag=0;
        dfs(0,0);
    }
    return 0;
}
///HDU 2553
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N,n;
int map[20];
int vis[100];
int count;
int check(int hang)
{
    int i;
    for(i=1; i<hang; i++)
    {
        if(map[i]==map[hang]||abs(i-hang)==abs(map[i]-map[hang]))
            return 0;
    }
    return 1;
}
void dfs(int hang)
{
    int j;
    if(hang>n)
        count++;
    for(j=1; j<=n; j++)
    {
        map[hang]=j;
        if(check(hang))
        {
            dfs(hang+1);
        }
    }
}
void count1(int n)
{
    dfs(1);
}
int main()
{
    memset(vis,0,sizeof(vis));
    for(n=1;n<=10;n++)
    {
        count=0;
        count1(n);
        vis[n]=count;
    }
    while(~scanf("%d",&N)&&N!=0)
    {
        printf("%d\n",vis[N]);
    }
    return 0;
}
///HDU 1010
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int sx,sy,ex,ey;
int n,m,t;
char a[10][10];
int xx[4]= {-1,0,0,1};
int yy[4]= {0,1,-1,0};
int flag;
int check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!='X')
        return 1;
    return 0;
}
void dfs(int x,int y,int step)
{
    if(step>t||flag==1)
        return ;
    if((abs(x-ex)+abs(y-ey))%2!=(t-step)%2)
    {
        return ;
    }
    if(x==ex&&y==ey&&step==t)
    {
        flag=1;
        return ;
    }
    int i;
    a[x][y]='X';
    for(i=0; i<4; i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(check(X,Y))
        {
            dfs(X,Y,step+1);
            a[X][Y]='.';
        }
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&t)&&n!=0&&m!=0&&t!=0)
    {
        int i,j,count=0;
        flag=0;
        for(i=0; i<n; i++)
            scanf("%s",&a[i]);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]=='S')
                {
                    sx=i;
                    sy=j;

                }
                if(a[i][j]=='D')
                {
                    ex=i;
                    ey=j;
                }
                if(a[i][j]=='X')
                    count++;
            }
        }
        if(n*m-count<t)
            printf("NO\n");
        else
        {
            dfs(sx,sy,0);
            if(flag==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
///HDU 1198
#include <stdio.h>
#include <stdlib.h>
int A[]= {0,1,0,1,1,0,0,0,0};
int B[]= {0,1,0,0,1,1,0,0,0};
int C[]= {0,0,0,1,1,0,0,1,0};
int D[]= {0,0,0,0,1,1,0,1,0};
int E[]= {0,1,0,0,1,0,0,1,0};
int F[]= {0,0,0,1,1,1,0,0,0};
int G[]= {0,1,0,1,1,1,0,0,0};
int H[]= {0,1,0,1,1,0,0,1,0};
int I[]= {0,0,0,1,1,1,0,1,0};
int J[]= {0,1,0,0,1,1,0,1,0};
int K[]= {0,1,0,1,1,1,0,1,0};
int map[200][200];
int M,N;
int xx[8]= {-1,-1,-1,0,0,1,1,1};
int yy[8]= {-1,0,1,-1,1,-1,0,1};
char mapp[52][52];
void hand(int i,int j,char X)
{
    int i1,j1;
    int count=0;
    for(i1=i*3; i1<i*3+3; i1++)
    {
        for(j1=j*3 ; j1<j*3+3 ; j1++)
        {
            if(X=='A')
                map[i1][j1]=A[count++];
            if(X=='B')
                map[i1][j1]=B[count++];
            if(X=='C')
                map[i1][j1]=C[count++];
            if(X=='D')
                map[i1][j1]=D[count++];
            if(X=='E')
                map[i1][j1]=E[count++];
            if(X=='F')
                map[i1][j1]=F[count++];
            if(X=='G')
                map[i1][j1]=G[count++];
            if(X=='H')
                map[i1][j1]=H[count++];
            if(X=='I')
                map[i1][j1]=I[count++];
            if(X=='J')
                map[i1][j1]=J[count++];
            if(X=='K')
                map[i1][j1]=K[count++];
        }
    }
}
void dfs(int x,int y)
{
    int i;
    map[x][y]=0;
    for(i=0;i<8;i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(check(X,Y))
        {
            dfs(X,Y);
        }
    }
}
int check(int x,int y)
{
    if(x>=0&&x<3*M&&y>=0&&y<3*N&&map[x][y])
        return 1;
    return 0;
}
int main()
{
    char ch[100];
    while(~scanf("%d%d",&M,&N)&&M!=-1&&N!=-1)
    {
        int i,j,num=0;
        memset(map,0,sizeof(map));
        for(i=0; i<M; i++)
            scanf("%s",mapp[i]);
        for(i=0; i<M; i++)
        {
            for(j=0; j<N; j++)
            {
                hand(i,j,mapp[i][j]);
            }
        }
        for(i=0;i<3*M;i++)
        {
            for(j=0;j<3*N;j++)
            {
                if(map[i][j]==1)
                {
                    dfs(i,j);
                    num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
///HDU 1242(сеох╤сап)
#include <queue>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int N,M;
int sx,sy;
char mapp[220][220];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int vis[220][220];
struct node
{
    int x,y,step;
    friend bool operator<(node n1,node n2)
    {
        return n1.step>n2.step;
    }
};
int check(int x,int y)
{
    if(x>=0 and x<N and y>=0 and y<M and mapp[x][y]!='#' and vis[x][y]==0)
        return 1;
    return 0;
}
int bfs()
{
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    priority_queue<node> q;
    node s,v,e;
    s.x=sx;
    s.y=sy;
    s.step=0;
    q.push(s);
    while(!q.empty())
    {
        e=q.top();
        q.pop();
        if(mapp[e.x][e.y]=='r')
            return e.step;
        for(int i=0; i<4; i++)
        {
            v.x=e.x+xx[i];
            v.y=e.y+yy[i];
            if(check(v.x,v.y))
            {
                vis[v.x][v.y]=1;
                if(mapp[v.x][v.y]=='x')
                {
                    v.step=e.step+2;
                }
                else
                {
                    v.step=e.step+1;
                }
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>N>>M)
    {
        int i,j;
        for(i=0; i<N; i++)
            cin>>mapp[i];
        for(i=0; i<N; i++)
        {
            for(j=0; j<M; j++)
            {
                if(mapp[i][j]=='a')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        int ans=bfs();
        if(!ans)
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        else
            cout<<ans<<endl;
    }
}
///POJ 2488
#include <stdio.h>
#include <stdlib.h>
int map[100][2];
int vis[50][50];
int xx[8]= {-2,-2,-1,-1,1,1,2,2};
int yy[8]= {-1,1,-2,2,-2,2,-1,1};
int n,p,q,flag;
int check(int x,int y)
{
    if(x>=0&&x<q&&y>=0&&y<p&&vis[x][y]==0&&!flag)
        return 1;
    return 0;
}
void dfs(int x,int y,int step)
{
    int i;
    if(step==p*q)
    {
        flag=1;
        for(i=0; i<step; i++)
        {
            printf("%c%d",map[i][0]+'A',map[i][1]+1);
        }
        printf("\n");
    }
    for(i=0; i<8; i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(check(X,Y))
        {
            vis[X][Y]=1;
            map[step][0]=X;
            map[step][1]=Y;
            dfs(X,Y,step+1);
            vis[X][Y]=0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    int count=0,i;
    while(n--)
    {
        scanf("%d%d",&p,&q);
        count++;
        printf("Scenario #%d:\n",count);
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        flag=0;
        vis[0][0]=1;
        dfs(0,0,1);
        if(!flag)
            printf("impossible\n");
        printf("\n");
    }
    return 0;
}
///全排列（基础） oj 2144
#include <stdio.h>
#include <string.h>
int n;
int a[10];
int vis[10]={0};
void dfs(int step)
{
    int i;
    if(step==n+1)
    {
        for(i=1;i<=n;i++)
        {
            printf("%d%c",a[i],i==n?'\n':' ');
        }
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            a[step]=i;
            vis[i]=1;
            dfs(step+1);
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
    while(~scanf("%d",&n))
    {
       dfs(1);
       printf("\n");
    }
    return 0;
}
