#include <iostream>
using namespace std;


int sum(int* pa, int a, int* pb, int b, int s)
{
	int result = 0;

	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if((pa[i]+pb[j]) == s) result++;
		}
	}

	return result;
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,s,a,b;
	int *pa, *pb;
	cin >> n;
	while(n--){
		cin >> s;
		cin >> a;
		pa = new int[a+1];
		for(int i=1;i<=a;i++) cin >> pa[i];
		cin >> b;
		pb = new int[b+1];
		for(int i=1;i<=b;i++) cin >> pb[i];

		cout << sum(pa,a,pb,b,s) << endl;

		delete [] pa;
		delete [] pb;
	}
	return 0;
}