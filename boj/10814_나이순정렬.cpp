#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	vector<pair<int, string>> members;
	for(int i=0; i<N;i++) {
		int age;
		string name;
		cin >> age >> name;
		members.push_back(make_pair(age, name));
	}

	stable_sort(members.begin(), members.end(), [](
				const pair<int,string> &a,
				const pair<int, string> &b)
			{
			return a.first < b.first;
			});
	
	for(auto it : members) {
		cout << it.first << " " << it.second << '\n';
	}

	return 0;
}
