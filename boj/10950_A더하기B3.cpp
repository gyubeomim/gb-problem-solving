#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A,B;
  for(int i=0; i<N; i++) {
    cin >> A >> B;
    cout << A + B << "\n";
  }

  return 0;
}