#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("test.txt","r",stdin);
	int N,S,x,y,minx;
	long long cost = 0;
	vector<int> v;
	cin >> N >> S;

	for(int i=0;i<N;i++){
		cin >> x >> y;
		minx = x;
		for(int j=0;j<v.size();j++){
			v[j] += S;
			if(v[j] < minx) minx = v[j];
		}
		cost += (minx * y);
		v.push_back(x);
	}
	cout << cost << endl;
	return 0;
}