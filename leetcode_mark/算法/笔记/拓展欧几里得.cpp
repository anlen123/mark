ll exgcd(ll a, ll b��ll &x,ll &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a%b);
	ll t = x;
	x = y;
	y = t - (a / b)*y;
	return d;
}





#include<iostream>
#include<cstdio>
#include<cmath>
 
using namespace std;
 
int exgcd(int a,int b,int &x,int &y)//��չŷ������㷨
{
    if(b==0)
    {
        x=1;y=0;
        return a;  //����ݹ�߽翪ʼ����һ�㷵��
    }
    int r=exgcd(b,a%b,x,y);
    int temp=y;    //��x y�����һ���
    y=x-(a/b)*y;
    x=temp;
    return r;     //�õ�a b���������
}