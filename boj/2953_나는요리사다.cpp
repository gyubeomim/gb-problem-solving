#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  std::vector<int> scores(5);

  for(int i=0;i<5;i++) {
    int a,b,c,d;
    cin >> a>>b>>c>>d;

    scores[i] = (a+b+c+d);
  }

  int num=0;
  int max_score=0;

  for(int i=0; i<scores.size(); i++) {
    int score = scores[i];
    if(max_score < score) {
      max_score = score;
      num = i+1;
    }
  }

  std::cout << num << ' ' << max_score << std::endl;

  return 0;
}
