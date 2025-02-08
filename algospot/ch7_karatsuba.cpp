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

// a += b * (10^k) implentation
void addTo(vector<int>& a, const vector<int>& b, int k);

// a -= b  implentation
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();

	if(an < bn) return karatsuba(b,a);

	if(an==0 || bn == 0) return vector<int>();

	if(an <= 50) return multiply(a,b);

	int half = an/2;

	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
	vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	
	addTo(a0, a1, 0); addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}


int main(int argc, char **argv){
	 
}
