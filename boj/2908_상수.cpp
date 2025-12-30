#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main(int argc, char** argv) {
  std::string a,b;

  cin >> a >> b;

  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  int c = std::stoi(a);
  int d = std::stoi(b);

  if(c > d) {
    std::cout << c;
  }
  else {
    std::cout << d;
  }

  return 0;
}
