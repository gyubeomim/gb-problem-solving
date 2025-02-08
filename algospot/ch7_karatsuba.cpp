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

int main(){
    string s1, s2;
		s1 = "1234";
		s2 = "5678";

    vector<int> a, b;
    for(int i = s1.size()-1; i >= 0; i--){
        a.push_back(s1[i] - '0');
    }
    for(int i = s2.size()-1; i >= 0; i--){
        b.push_back(s2[i] - '0');
    }

    // Karatsuba로 곱셈
    vector<int> result = karatsuba(a, b);

    // Leading zero 제거 (최소 한 자리는 남겨둠)
    while(result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    // 정상적인(가장 큰 자리부터) 순서로 출력
    for(int i = result.size()-1; i >= 0; i--){
        printf("%d", result[i]);
    }
    puts("");
}
