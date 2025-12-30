#include <iostream>
#include <string>
#include <vector>

using namespace std;

string move_clock(string t, int counterclock){
  if(!counterclock)
    return t.back() + t.substr(0, t.size() - 1);

  return t.substr(1,t.size()) + t.front();
}

void move(vector<string>& tt, int tnum, int direction, vector<bool> b_t) {
  bool c;
  if(direction==1) 
    c=false;
  else 
    c=true;

  // cout<<endl<<tt[0]<<","<<tt[1]<<","<<tt[2]<<","<<tt[3]<<endl;
  if (tnum == 1) {
    tt[0] = move_clock(tt[0],c);
    if (b_t[1])
      tt[1] = move_clock(tt[1],!c);
    if (b_t[2])
      tt[2] = move_clock(tt[2],c);
    if (b_t[3])
      tt[3] = move_clock(tt[3],!c);
  } 
  else if (tnum == 2) {
    tt[1] = move_clock(tt[1],c);
    if (b_t[0])
      tt[0] = move_clock(tt[0],!c);
    if (b_t[2])
      tt[2] = move_clock(tt[2],!c);
    if (b_t[3])
      tt[3] = move_clock(tt[3],c);
  } 
  else if (tnum == 3) {
    tt[2] = move_clock(tt[2],c);
    if (b_t[0])
      tt[0] = move_clock(tt[0],c);
    if (b_t[1])
      tt[1] = move_clock(tt[1],!c);
    if (b_t[3])
      tt[3] = move_clock(tt[3],!c);
  } 
  else if (tnum == 4) {
    tt[3] = move_clock(tt[3],c);
    if (b_t[0])
      tt[0] = move_clock(tt[0],!c);
    if (b_t[1])
      tt[1] = move_clock(tt[1],c);
    if (b_t[2])
      tt[2] = move_clock(tt[2],!c);
  }
  // cout<<"after: "<<tt[0]<<","<<tt[1]<<","<<tt[2]<<","<<tt[3]<<endl;
}

int main() {
  vector<string> tt(4);
  cin >> tt[0] >> tt[1] >> tt[2] >> tt[3];

  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int tnum, direction;
    cin >> tnum >> direction;

    vector<bool> b_t(4);
    b_t[0]=false;
    b_t[1]=false;
    b_t[2]=false;
    b_t[3]=false;

    if (tnum == 1) {
      b_t[0] = true;
      if (tt[0].at(2) != tt[1].at(6))
        b_t[1] = true;
      if (tt[1].at(2) != tt[2].at(6) && b_t[1])
        b_t[2] = true;
      if (tt[2].at(2) != tt[3].at(6) && b_t[2])
        b_t[3] = true;

      move(tt, tnum, direction, b_t);
    } else if (tnum == 2) {
      b_t[1] = true;
      if (tt[0].at(2) != tt[1].at(6))
        b_t[0] = true;
      if (tt[1].at(2) != tt[2].at(6))
        b_t[2] = true;
      if (tt[2].at(2) != tt[3].at(6) && b_t[2])
        b_t[3] = true;

      move(tt, tnum, direction, b_t);
    } else if (tnum == 3) {
      b_t[2] = true;
      if (tt[1].at(2) != tt[2].at(6))
        b_t[1] = true;
      if (tt[0].at(2) != tt[1].at(6) && b_t[1])
        b_t[0] = true;
      if (tt[2].at(2) != tt[3].at(6))
        b_t[3] = true;

      move(tt, tnum, direction, b_t);
    } else if (tnum == 4) {
      b_t[3] = true;
      if (tt[2].at(2) != tt[3].at(6))
        b_t[2] = true;
      if (tt[1].at(2) != tt[2].at(6) && b_t[2])
        b_t[1] = true;
      if (tt[0].at(2) != tt[1].at(6) && b_t[1])
        b_t[0] = true;

      move(tt, tnum, direction, b_t);
    }
  }
  int ans = 0;
  if (tt[0].at(0) == '1') ans += 1;
  if (tt[1].at(0) == '1') ans += 2;
  if (tt[2].at(0) == '1') ans += 4;
  if (tt[3].at(0) == '1') ans += 8;

  cout << ans << '\n';
}