#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

// num[]의 자리수 올림을 처리한다
void normalize(vector<int>& num){
	num.push_back(0);

	// 자리수 올림 처리
	for(int i=0;i<num.size()-1; i++){
		if(num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i+1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
	}

	while(num.size() > 1 && num.back() == 0) 
		num.pop_back();
}

// 두 긴 자연수의 곱을 반환한다
// 각 배열에는 각 수의 자리수가 1의 자리에서부터 시작해 저장되어있다
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			c[i+j] += a[i] * b[j];
	normalize(c);
	return c;
}

int main(int argc, char **argv){
	vector<int> a,b;
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);

	b.push_back(8);
	b.push_back(7);
	b.push_back(6);
	b.push_back(5);

	vector<int> c = multiply(a,b);

	for(auto rit = c.rbegin(); rit!=c.rend(); rit++) {
		printf("%d", *rit);
	}
	puts("");
}
