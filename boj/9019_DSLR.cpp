#include <bits/stdc++.h>



using namespace std;




bool visited[10001];







// int DSLR(int in, int mode) {
// 	string sin;




// 	if(in >= 1000) {
// 		sin = to_string(in);
// 	}
// 	else if(in >= 100) {
// 		sin = to_string(in);
// 		sin = '0' + sin;
// 	}
// 	else if(in >= 10) {
// 		sin = to_string(in);
// 		sin = "00" + sin;
// 	}
// 	else {
// 		sin = to_string(in);
// 		sin = "000" + sin;
// 	}






// 	int a,b,c,d;
// 	// cout << sin[0] << ", " << sin[1] << ", " << sin[2] << ", " << sin[3] << ", " << in << endl;
// 	a = sin[0] - '0';
// 	b = sin[1] - '0';
// 	c = sin[2] - '0';
// 	d = sin[3] - '0';


// 	int ret;

// 	switch(mode) {
// 		case(0): //D

// 		ret = in*2;
// 		if(ret > 9999) ret %= 10000;

// 		break;


// 		case(1): //S
// 		ret = in-1;

// 		if(ret <= 0) ret = 9999;

// 		break;



// 		case(2): //L
// 			ret = b*1000 + c*100 + d*10 + a;

// 		break;


// 		case(3): //R
// 			ret = d*1000 + a*100 + b*10 + c;

// 		break;


// 	}


// return ret;
// }


int DSLR(int in, int mode) {

	int ret;



	switch(mode) {
		case(0):
		ret = (in*2) % 10000;
		break;

		case(1):
		ret = in == 0 ? 9999 : in-1;
		break;

		case(2):
		ret = (in%1000) * 10 + (in/1000);
		break;

		case(3):
		ret = (in%10) * 1000 + (in/10);
		break;
	}




	return ret;
}









string bfs(int in, int target) {
	queue<pair<string, int>> Q;

	Q.push(make_pair("",in));





	while(!Q.empty()) {
		int qsize = Q.size();


		for(int i=0; i<qsize; i++) {
			string prev = Q.front().first;

			int n = Q.front().second;

			Q.pop();




			if(n == target) {
				return prev;
			}





			for(int d=0; d<4; d++) {
				int nn = DSLR(n, d);




				if(visited[nn]) continue;

				visited[nn] = true;



				
				if(d==0) {
					Q.push(make_pair(prev+'D', nn));
				}
				else if(d==1) {
					Q.push(make_pair(prev+'S', nn));
				}
				else if(d==2) {
					Q.push(make_pair(prev+'L', nn));
				}
				else if(d==3) {
					Q.push(make_pair(prev+'R', nn));
				}

				// cout << "n: " << n << ", nn: " << nn << ", ret: " << Q.front().first << ", d: " << d << endl;


			}
		}
	}

}










int main() {
	int T;

	cin >> T;




	while(T--) {
		int in, target;
		
		cin >> in >> target;


		string ans = bfs(in, target);


		memset(visited, 0, sizeof(visited));


		cout << ans << '\n';
	}



	

	return 0;
}