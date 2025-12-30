#include <bits/stdc++.h>

using namespace std;

int N;
int board[500][500] = {0};
int result = 0;

int dxy[4][2] = {
	{0,-1},   // Left
	{1,0},    // Down
	{0,1},    // Right
	{-1,0}    // Up
};

bool OutOfBound(int x, int y){
	if(x < 0 || x > N-1 || y < 0 || y > N-1) {
		return true; 
	}
	
	return false;
}

void MakeTornado(int tx, int ty, int ind){
	int amount = board[tx][ty];
	// cout << "amount: " << amount << ", tx: " << tx << ", ty: " << ty << ", ind: " << ind << endl;
	int direction = ind;
	
	board[tx][ty] = 0;

	switch(direction){
		case 0: // from left
			if(!OutOfBound(tx-1, ty+1)) board[tx-1][ty+1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx+1, ty+1)) board[tx+1][ty+1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx-2, ty)) board[tx-2][ty] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx+2, ty)) board[tx+2][ty] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx-1, ty)) board[tx-1][ty] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx+1, ty)) board[tx+1][ty] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx-1, ty-1)) board[tx-1][ty-1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx+1, ty-1)) board[tx+1][ty-1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx, ty-2)) board[tx][ty-2] += (int)(amount * 0.05);
			else result += (int)(amount * 0.05);

			amount -= 2*(int)(amount*0.1) + 2*(int)(amount*0.01) + 2*(int)(amount*0.07)  + 2*(int)(amount*0.02) + (int)(amount*0.05);
			
			// alpha
			if(!OutOfBound(tx, ty-1)) board[tx][ty-1] += amount;
			else result += amount;

			break;
		case 1: // from down
			if(!OutOfBound(tx-1, ty-1)) board[tx-1][ty-1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx-1, ty+1)) board[tx-1][ty+1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx, ty-2)) board[tx][ty-2] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx, ty+2)) board[tx][ty+2] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx, ty-1)) board[tx][ty-1] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx, ty+1)) board[tx][ty+1] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx+1, ty-1)) board[tx+1][ty-1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx+1, ty+1)) board[tx+1][ty+1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx+2, ty)) board[tx+2][ty] += (int)(amount * 0.05);
			else result += (int)(amount * 0.05);

			amount -= 2*(int)(amount*0.1) + 2*(int)(amount*0.01) + 2*(int)(amount*0.07)  + 2*(int)(amount*0.02) + (int)(amount*0.05);

			// alpha
			if(!OutOfBound(tx+1, ty)) board[tx+1][ty] += amount;
			else result += amount;

			break;
		case 2: // from right
			if(!OutOfBound(tx-1, ty-1)) board[tx-1][ty-1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx+1, ty-1)) board[tx+1][ty-1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx-2, ty)) board[tx-2][ty] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx+2, ty)) board[tx+2][ty] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx-1, ty)) board[tx-1][ty] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx+1, ty)) board[tx+1][ty] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx-1, ty+1)) board[tx-1][ty+1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx+1, ty+1)) board[tx+1][ty+1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx, ty+2)) board[tx][ty+2] += (int)(amount * 0.05);
			else result += (int)(amount * 0.05);

			amount -= 2*(int)(amount*0.1) + 2*(int)(amount*0.01) + 2*(int)(amount*0.07)  + 2*(int)(amount*0.02) + (int)(amount*0.05);
			
			// alpha
			if(!OutOfBound(tx, ty+1)) board[tx][ty+1] += amount;
			else result += amount;


			break;
		case 3: // from up
			if(!OutOfBound(tx+1, ty-1)) board[tx+1][ty-1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx+1, ty+1)) board[tx+1][ty+1] += (int)(amount * 0.01);
			else result += (int)(amount * 0.01);

			if(!OutOfBound(tx, ty-2)) board[tx][ty-2] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx, ty+2)) board[tx][ty+2] += (int)(amount * 0.02);
			else result += (int)(amount * 0.02);

			if(!OutOfBound(tx, ty-1)) board[tx][ty-1] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx, ty+1)) board[tx][ty+1] += (int)(amount * 0.07);
			else result += (int)(amount * 0.07);

			if(!OutOfBound(tx-1, ty-1)) board[tx-1][ty-1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx-1, ty+1)) board[tx-1][ty+1] += (int)(amount * 0.1);
			else result += (int)(amount * 0.1);

			if(!OutOfBound(tx-2, ty)) board[tx-2][ty] += (int)(amount * 0.05);
			else result += (int)(amount * 0.05);

			amount -= 2*(int)(amount*0.1) + 2*(int)(amount*0.01) + 2*(int)(amount*0.07)  + 2*(int)(amount*0.02) + (int)(amount*0.05);
			
			// alpha
			if(!OutOfBound(tx-1, ty)) board[tx-1][ty] += amount;
			else result += amount;


			break;
	};
}


void Move(){
	int sx=N/2;
	int sy=N/2;
	int tx=sx;
	int ty=sy;

	for(int i=0;i<N;i++){
		int ind=0;
		if(i%2==1) ind=2;

		for(int j=0;j<2; j++, ind++){
			for(int k=0; k<i+1; k++){
				tx += dxy[ind][0];
				ty += dxy[ind][1];
				
				if(tx<0 || tx>=N || ty<0 || ty>=N) continue;

				MakeTornado(tx, ty, ind);

				if(tx==0 && ty==0) return;
			}
		}
	}
}




int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int n ;
				cin>>n;
				board[i][j] = n;
		}
	}

	Move();
	
	cout << result;

	return 0;
}





