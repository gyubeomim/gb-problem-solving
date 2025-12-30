#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int T;
  cin >> T;

  int t=1;
  while(true) {
    int N;
    vector<int> scores;
    cin >> N;
    for(int i=0; i<N; i++) {
      int score;
      cin >> score;
      scores.push_back(score);
    }

    sort(scores.begin(), scores.end(), greater<int>());

    int max_score = scores[0];
    int min_score = scores[N-1];
    int largest_gap = 0;

    for(int i=1; i<scores.size(); i++) {
      int gap = scores[i-1] - scores[i];
      if(largest_gap < gap) {
        largest_gap = gap;
      }
    }

    cout << "Class " << t << endl;
    cout << "Max " << max_score << ", Min " << min_score << ", Largest gap " << largest_gap << endl;
    if(t >= T) {
      break;
    }
    t += 1;
  }

  return 0;
}
