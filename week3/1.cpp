#include <iostream>
using namespace std;

int main()
{
    int num[31];
    int cum[31];
    for(int i=0;i<31;i++){
    	num[i] = 0; 
    	cum[i] = 0;
    }

    num[0] = 1;
    num[2] = 3;
    cum[0] = 1;
    cum[2] = 4;   

    for(int i = 4; i<= 30;i+=2){
        num[i]  = num[i-2] + 2*cum[i-2];
        //printf("%d %d\n",i,num[i]);
        cum[i]  = cum[i-2] + num[i];
    }
    int n;
    cin >> n;
    while(n>=0){
    	cout << num[n] << endl;
    	cin >> n;
    }
    return 0;
}
