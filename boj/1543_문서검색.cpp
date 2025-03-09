#include <bits/stdc++.h>
using namespace std;

int main( int argc, char **argv ) {
  string t, p;
  getline( cin, t );
  getline( cin, p );

  int cnt = 0;
  int f = t.find( p );
  while ( f != string::npos ) {
    cnt++;
    f = t.find( p, p.size() + f );
  }
  printf( "%d\n", cnt );
}
