#include <iostream>
using namespace std;

int minArea(int N)
{
	int l,w,h,minA,tmp;
	minA = N * 6;
	for(h=1;h<=N;h++){
		if(N%h) continue;
		for(l=1;l<=N/h;l++){
			for(w=1;w<=l;w++){
				if(h*l*w == N){
					tmp = 2*w*l + 2 * (w+l) * h;
					if(tmp < minA) minA = tmp;
				}
			}
		}
	}
	return minA;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int N,C;
	cin >> C;
	while(C--){
		cin >> N;
		cout << minArea(N) << endl;
	}
	return 0;
}