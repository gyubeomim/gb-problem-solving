#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

template<typename T>
struct compareABS {
	bool operator()(T a, T b) {
		if(abs(a) == abs(b)) return a>b;
		return abs(a) > abs(b);
	}
};

priority_queue<int> maxpq;  // max heap
priority_queue<int, vector<int>, greater<int>> minpq; // min heap
priority_queue<int, vector<int>, compareABS<int>> abspq;

int main(int argc, char **argv){
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int val;
		scanf("%d", &val);

		if(val != 0) {
			maxpq.push(val);
			minpq.push(val);
			abspq.push(val);
		}
		else {
			int a=-1,b=-1,c=-1;
			if(!maxpq.empty()) a = maxpq.top(), maxpq.pop();
			if(!minpq.empty()) b = minpq.top(), minpq.pop();
			if(!abspq.empty()) c = abspq.top(), abspq.pop();

			if(a == -1 && b == -1 && c == -1) printf("-1\n");
			else
				printf("%d %d %d\n", a, b, c);
		}
	}
}