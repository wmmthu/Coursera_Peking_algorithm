#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int cut[5];
int digits;
int maxSum;
int optimalCut[5];
int target, paper;
vector<int> maxV;

int getDigits(int num)
{
	int r = 0;
	while(num){
		num /= 10;
		r++;
	}
	return r;
}

int getSum()
{
	int p = paper;
	int r = 0;
	int w = 10;
	for(int i=0;i<(digits-1);i++)
	{
		if(cut[i]){
			r += (p%w);
			p /= w;
			w = 10;
		}else{
			w *= 10;
		}
	}
	r += p;
	return r;
}

void printCut()
{
	vector<int> v;
	cout << getSum();
	int p = paper;
	int w = 10;
	for(int i=0;i<(digits-1);i++)
	{
		if(cut[i]){
			v.push_back(p%w);
			p /= w;
			w = 10;
		}else{
			w *= 10;
		}
	}
	v.push_back(p);
	for(int i=v.size()-1;i>=0;i--) cout << " " << v[i];
	cout << endl;
}

void dfs(int depth)
{
	int s = getSum();
	if(depth == 0){
		if(s<=target && s>=maxSum){
			maxSum = s;
			maxV.push_back(s);
			memcpy(optimalCut,cut,sizeof(cut));
		}
	}
	if(depth >= (digits-1)) return;
	
	cut[depth] = 0;
	dfs(depth+1);
	cut[depth] = 1;
	s = getSum();
	if(s<=target && s>=maxSum){
		maxSum = s;
		maxV.push_back(s);
		memcpy(optimalCut,cut,sizeof(cut));
	}
	dfs(depth+1);
	
	cut[depth] = 0;
	
}


int main()
{
	//freopen("test.txt","r",stdin);
	cin >> target >> paper;
	while(target >0){
		maxV.clear();
		digits = getDigits(paper);
		memset(cut,0,sizeof(cut));
		memset(optimalCut,0,sizeof(optimalCut));
		maxSum = -1;
		dfs(0);
		if(maxSum<0) cout << "error" << endl;
		else{
			int count = 0;
			for(int i=0;i<maxV.size();i++){
				if(maxV[i] == maxSum) count++;
			}
			if(count == 1){
				memcpy(cut,optimalCut,sizeof(cut));
				printCut();
			}else{
				cout << "rejected" << endl;
			}
		}

		cin >> target >> paper;
	}
	return 0;
}