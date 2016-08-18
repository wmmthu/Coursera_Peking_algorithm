#include <iostream>
#include <stdio.h>
using namespace std;

//#define DEBUG

const int table[10][5] = {{},{1,2,4,5},{1,2,3},
{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},
{7,8,9},{5,6,8,9}};
int main()
{
	#ifdef DEBUG
		freopen("test2.txt","r",stdin);
	#endif
	
	int c[10];
	for(int i=1;i<=9;i++) cin >> c[i];

	int c2[10];
	int op[10];
	int min_op = 37;
	int min_op_array[10];
	for(int i=0;i<1<<18;i++){
		bool ok = true;
		int tmp = i;
		int tmp_op = 0;
		for(int j=1;j<=9;j++){
			op[j] = (tmp%4);
			tmp/=4;
		}

		for(int j=1;j<=9;j++) c2[j] = c[j];

		for(int j=1;j<=9;j++){
			for(int t = 0;t<5;t++){
				c2[table[j][t]] += op[j];
			}
			tmp_op += op[j];
		}

		for(int j=1;j<=9;j++){
			c2[j] %= 4;
			if(c2[j]>0) ok = false;
		}
		if(ok && tmp_op < min_op){ 
			min_op = tmp_op;
			for(int j=1;j<=9;j++) min_op_array[j] = op[j];
		}
	}

	for(int j = 1;j<=9;j++){
		while(min_op_array[j]--){
			cout << j << " ";
		}
	}

	return 0;
}