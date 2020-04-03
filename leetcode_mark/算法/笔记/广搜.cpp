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
const double PI = 3.14159265358979323846;
int n, m;
struct node {
	int x;
	int cnt;
}a;
int vis[10000 + 10];
queue<node > q;
int bfs() {
	chushihua(vis, 0);
	a.x = n;
	a.cnt = 0;
	q.push(a);
	vis[a.x] = 1;
	while (!q.empty()) {
		node b = q.front();
		q.pop();
		if (b.x != m) {
			node tmp1, tmp2;
			tmp1.x = b.x * 2;
			tmp1.cnt = b.cnt + 1;
			if (tmp1.x >= 0 && tmp1.x <= 10000 && vis[tmp1.x] == 0) {!
				q.push(tmp1);
				vis[tmp1.x] = 1;
			}
			tmp2.x = b.x - 1;
			tmp2.cnt = b.cnt + 1;
			if (tmp2.x >= 0 && tmp2.x <= 10000 && vis[tmp2.x] == 0) {
				q.push(tmp2);
				vis[tmp2.x] = 1;
			}
		}
		else {
			return b.cnt;
		}
	}
}
int main() {

	cin >> n >> m;
	if (n >= m) {
		cout << abs(n - m) << endl;
	}
	else {
		cout << bfs() << endl;
	}
	return 0;
}