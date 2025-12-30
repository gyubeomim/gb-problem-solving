#include <bits/stdc++.h>

using namespace std;


int HourToMinute(string s) {
	int H = stoi(s.substr(0,2));
	int M = stoi(s.substr(3,4));

	// cout << H << ", " << M << endl;

	return H*60 + M;
}





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	string Start, Finish, Finish2;
	cin >> Start >> Finish >> Finish2;
	int mstart = HourToMinute(Start);
	int mfinish = HourToMinute(Finish);
	int mfinish2 = HourToMinute(Finish2);


	

	set<string> s;

	

	int ans=0;

	while(!cin.eof()) {
		string time, name;
		
		cin >> time >> name;
		
		if(time.empty())continue;

		int mtime = HourToMinute(time);
	
		// cout << "time: " << mtime << ", " << mstart << ", " << mfinish << ", " << mfinish2 << endl;

		if(mtime <= mstart) {
			s.insert(name);
		}
		
		if(mtime >= mfinish && mtime <= mfinish2) {
			if(s.count(name)) {
				ans++;
				// cout << "ans: " << ans << endl;
				s.erase(name);
			}
		}

	}


		cout << ans << '\n';


	

	return 0;
}