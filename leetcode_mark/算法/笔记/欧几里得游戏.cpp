#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int main()
{
    int T;
    ll n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        if(n<m)swap(n,m); //n%m==0±ØÊ¤
        int res=1;
        while(n%m&&n/m==1)
        {
            n-=m;
            if(n<m)swap(n,m);
            res^=1;
        }
        printf("%s wins\n",res?"Stan":"Ollie");
    }
}
