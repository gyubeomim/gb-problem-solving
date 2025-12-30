#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N,M;


  cin>>N>>M;

  int W,L,G;
  cin>>W>>L>>G;

  map<string,int> m;
  for(int i=0;i<M;i++){
    string a,b;
    cin>>a>>b;

    if(b=="W"){
      m[a]++;
    }
  }


  int score=0;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;

    if(m[s]) {
      score += W;
    }
    else {
      score -= L;
      if(score<0) score=0;
    }


    if(score >= G) {
      cout << "I AM NOT IRONMAN!!\n";
      return 0;
    }

  }


  cout << "I AM IRONMAN!!\n";





  return 0;
}
