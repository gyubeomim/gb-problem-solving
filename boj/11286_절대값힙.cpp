#include <bits/stdc++.h>
using namespace std;

class cmp {
	public:
		bool operator()(int a, int b) {
			if (abs(a) != abs(b)) 
				return abs(a) > abs(b);
			return a > 0 && b < 0;
		}
};

int main() {
	priority_queue<int, vector<int>, cmp> pq;
	int n; scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x == 0){
			if(pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}

