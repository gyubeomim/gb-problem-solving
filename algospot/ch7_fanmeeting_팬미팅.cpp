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
    for(int i=0; i<num.size()-1; i++){
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
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            c[i+j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

// a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    // Ensure a has enough size to accommodate b shifted by k
    int sizeNeeded = max((int)a.size(), (int)(b.size() + k));
    if(a.size() < sizeNeeded) {
        a.resize(sizeNeeded, 0);
    }
    // Digit-wise addition
    for(int i=0; i<b.size(); i++){
        a[i + k] += b[i];
    }
    normalize(a);
}

// a -= b
void subFrom(vector<int>& a, const vector<int>& b) {
    // Subtract b from a
    for(int i=0; i<b.size(); i++){
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    // a가 b보다 작으면 swap
    if(an < bn) return karatsuba(b,a);

    if(an == 0 || bn == 0) 
        return vector<int>();

    // 작은 크기에서는 일반 곱으로 계산
    if(an <= 50) 
        return multiply(a,b);

    int half = an / 2;

    // a, b를 절반으로 분할
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // 재귀적으로 계산
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    // (a0 + a1)*(b0 + b1)를 계산
    addTo(a0, a1, 0);  // a0 = a0 + a1
    addTo(b0, b1, 0);  // b0 = b0 + b1
    vector<int> z1 = karatsuba(a0, b0);
    
    // z1 = z1 - z0 - z2
    subFrom(z1, z0);
    subFrom(z1, z2);

    // 결과를 ret에 합치기
    vector<int> ret;
    // 시작은 0으로 아무것도 없는 상태
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}


int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);

	for(int i=0; i<N; i++) A[i] = (members[i] == 'M');
	for(int i=0; i<M; i++) B[M-i-1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);

	int allHugs = 0;
	for(int i=N-1; i<M; i++){
		if(C[i] == 0) 
			++allHugs;
	}

	return allHugs;
}

int main(int argc, char **argv){
	int C;
	scanf("%d", &C);

	while(C--){
		string members, fans;
		cin >> members;
		cin >> fans;

		int ret = hugs(members, fans);
		printf("%d\n", ret);
	}
}
