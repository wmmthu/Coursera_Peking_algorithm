#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int N,C,tmp,l,r,mid;
int v[100001];

int check(int x)
{
	for(int i=0;i<=0;i++){
		int now,num;
		now = v[i];
		num = 1;
		for(int j=i+1;j<N;j++){
			if((N-i) < (C - num)) return 0;

			if((v[j] - now)>=x){
				now = v[j];
				num ++;
			}

			if(num == C) return 1;
		}
	}
	return 0;
}

void qsort(int* p, int n)
{
	int key = p[n-1];
	int i=-1,tmp;
	for(int j=0;j<(n-1);j++){
		if(p[j] < key){
			i ++;
			tmp = p[j];
			p[j] = p[i];
			p[i] = tmp;
		}
	}
	i ++;
	p[n-1] = p[i];
	p[i] = key;
	if(i>0) qsort(p,i);
	if(n-i-1 > 0) qsort(p+i+1,n-i-1);
}

int main()
{
	//freopen("test.txt","r",stdin);
	cin >> N >> C;
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	//qsort(v,N);
	sort(v,v+N);

	l = 0;
	r = (v[N-1] - v[0]) / (C - 1);

	while(l<=r){
		mid = (l+r)/2 ;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}

	cout << r << endl;
	return 0;
}