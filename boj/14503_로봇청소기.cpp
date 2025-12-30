#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Robot {
  Robot(int x, int y, int heading, int N, int M)
      : x_(x), y_(y), heading_(heading), count_(0), N_(N), M_(M) {
    b0_ = true;
    b1_ = true;
    b2_ = true;
    b3_ = true;

    // cout<<"x_: "<<x_<<", y_: "<<y_<<", heading_: "<<heading<<endl;
  }

  int x_;
  int y_;
  int heading_;
  int count_;
  bool b0_, b1_, b2_, b3_;
  int N_,M_;
  int map_[50][50] = {1};

  void GoNext();

  void GetOut();

  void Terminate();

  void Update(int x, int y, int heading, bool getout);

  void SetMap(int map[50][50]);

  void DoClean();
};

void Robot::DoClean(){
  if(map_[x_][y_]==0){
    map_[x_][y_]=2;
    count_+=1;
  }
}

void Robot::SetMap(int map[50][50]) {
  std::copy(&map[0][0], &map[0][0] + 50 * 50, &map_[0][0]);

  // for(int i=0;i<50;i++){
  //   for(int j=0;j<50;j++){
  //     cout<<map_[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
}

void Robot::Update(int x, int y, int heading, bool getout) {
  if(x<0 || x>N_ || y<0 || y>M_) {
    Terminate();
  }

  x_ = x;
  y_ = y;
  heading_ = heading;

  b0_ = true;
  b1_ = true;
  b2_ = true;
  b3_ = true;

  if(!getout){
    map_[x_][y_] = 2;
    count_ += 1;
  }

  // cout << "Update: x_:" << x_ << ", y_: " << y_ << ", heading_: " << heading_ << ", count: " << count_ <<", getout: " << bool(getout) << endl;
}

void Robot::GoNext() {
  while (true) {
    if (heading_ == 0) {
      // cout<<"HEADING 0"<<endl;
      if (map_[x_][y_ - 1] == 0) {
        Update(x_, y_ - 1, 3, false);
      } else {
        heading_ = 3;
        b0_ = false;
      }
    } else if (heading_ == 1) {
      // cout<<"HEADING 1"<<endl;
      if (map_[x_ - 1][y_] == 0) {
        Update(x_ - 1, y_, 0, false);
      } else {
        heading_ = 0;
        b1_ = false;
      }
    } else if (heading_ == 2) {
      // cout<<"HEADING 2"<<endl;
      if (map_[x_][y_ + 1] == 0) {
        Update(x_, y_ + 1, 1,false);
      } else {
        heading_ = 1;
        b2_ = false;
      }
    } else if (heading_ == 3) {
      // cout<<"HEADING 3"<<endl;
      if (map_[x_ + 1][y_] == 0) {
        Update(x_ + 1, y_, 2, false);
      } else {
        heading_ = 2;
        b3_ = false;
      }
    }

    if (!b0_ && !b1_ && !b2_ && !b3_) {
      // cout<<"GETOUT"<<endl;
      GetOut();
    }
  }
}

void Robot::GetOut() {
  if (heading_ == 0) {
    if (map_[x_ + 1][y_] == 1) {
      Terminate();
    }
    Update(x_ + 1, y_, 0, true);
  } else if (heading_ == 1) {
    if (map_[x_][y_ - 1] == 1) {
      Terminate();
    }
    Update(x_, y_ - 1, 1, true);
  } else if (heading_ == 2) {
    if (map_[x_ - 1][y_] == 1) {
      Terminate();
    }
    Update(x_ - 1, y_, 2, true);
  } else if (heading_ == 3) {
    if (map_[x_][y_ + 1] == 1) {
      Terminate();
    }
    Update(x_, y_ + 1, 3, true);
  }
}

void Robot::Terminate() {
  cout << count_ << '\n';
  exit(0);
}

int main() {
  int N, M;
  cin >> N >> M;

  int x, y, heading;
  cin >> x >> y >> heading;
  Robot robot(x, y, heading, N, M);

  int _map[50][50] = {1};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> _map[i][j];
      // cout << _map[i][j];
    }
    // cout << endl;
  }

  robot.SetMap(_map);
  robot.DoClean();
  robot.GoNext();
}