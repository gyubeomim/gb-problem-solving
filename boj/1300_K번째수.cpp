#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  // A[3][3]
  // B[7] = A[3][1]
  // [1 1] [1 2] [1 3] [2 1] [2 2] [2 3] [3 1] [3 2] [3 3]
  // 1 2 3 2 4 6 3 6 9
  // 1 2 2 3 3 4 6 6 9

  int N,K;
  cin >>N >>K;

  int lo=1;
  int hi=K;
  int ret=-1;

  while(lo<=hi){
    int mid = (lo+hi)/2;

    int cnt=0;
    for(int i=1; i<=N;i++){
      cnt += min(mid/i, N);
    }

    if(cnt < K){
      lo = mid+1;
    }
    else{
      ret = mid;
      hi = mid-1;
    }

  }
  cout << ret << endl;

  return 0;
}
