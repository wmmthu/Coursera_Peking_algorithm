#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a > b){
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if(b % a == 0) return a;

	b %= a;
	return gcd(b,a);
}

int main()
{
	int M,N;
	//freopen("test.txt","r",stdin);
	while(cin >> M >> N){
		int r = M % N;
		while(r){
			M = N;
			N = r;
			r = M % N;
		}
		cout << N << endl;
	}
	return 0;
}