lt exgcd(lt a,lt b,lt &x,lt &y)
{
    if(b==0){x=1;y=0;return a;}
    lt gcd=exgcd(b,a%b,x,y);
    lt tp=x;
    x=y; y=tp-a/b*y;
    return gcd;
}

lt excrt()
{
    lt x,y,k;
    lt M=bi[1],ans=ai[1];
    for(int i=2;i<=n;i++)
    {
        lt a=M,b=bi[i],c=(ai[i]-ans%b+b)%b;
        lt gcd=exgcd(a,b,x,y),bg=b/gcd;
        if(c%gcd!=0) return -1; 
        
        x=mul(x,c/gcd,bg);
        ans+=x*M;
        M*=bg;
        ans=(ans%M+M)%M;
    }
    return (ans%M+M)%M;
}












#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
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
#include <time.h>
#define ll long long
#define chushihua(x,y) memset(x,y,sizeof x)
using namespace std;
const ll MAXX = 1000000 + 10;
const double PI = 3.14159265358979323846;
const ll mod = 1000000007;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll powmod(ll a, ll b, ll MOD) { ll ans = 1; while (b) { if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2; }return ans; }
ll ksm(ll a, ll  b) { ll ans = 1; while (b) { if (b % 2)ans = ans * a; a = a * a; b /= 2; }return ans; }
ll ksc(ll a, ll  b,ll mod) { ll ans = 0; while (b) { if (b % 2)ans = ans + a%mod; a = (a + a)%mod; b>>=1; }return ans; }
ll a[100000+10],b[100000+10];
int n;
inline bool read(int& num)
{
	char in; bool IsN = false;
	in = getchar();
	if (in == EOF) return false;
	while (in != '-' && (in<'0' || in>'9')) in = getchar();
	if (in == '-') { IsN = true; num = 0; }
	else num = in - '0';
	while (in = getchar(), in >= '0' && in <= '9') {
		num *= 10, num += in - '0';
	}
	if (IsN) num = -num;
	return true;
}

void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){ x=1; y=0; return;}
    exgcd(b,a%b,x,y);
    int tp=x;
    x=y; y=tp-a/b*y;
}

ll china()
{
    ll ans=0,lcm=1,x,y;
    for(int i=1;i<=n;++i) lcm*=b[i];
    for(int i=1;i<=n;++i)
    {
        ll tp=lcm/b[i];
        exgcd(tp,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+ksc(ksc(tp,x,lcm),a[i],lcm))%lcm;
    }
    return (ans+lcm)%lcm;
}

int main(){
    cin>>n;
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for (int i = 1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for (int i = 1;i<=n;i++){
        a[i]=(a[i]%b[i]+b[i])%b[i];
    }
    cout<<china()<<endl;
    return 0;
}


