���⣺q�β�ѯ������a,b�������Ŀ�������ʹ�� x*y<a*b

˼·��������sqrt(a*b)�йأ�Ȼ����ݹ�ϵ�����㣬���Ե�һ�����ۼ�ס

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
	int n;
	cin >> n;
	ll a, b, pr;
	ll ans;
	for(int i = 1;i <= n; i++)
	{
		cin >> a >> b;
		pr = a * b;
		ll t = sqrt(pr);
		if(t * (t + 1) < pr)
			ans = t * 2 - 1;
		else if(t * t == pr)
		{
			if(a == b)
				ans = (t - 1) * 2;
			else
				ans = (t - 1) * 2 - 1;
		}
		else
			ans = (t - 1) * 2;
		cout << ans << endl;
	}
	return 0;
}
