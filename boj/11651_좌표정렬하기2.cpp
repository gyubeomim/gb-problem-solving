#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int,int>> coords;

	for(int i=0; i<N;i++){
		int x,y;
		cin >> x>>y;

		coords.push_back(make_pair(x,y));
	}

	sort(coords.begin(), coords.end(), [](
				const pair<int,int> &a,
				const pair<int,int> &b) 
			{
			if(a.second != b.second) {
			return a.second < b.second;
			}
			else {
			return a.first < b.first;
			}
			});

	for(auto it : coords) {
		cout << it.first << " " << it.second << '\n';
	}


	return 0;
}
