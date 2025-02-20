#include <bits/stdc++.h>
using namespace std;

vector<string> alphas = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main( int argc, char **argv ) {
  string w;
  cin >> w;
  for ( auto alpha : alphas ) {
    while ( 1 ) {
      int pos = w.find( alpha );
      if ( pos == string::npos ) break;
      w.replace( pos, alpha.size(), "1" );
    }
  }
  printf( "%zu\n", w.size() );
}
