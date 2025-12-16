#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << ": " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

struct Data {
  int id, score;
  bool operator<(const Data& r) const {
    if(score == r.score) return id < r.id;
    return score < r.score;
  }
};

struct MaxCmp {
  bool operator()(const Data& a, const Data& b) const {
    if(a.score == b.score) return a.id > b.id;
    return a.score > b.score;
  }
};

set<Data> minSet;
set<Data, MaxCmp> maxSet;
unordered_map<int,int> hmap;

int main(int argc, char **argv){
  #ifndef ONLINE_JUDGE
  freopen("data/Query+.txt", "r", stdin);
  #endif

  int Q; scanf("%d", &Q);

  while(Q--){
    int cmd; scanf("%d", &cmd);
    if(cmd == 1){
      int id,score; scanf("%d%d", &id, &score);
      auto it = hmap.find(id);
      if(it != hmap.end()){
        Data old{id, it->Y};
        minSet.erase(old);
        maxSet.erase(old);
      }

      hmap[id] = score;
      Data cur{id, score};
      minSet.insert(cur);
      maxSet.insert(cur);
    }
    if(cmd == 2){
      int id; scanf("%d", &id);
      auto it = hmap.find(id);
      if(it != hmap.end()){
        Data cur{id, it->Y};
        minSet.erase(cur);
        maxSet.erase(cur);
      }
    }
    if(cmd == 3){
      if(minSet.size() >= 3){
        auto it = minSet.begin();
        std::advance(it, 2);
        printf("%d\n", it->id);
      }else{
        printf("-1\n");
      }
    }
    if(cmd == 4){
      if(maxSet.size() >= 3){
        auto it = maxSet.begin();
        std::advance(it, 2);
        printf("%d\n", it->id);
      }else{
        printf("-1\n");
      }

    }
  }
}