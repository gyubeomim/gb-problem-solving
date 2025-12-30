#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int woman, man, intern;
  cin >> woman >> man >> intern;

  while (intern) {
    if (woman >= 2 * man) {
      woman -= 1;
      intern -= 1;
    } else {
      man -= 1;
      intern -= 1;
    }
  }

  cout << std::min(man, woman / 2) << '\n';

  return 0;
}