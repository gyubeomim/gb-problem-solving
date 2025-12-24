#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> num(N);
        for (int i = 0; i < N; i++) cin >> num[i];

        ll sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                sum += gcd(num[i], num[j]);
            }
        }
        cout << sum << '\n';
    }
}
