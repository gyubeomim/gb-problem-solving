#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int x;
		scanf("%d", &x);
		pq.push(x);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b= pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	printf("%d", ans);
}

