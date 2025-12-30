#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N,M;

  cin >> N;

  vector<int> nvec, mvec;

  for(int i=0; i<N;i++){
    int x;
    cin >>x;
    nvec.push_back(x);
  }
  cin>>M;
  for (int i=0; i<M;i++){
    int x;
    cin >> x;
    mvec.push_back(x);
  }

  sort(nvec.begin(), nvec.end());

  for(int i=0; i<mvec.size();i++){
    int target=mvec.at(i);
    int lo=0;
    int hi=nvec.size();
    bool exist=false;

    while(lo<hi){
      int mid=(lo+hi)>>1;

      if(nvec.at(mid)<target) lo=mid+1;
      else if(nvec.at(mid)==target) {
        exist=true;
        break;
      }
      else hi=mid;
    }
    if(exist) cout << "1 ";
    else cout << "0 ";
  }




  return 0;
}