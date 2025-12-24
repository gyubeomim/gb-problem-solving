#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int LM = 100000;
constexpr int MOD = 1'000'000'009;

ll D[LM + 1][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 초기값
    D[1][1] = 1;
    D[2][2] = 1;
    D[3][1] = D[3][2] = D[3][3] = 1;

    // DP 미리 계산
    for (int i = 4; i <= LM; i++) {
        D[i][1] = (D[i-1][2] + D[i-1][3]) % MOD;
        D[i][2] = (D[i-2][1] + D[i-2][3]) % MOD;
        D[i][3] = (D[i-3][1] + D[i-3][2]) % MOD;
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << (D[N][1] + D[N][2] + D[N][3]) % MOD << '\n';
    }
}
