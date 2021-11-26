#include<iostream>
#define MAXN 205
#define MAXW 605
#define MAXH 605
using namespace std;
int W, H, w[MAXW], h[MAXH], N, res[MAXW][MAXH];

void input(){
	cin >> W >> H;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> w[i] >> h[i];
	}
}

void sol(){
	for(int i=1; i<=W; i++){
		for(int j=1; j<=H; j++){
			res[i][j] = i*j;
			for(int k=1; k<=N; k++){
				if(i==w[k] && j==h[k]) res[i][j] = 0;
			}
			for(int k=1; k<i;k++){
				res[i][j] = min(res[i][j], res[k][j] + res[i-k][j]);
			}
			for(int k=1; k<j;k++){
				res[i][j] = min(res[i][j], res[i][k] + res[i][j-k]);
			}
		}
	}
	cout << res[W][H];
}

int main(){
	input();
	sol();
}
