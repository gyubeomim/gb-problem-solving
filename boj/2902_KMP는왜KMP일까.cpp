#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  string str;
  cin >> str;

  string answer;
  answer += str[0];
  for(int i=0; i<str.size(); i++) {
    if(str[i] == '-') {
      answer += str[i+1];
    }
  }
  cout << answer << endl;
  return 0;
}
