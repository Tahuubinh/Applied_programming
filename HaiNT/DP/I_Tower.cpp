//5-I.Tower
#include <iostream>
#include <algorithm>
using namespace std;
int x[1000], y[1000], z[1000], res[1000], d[1000];

bool init(int x1, int y1, int x2, int y2){
	return (x1 < x2 && y1 < y2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, _case = 0;
	while(1){
		_case ++;
		cin >> n;
		if(n==0) break;
		for(int i=0; i<n; i++){
			cin >> x[6*i+1] >> y[6*i+1] >> z[6*i+1];
			x[6*i+2] = y[6*i+1];
			y[6*i+2] = z[6*i+1];
			z[6*i+2] = x[6*i+1];

			x[6*i+3] = z[6*i+1];
			y[6*i+3] = x[6*i+1];
			z[6*i+3] = y[6*i+1];

			x[6*i+4] = y[6*i+1];
			y[6*i+4] = x[6*i+1];
			z[6*i+4] = z[6*i+1];

			x[6*i+5] = x[6*i+1];
			y[6*i+5] = z[6*i+1];
			z[6*i+5] = y[6*i+1];

			x[6*i+6] = z[6*i+1];
			y[6*i+6] = y[6*i+1];
			z[6*i+6] = x[6*i+1];
		}
//
//		for(int i=1; i<=6*n; i++){
//			cout << x[i] << " " << y[i] << " " << z[i] << endl;
//		}
		for(int i=1; i<6*n; i++){
			for(int j=i+1; j<=6*n; j++){
				if(x[i] < x[j]){
					swap(x[i], x[j]);
					swap(y[i], y[j]);
					swap(z[i], z[j]);
				}
			}
		}
		for(int i=1; i<=6*n; i++){
			res[i] = z[i];
		}
		res[0] = 0;
		for(int i=1; i<=6*n; i++){
			for(int j=1; j<i;j++){
				if(init(x[i], y[i], x[j], y[j])){
					res[i] = max(res[i], res[j] + z[i]);
				}
			}
		}
//		for(int i=1; i<n*6+1; i++){
//			cout << x[i] << " "<< y[i] << " " <<z[i] << " " << res[i] << endl;
//		}
		cout << "Case " << _case << ": maximum height = "  << *max_element(res+1, res+1+6*n) << endl;

	}
}
