#include <iostream>
using namespace std;

long long solve(int N)
{
	int lastN = 1;
	bool flag = false;
	long long tmp;
	while(!flag){
		flag = true;
		tmp = N * lastN + 1;
		for(int i = N - 1;i>=1;i--){
			if(tmp % (N-1)){
				flag = false;
				break;
			}else{
				tmp = (tmp*N)/(N-1) + 1;
			}
		}
		if(!flag){
			lastN ++;
		}
	}
	return tmp;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int N;
	cin >> N;
	while(N>0){
		cout << solve(N) << endl;
		cin >> N;
	}
	return 0;
}