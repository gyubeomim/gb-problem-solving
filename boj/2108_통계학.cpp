#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  cin >> N;

  vector<int> v;

  for(int i=0; i<N; i++){
    int n;
    cin >> n;

    v.push_back(n);
  }

  int sum=0;
  sort(v.begin(), v.end());

  map<int, int> m;

  for(auto it : v){
    sum += it;
    m[it]++;
  }

  int mean = round((double)sum/N);
  int median = v[ceil(N/2)];
  int range = v.back() - v.front();

  int freq = 0;

  int max_=-9999;

  for(auto it : m){
    if(max_ < it.second){
      max_ = it.second;
    }
  }


  vector<int> vv;
  for(auto it : m){
    if(max_ == it.second){
      vv.push_back(it.first);
    }
  }

  // cout << "vv: " << endl;
  // for(auto it : vv){
  //   cout << "it: " << it << endl;
  // }

  sort(vv.begin(), vv.end());
  if(vv.size() != 1){
    freq = vv[1];
  }
  else{
    freq = vv[0];
  }

  cout << mean << endl;
  cout << median << endl;
  cout << freq << endl;
  cout << range << endl;



  return 0;
}
