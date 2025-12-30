#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  cin >> N;

  map<string, int> m;
  vector<string> v;
  int count=0;
  for(int i=0;i<N;i++){
    string a,b;
    cin >> a >> b;

    string s = a.substr(0,2) + b;
    v.push_back(s);

    m[s]++;

  }


  int cnt;
  for(auto it : v) {
    string rev = it.substr(2,2) + it.substr(0,2);
    if(it == rev) continue;


    if(m.count(rev)) cnt += m[rev];
  }

  cout << cnt/2 << '\n';




  return 0;
}
