#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  vector<int> hams;
  vector<int> cokes;

  for(int i=0;i<3;i++) {
    int ham;
    cin >> ham;
    hams.push_back(ham);
  }

  for(int i=0; i<2; i++) {
    int coke;
    cin >> coke;
    cokes.push_back(coke);
  }

  auto minham = min_element(hams.begin(), hams.end());
  auto mincoke = min_element(cokes.begin(), cokes.end());

  int answer = *minham + *mincoke - 50;

  cout << answer << '\n';

  return 0;
}
