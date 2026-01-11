#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
using ll = long long;

struct Event {
    ll coord;
    int delta; // +1 start, -1 end
    bool operator<(Event const &other) const {
        if (coord != other.coord) return coord < other.coord;
        return delta < other.delta; // end(-1) before start(+1)
    }
};

static int max_overlap_open_intervals(const vector<pair<ll, ll>> &intervals) {
    vector<Event> ev;
    ev.reserve(intervals.size() * 2);
    for (auto &p : intervals) {
        ll a = p.first;
        ll b = p.second;
        if (a == b) continue;
        if (a > b) swap(a, b);
        ev.push_back({a, +1});
        ev.push_back({b, -1});
    }
    if (ev.empty()) return 0;
    sort(ev.begin(), ev.end());

    int cur = 0;
    int best = 0;
    size_t i = 0;
    while (i < ev.size()) {
        ll coord = ev[i].coord;
        // process all events at this coord
        while (i < ev.size() && ev[i].coord == coord) {
            cur += ev[i].delta;
            i++;
        }
        // cur applies to open interval just after coord
        if (cur > best) best = cur;
    }
    return best;
}

int main() {
    FASTIO;
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<ll, ll>> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    vector<pair<ll, ll>> vertical;   // y-intervals from vertical edges
    vector<pair<ll, ll>> horizontal; // x-intervals from horizontal edges
    vertical.reserve(n);
    horizontal.reserve(n);

    for (int i = 0; i < n; i++) {
        auto [x1, y1] = pts[i];
        auto [x2, y2] = pts[(i + 1) % n];
        if (x1 == x2) {
            vertical.push_back({y1, y2});
        } else {
            horizontal.push_back({x1, x2});
        }
    }

    int h = max_overlap_open_intervals(vertical);
    int v = max_overlap_open_intervals(horizontal);
    cout << max(h, v) << "\n";
    return 0;
}
