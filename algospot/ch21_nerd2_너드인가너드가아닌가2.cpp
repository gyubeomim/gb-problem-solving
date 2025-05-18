#include <bits/stdc++.h>
using namespace std;

int N;
map<int, int> coords;

bool isDominated(int x, int y){
  map<int, int>::iterator it = coords.lower_bound(x);
  if(it == coords.end()) return false;
  return y < it->second;
}

void removeDominated(int x, int y){
  map<int, int>::iterator it = coords.lower_bound(x);
  if(it == coords.begin()) return;   // x,y보다 왼쪽에는 점이 없는 경우
  --it;

  // 반복문 불변식 : it는 (x,y) 바로 왼쪽에 있는 점
  while(1){
    // (x,y) 바로 왼쪽에 있는 점을 찾는다. 
    // it가 표시하는 점이 (x,y)에 의해 지배당하지 않는다면 종료
    if(it->second > y) break;

    // 이전 점이 더 없으므로 it만 지우고 종료한다
    if(it == coords.begin()) {
      coords.erase(it);
      break;
    }
    else{
      // 이전 점으로 이터레이터를 하나 옮겨놓고 x를 지운다
      map<int,int>::iterator jt = it;
      --jt;
      coords.erase(it);
      it = jt;
    }
  }
}

// 새 점 (x,y)를 등록시킨다
// 지배 여부를 판단한다
int registered(int x, int y){
  if(isDominated(x,y)) return coords.size();

  removeDominated(x,y);
  coords[x] = y;
  return coords.size();
}

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
      scanf("%d",&N);

      coords.clear();

      int ans = 0;
      for(int i=0; i<N; i++){
        int p,q;
        scanf("%d%d", &p, &q);
        ans += registered(p,q);
      }
      printf("%d\n", ans);
  }
}
