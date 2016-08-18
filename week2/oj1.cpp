#include <iostream>
#include <stdio.h>
using namespace std;

//#define DEBUG

char change(char s)
{
	if(s=='w') return 'y';
	else return 'w';
}
void printColor(char d[17][17],int n){
	cout << "color : " << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	#ifdef DEBUG
		freopen("test.txt","r",stdin);
	#endif

	int t,n,o[17][17];
	char raw[17][17],d[17][17];
	int total,min_total=-1;

	cin >> t;
	while(t--){
		min_total=-1;
		// data input
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> raw[i][j];
			}
		}

		// enumarate operation for first line
		for(int e=0;e< 1<<n; e++){
			total = 0;

			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j] = raw[i][j];
					o[i][j] = 0;
				}
			}			

			int tmp = e;
			for(int i=1;i<=n;i++){
				o[1][i] = (tmp % 2);
				tmp /= 2;

				if(o[1][i] == 1){
					total ++ ;
					d[1][i] = change(d[1][i]);
					d[0][i] = change(d[0][i]);
					d[2][i] = change(d[2][i]);
					d[1][i-1] = change(d[1][i-1]);
					d[1][i+1] = change(d[1][i+1]);
				}
			}

			
			// operation
			for(int i=2;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(d[i-1][j] == 'w'){
						o[i][j] = 1;
						total ++;

						d[i][j] = change(d[i][j]);
						d[i-1][j] = change(d[i-1][j]);
						d[i+1][j] = change(d[i+1][j]);
						d[i][j-1] = change(d[i][j-1]);
						d[i][j+1] = change(d[i][j+1]);
					}
				}
			}

			//check
			bool ok = true;
			for(int j = 1;j<=n;j++){
				if(d[n][j] == 'w') ok = false;
			}
			if(ok){
				min_total = (min_total>=0)?(min_total>total?total:min_total):(total);
			}
		}
		if(min_total>=0) cout <<min_total<<endl;
		else cout << "inf" << endl;
	}

	return 0;
}