#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N,M;
  cin >> N >> M;

  vector<string> v;
  v.resize(N);

  for(int i=0; i<N; i++){
    string s;
    cin >> s;
    v[i] = s;
    // cout << endl;
    // cout << v[i] << endl;
  }

  int min = 999999;

  for(int i=0; i<=N-8; i++){
    for(int j=0; j<=M-8; j++){
    int cnt_WB = 0;
    int cnt_BW = 0;


      for(int k=0; k<8; k++){
        for(int q=0; q<8; q++){
          if(v[i+k][j+q] != BW[k][q]){
            cnt_BW++;
          }
          if(v[i+k][j+q] != WB[k][q]) {
            cnt_WB++;
          }
        }
      }

      // cout << i <<"," <<j << " : "<< cnt_BW << ", "<<cnt_WB<< endl;

      if(min > cnt_BW){
        min = cnt_BW;
        cnt_BW=0;
      }
      if(min > cnt_WB){
        min = cnt_WB;
        cnt_WB=0;
      }
    }
  }

  cout << min << endl;


  return 0;
}
