#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int height, width;
  cin >> height >> width;

  if(height == 1)
    cout << 1;
  else if(height == 2)
    cout << min(4, (width+1)/2);
  else if(height >= 3) {
    if(width >= 7)
      cout << width - 2;
    else
      cout << min(4, width);
  }
  
  return 0;
}
