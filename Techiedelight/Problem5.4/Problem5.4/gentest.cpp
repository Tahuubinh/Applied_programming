#include <bits/stdc++.h>
using namespace std;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(int argc, char** argv){
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
	freopen("TSP.inp", "w", stdout);
	int n = random(2, 10);
	int m = random(0, n*(n - 1)/2 );
	cout << n << ' ' << m << endl;
	map < pair <int, int>, int > E;
	while (E.size() < m) {
        int u = random(1,n);
        int v = random(1,n);
        if(u > v) swap (u,v);
        if(u == v) continue;
        int w = random(1,1000);
        E[make_pair(u,v)] = w;
	}
	for (auto it : E) {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        cout << u << ' ' << v << ' ';
        cout << w << endl;
	}
	return 0;
}
