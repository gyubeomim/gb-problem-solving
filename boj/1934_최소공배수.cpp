#include <iostream>
using namespace std;

int gcd(int x, int y) {
  if(y==0) return x;
  else return gcd(y, x%y);
}

int main() {
  int T;
  cin >> T;

  while(T--) {
    int a,b;
    cin >> a >> b;
    int g = gcd(a,b);
    cout << a*b/g << endl;
  }

  return 0;
}
