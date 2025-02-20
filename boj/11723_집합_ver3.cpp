#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

int state;

int main( int argc, char **argv ) {
  FASTIO;
  int M;
  cin >> M;
  while ( M-- ) {
    string com;
    int x;
    cin >> com;

    if ( com == "add" ) {
      cin >> x;
      state |= ( 1 << ( x - 1 ) );
    } 
    else if ( com == "remove" ) {
      cin >> x;
      state &= ( ~( 1 << ( x - 1 ) ) );
    } 
    else if ( com == "check" ) {
      cin >> x;
      printf( "%d\n", ( ( state >> ( x - 1 ) ) & 1 ) );
    } 
    else if ( com == "toggle" ) {
      cin >> x;
      state ^= ( 1 << ( x - 1 ) );
    } 
    else if ( com == "all" ) {
      state = 0xfffff;
    } 
    else {  // empty
      state = 0;
    }
  }
}
