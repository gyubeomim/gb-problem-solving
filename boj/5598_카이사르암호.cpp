#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  string S;
  cin >> S;

  for(int i=0; i<S.size(); i++) {
    if(S[i] == 'A' || S[i] == 'B' || S[i] == 'C') {
      S[i] += 26 - 3;
    }
    else {
    S[i] -= 3;
    }
  }

  cout << S << endl;

  return 0;
}
