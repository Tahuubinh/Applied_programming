#include <bits/stdc++.h>

using namespace std;
int num1(int from, int to, int d)
{
	int f = from;
	int t = 0;
	int step = 1; // Needed to fill "from" Jug

	while (f != d && t != d)
	{
		int temp = min(f, to - t);
		t += temp;
		f -= temp;

		step++;

		if (f == d || t == d)
			break;
		if (f == 0)
		{
			f = from;
			step++;
		}
		if (t == to)
		{
			t = 0;
			step++;
		}
	}
	return step;
}
int main(){
    clock_t t1, t2, t3;
    int a = 1000000;
    int b = 231;
    int result;
    auto t_start = std::chrono::high_resolution_clock::now();
    int buffer = a / b;
    result = a - buffer*b;
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    std::chrono::duration<double> elapsed = t_end-t_start;
    cout << elapsed<< endl;
    //cout << result << endl;
    t2 = clock();
    result = a % b;
    //cout << result << endl;
    t3 = clock();
    //cout << (double)(t3 - t2)*1000 << endl << (double)(t2 - t1)*1000 << endl;
    return 0;
}