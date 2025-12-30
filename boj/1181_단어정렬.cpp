#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  vector<string> v;
  map<string, int> m;

  cin >> N;

  for(int i=0; i<N; i++){
    string s;
    cin >> s;

    if(!m[s])
        v.push_back(s);
   
    m[s]++;
  }


  sort(v.begin(), v.end(), [](const string& a, const string& b){
                             if(a.size() < b.size()){
                               return true;
                             }
                             else if(a.size() == b.size()){
                               if(a < b){
                                 return true;
                               }
                               else return false;
                             }
                             else{
                               return false;
                             }
                           });

  for(auto it : v){
    cout << it << '\n';
  }

  return 0;
}
