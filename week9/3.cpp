#include <iostream>
#include <cstring>
using namespace std;

int h,n;
int best_lake_time[25];
int best_fish;
int f[25];
int d[25];
int t[25];


int maxArray(int*p, int n)
{
	int r = -1;
	for(int i=0;i<n;i++){
		if(p[i]>r) r = p[i];
	}
	return r;
}

void solve()
{

	int lake_time[25];
	int now_f[25];

	// lakes 0,...,i is used
	// h2 : total time left
	for(int i=0;i<n;i++){
		memcpy(now_f, f, sizeof(f));
		memset(lake_time,0,sizeof(lake_time));
		int fish = 0;
		int h2 = h;
		for(int j=0;j<i;j++) h2 -= t[j];

		while(h2>0){
			int maxf = -1;
			int maxl = -1;
			for(int j=0;j<=i;j++){
				if(now_f[j] > maxf){
					maxf = now_f[j];
					maxl = j;
				}
			}

			lake_time[maxl] ++;
			fish += (maxf);
			now_f[maxl] -= d[maxl];
			if(now_f[maxl] < 0) now_f[maxl] = 0;
			h2 -- ;
		}
		if(fish > best_fish){
			best_fish = fish;
			memcpy(best_lake_time,lake_time,sizeof(lake_time));
		}else if(fish == best_fish){
			for(int j=0;j<=i;j++){
				if(lake_time[j]>best_lake_time[j]){
					memcpy(best_lake_time,lake_time,sizeof(lake_time));
					break;
				}else if(lake_time[j] == best_lake_time[j]) continue;
				else break;
			}
		}
	}
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> n;
	while(n >0){
		cin >> h;
		memset(best_lake_time,0,sizeof(best_lake_time));
		for(int i=0;i<n;i++) cin >> f[i];
		for(int i=0;i<n;i++) cin >> d[i];
		for(int i=0;i<n-1;i++) cin >> t[i];
		h *= 12;
		best_fish = 0;
		solve();
		for(int i=0;i<n;i++){
			cout << best_lake_time[i] * 5;
			if(i<(n-1)) cout <<", ";
		}
		cout << endl << "Number of fish expected: " << best_fish << endl;

		cin >> n;
		if(n > 0) cout << endl;
	}
	return 0;
}