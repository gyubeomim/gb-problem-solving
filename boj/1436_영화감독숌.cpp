#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  cin>>N;

  int num=0;
  int cnt =0;
  while(true){
    num+=1;
    string s = to_string(num);


    if(s.find("666") != string::npos){
      cnt += 1;

      if(cnt == N){
        cout << s << endl;
        return 0;
      }
    }
  }




  return 0;
}
