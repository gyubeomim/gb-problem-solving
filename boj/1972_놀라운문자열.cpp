#include <bits/stdc++.h>

using namespace std;






int main() {



	while(true) {
		string s;
		cin >> s;


		if (s == "*") break;




		int len = s.size();

		if(len <= 2) {
			cout << s << " is surprising.\n";
			continue;
		}



		map<string, int > m;
		bool surp = true;


		for(int d=0 ; d<len-1; d++) {

			for(int i=0; i<=len-d-2; i++) {
				char start = s[i] ;
				char end = s[i+d+1];

				if(i+d  > len) continue;

				string word;

				word += start;
				word += end;




				m[word]++;
				// cout << "1: " << m[word] << ", " << word << ", " << i << ", " << d << endl;

				if(m[word] > 1) {
					// cout << m[word] << ", " << word << ", " << i << ", " << d << endl;
					surp = false;
				}
			}
			// cout << endl;

			m.clear();
		}



		if(surp) {
			cout << s << " is surprising.\n";
		}
		else {
			cout << s << " is NOT surprising.\n";
		}


	}
	

	return 0;
}