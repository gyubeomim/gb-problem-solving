#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;

  for(int i=0; i<s.size(); i++) {
    if(i % 10 == 0 && i > 1) cout << endl;
    cout << s.at(i);
  }

  return 0;
}