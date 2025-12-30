#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, char>> command;
deque<pair<int, int>> snake;
int map[100][100] = {0};
int N;

void GetHeading(int time, int& heading) {
  int signal = 0;
  for (auto it : command) {
    if (it.first == time) {
      if (it.second == 'D') {
        signal = 1;
      } else if (it.second == 'L') {
        signal = 2;
      }
    }
  }

  if (signal == 1) {
    heading += 1;
    if (heading == 5) heading = 1;
  } else if (signal == 2) {
    heading -= 1;
    if (heading == 0) heading = 4;
  }
}

void RemoveBody(int heading) {
  int x, y;
  if (snake.size() > 1) {
    x = snake.at(1).first;
    y = snake.at(1).second;
  } else {
    x = snake.front().first;
    y = snake.front().second;
  }

  if (heading == 1) {
    if (map[x][y + 1] != 2) {
      snake.pop_back();
    } else {
      map[x][y + 1] = 1;
    }
  } else if (heading == 2) {
    if (map[x + 1][y] != 2) {
      snake.pop_back();
    } else {
      map[x + 1][y] = 1;
    }
  } else if (heading == 3) {
    if (map[x][y - 1] != 2) {
      snake.pop_back();
    } else {
      map[x][y - 1] = 1;
    }
  } else if (heading == 4) {
    if (map[x - 1][y] != 2) {
      map[x - 1][y] = 1;
      snake.pop_back();
    } else {
      map[x - 1][y] = 1;
    }
  }
}

void AddBody(int heading) {
  int x = snake.front().first;
  int y = snake.front().second;

  if (heading == 1) {
    snake.push_front(make_pair(x, y + 1));
  } else if (heading == 2) {
    snake.push_front(make_pair(x + 1, y));
  } else if (heading == 3) {
    snake.push_front(make_pair(x, y - 1));
  } else if (heading == 4) {
    snake.push_front(make_pair(x - 1, y));
  }

  for (auto it : snake) {
  }
}

bool check() {
  int x = snake.front().first;
  int y = snake.front().second;

  if (x < 0 || x > N - 1 || y < 0 || y > N - 1) {
    return false;
  }

  for (int i = 0; i < snake.size() - 1; i++) {
    for (int j = i + 1; j < snake.size(); j++) {
      if (snake.at(i).first == snake.at(j).first) {
        if (snake.at(i).second == snake.at(j).second) {
          // cout << "check2: " << snake.at(i).first << ", " << snake.at(i).second << ", "
          //  << snake.at(j).first << ", " << snake.at(j).second << endl;
          return false;
        }
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  snake.push_back(make_pair(0, 0));

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      map[i][j] = 1;
    }
  }

  int num_apple;
  cin >> num_apple;

  while (num_apple--) {
    int x, y;
    cin >> x >> y;
    map[x - 1][y - 1] = 2;  // apple
  }

  int num_command;
  cin >> num_command;

  while (num_command--) {
    int t;
    char c;
    cin >> t >> c;
    command.push_back(make_pair(t + 1, c));
  }

  int time = 0;
  int heading = 1;
  while (true) {
    time += 1;
    GetHeading(time, heading);
    AddBody(heading);
    if (!check()) break;
    RemoveBody(heading);
  }

  cout << time << '\n';

  return 0;
}