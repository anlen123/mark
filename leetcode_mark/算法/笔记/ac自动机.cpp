//#include<bits/stdc++.h>
//#define ll long long
//#define chushihua(x,y) memset(x,y,sizeof x)
//using namespace std;
//const ll MAXX = 1000000 + 10;
//const double PI = 3.14159265358979323846;
//const ll mod = 1000000007;
//int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
//ll powmod(ll a, ll b, ll MOD) { ll ans = 1; while (b) { if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2; }return ans; }
//ll ksm(ll a, ll  b) { ll ans = 1; while (b) { if (b % 2)ans = ans * a; a = a * a; b /= 2; }return ans; }
//inline bool read(int& num)
//{
//	char in; bool IsN = false;
//	in = getchar();
//	if (in == EOF) return false;
//	while (in != '-' && (in<'0' || in>'9')) in = getchar();
//	if (in == '-') { IsN = true; num = 0; }
//	else num = in - '0';
//	while (in = getchar(), in >= '0' && in <= '9') {
//		num *= 10, num += in - '0';
//	}
//	if (IsN) num = -num;
//	return true;
//}
//int main() {
//
//	return 0;
//}

#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e6 + 9;

int trie[maxn][26]; //字典树
int cntword[maxn];  //记录该单词出现次数
int fail[maxn];     //失败时的回溯指针
int cnt = 0;

void insertWords(string s) {
	int root = 0;
	for (int i = 0; i < s.size(); i++) {
		int next = s[i] - 'a';
		if (!trie[root][next])
			trie[root][next] = ++cnt;
		root = trie[root][next];
	}
	cntword[root]++;      //当前节点单词数+1
}
void getFail() {
	queue <int>q;
	for (int i = 0; i < 26; i++) {      //将第二层所有出现了的字母扔进队列
		if (trie[0][i]) {
			fail[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	}

	//fail[now]    ->当前节点now的失败指针指向的地方
	////tire[now][i] -> 下一个字母为i+'a'的节点的下标为tire[now][i]
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < 26; i++) {      //查询26个字母
			if (trie[now][i]) {
				//如果有这个子节点为字母i+'a',则
//让这个节点的失败指针指向(((他父亲节点)的失败指针所指向的那个节点)的下一个节点)
				//有点绕,为了方便理解特意加了括号

				fail[trie[now][i]] = trie[fail[now]][i];
				q.push(trie[now][i]);
			}
			else//否则就让当前节点的这个子节点
				//指向当前节点fail指针的这个子节点
				trie[now][i] = trie[fail[now]][i];
		}
	}
}


int query(string s) {
	int now = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {    //遍历文本串
		now = trie[now][s[i] - 'a'];  //从s[i]点开始寻找
		for (int j = now; j && cntword[j] != -1; j = fail[j]) {
			//一直向下寻找,直到匹配失败(失败指针指向根或者当前节点已找过).
			ans += cntword[j];
			cntword[j] = -1;    //将遍历国后的节点标记,防止重复计算
		}
	}
	return ans;	
}

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		insertWords(s);
	}
	fail[0] = 0;
	getFail();
	cin >> s;
	cout << query(s) << endl;
	return 0;
}
