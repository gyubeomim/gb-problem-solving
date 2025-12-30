#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N,M;
vector<int> series;

void dfs(int index, int cnt){
  if(cnt == M){
    for(int i=0;i<M;i++){
      cout << series[i] << ' ';
    }
    cout << endl;
    return;
  }

  for(int i=index; i<=N; i++){

    series.push_back(i);
    dfs(i+1, cnt+1);
    series.pop_back();

  }


}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  cin>>N>>M;
  dfs(1,0);



  return 0;
}
