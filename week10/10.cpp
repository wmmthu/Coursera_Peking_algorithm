#include <iostream>
#include <cstring>
using namespace std;

long long F[20000][4];
int t[4]; // VV:0, VL:1, LV:2, LL:3

int g(int x, int y, int z, int w)
{
	return ((x*(t[1]+1)+y)*(t[2]+1) + z) * (t[3]+1) + w;
}

long long f(int *num, int k, int goal)
{
	if(num[0] <0 || num[1] <0||num[2]<0||num[3]<0) return 0;

	if(F[g(num[0],num[1],num[2],num[3])][goal]!=-1)
		return F[g(num[0],num[1],num[2],num[3])][goal];

	if(k==1) return (num[goal]>0);
	int temp[4] = {num[0],num[1],num[2],num[3]};
	int l=goal&2, r=goal&1;
	temp[l] -- ;
	F[g(num[0],num[1],num[2],num[3])][goal] = f(temp,k-1,r);
	temp[l] ++;
	temp[l+1] --;
	F[g(num[0],num[1],num[2],num[3])][goal] += f(temp, k-1,r+2);
	return F[g(num[0],num[1],num[2],num[3])][goal];
}

int main()
{
	//freopen("test.txt","r",stdin);
	int n,k,goal;
	char c1,c2;
	while(cin >> n >> k){
		cin >> c1 >> c2;
		memset(F,-1,sizeof(F));
		memset(t,0,sizeof(t));
		goal = (c1=='L') + ((c2=='L') <<1);
		for(int i=0;i<n;i++){
			cin >> c1 >> c2;
			t[((c1=='L')<<1)+(c2=='L')]++;
		}
		long long ans = f(t,k,goal);
		if(ans) cout << "YES" << endl << ans << endl;
		else cout << "NO" << endl;

	}
	return 0;
}