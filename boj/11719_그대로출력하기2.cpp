#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  string s;

  while(getline(cin, s, '\n')) {
    cout << s << endl;
  }

  return 0;
}