#include <iostream>
#include <vector>
#include <complex>
using namespace std;

const double PI = 4 * atan(1);

//int revBit(int nbit, int mask)
//{
//    int i = 0;
//    int j = nbit - 1;
//    while(i <= j)
//    {
//        if( (mask >> i & 1) != (mask >> j & 1) )
//        {
//            mask ^= 1<<i;
//            mask ^= 1<<j;
//        }
//        ++i;
//        --j;
//    }
//    return mask;
//}

void FFT(int n, vector<complex<double>> &A, bool revert){
    if (n == 1) return;
//    int j;
//    for(int i = 1; i < n; ++i)
//    {
//        j = revBit(NBIT, i);
//        if(i < j) swap(A[i], A[j]);
//    }

	int j = 0;
	for(int i = 1; i < n; ++i){
		int bit = n >> 1;
		while(j >= bit){
			j = j - bit;
            bit = bit >> 1;
        }
		j = j + bit;
		if (i < j){
			swap (A[i], A[j]);
		}
	}

	for(int len = 2; len <= n; len <<= 1){
		double ang = 2 * PI / len; // x^len - 1
        if(revert) ang = -ang;
		complex<double> first_complex_root(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			complex<double> w(1);   // root will be like cos + isin, 1 is always a root of x^ - 1 = 0
			int half_len = len >> 1;
			for (int j = 0; j < half_len; ++j) {
				complex<double> u = A[i + j];
				complex<double> v = A[i + j + half_len] * w;
				A[i + j] = u + v;
				A[i + j + half_len] = u - v;
				w = w * first_complex_root; // next root
			}
		}
	}

//	for(int step = 1; step < n; step <<= 1)
//    {
//        double ang = PI / step;
//        if (revert) ang = -ang;
//
//        complex<double> w(1, 0), wn (cos(ang), sin(ang));
//
//        for(int i = 0; i < step; ++i)
//        {
//            W[i] = w;
//            w *= wn;
//        }
//
//        int start_even = 0;
//        int start_odd  = start_even + step;
//        while(start_even < n)
//        {
//            for(int i = 0; i < step; ++i)
//            {
//                anext[start_even + i]        = A[start_even + i] + W[i] * A[start_odd + i];
//                anext[start_even + i + step] = A[start_even + i] - W[i] * A[start_odd + i];
//            }
//            start_even += 2*step;
//            start_odd   = start_even + step;
//        }
//        for(int = 0; i < n; ++i)
//            A[i] = anext[i];
//    }

	if(revert){
		for(int i = 0; i < n; ++i){
			A[i] /= n;
        }
	}
}

int multiplyPoly(int n, vector<complex<double>> A, int m, vector<complex<double>> B){
    int p = 1;
	while(p <= max (n, m)){ // Complexity of the whole algo is p * log(p), p is the first power of 2 that not less than m, n
        p = p << 1;
	}
	p = p << 1; // deg of prod not less than sum of the two factors
	A.resize(p);
    B.resize(p);
	FFT(p, A, false);
    FFT(p, B, false);

    vector<complex<double>> product(p);
	for (int i = 0; i < p; i++)
		product[i] = A[i] * B[i];
	FFT(p, product, true);

//    for (int i = 0; i <= p; ++i){
//        cout << real(product[i]) << ' ' << imag(product[i]) << endl;
//    }
	int res = (int)(real(product[0]) + 0.5); // If not + 0.5, the result might not be exactly the real part
	for (int i = 1; i <= p; ++i){
		res = res ^ (int)(real(product[i]) + 0.5);
	}

    return res;
}

int main(){
    int n, m;
    complex<double> input;
    vector<complex<double>> A,B;

    cin >> n;
    for(int i = 0; i <= n; ++i){
        cin >> input;
        A.push_back(input);
    }

    cin >> m;
    for(int i = 0; i <= m; ++i){
        cin >> input;
        B.push_back(input);
    }

    cout << multiplyPoly(n, A, m, B);
    return 0;
}
