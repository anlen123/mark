# -
记录算法的地方  

cout.setf(ios::fixed)；
cout <<  fixed << setprecision(x) << ans << endl;///保留x位小数
 
///快读

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



///最大公约数，以及快速幂

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll powmod(ll a, ll b, ll MOD) { ll ans = 1; while (b) { if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2; }return ans; }
ll ksm(ll a, ll  b) { ll ans = 1; while (b) { if (b % 2)ans = ans * a; a = a * a; b /= 2; }return ans; }
