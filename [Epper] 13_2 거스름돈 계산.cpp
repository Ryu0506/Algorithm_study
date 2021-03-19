#include <iostream>
using namespace std;
int main() {
	int n;
	int ways[10000];
	
	scanf("%d", &n);
	ways[1]=1;
	ways[2]=2;
	for(int i=3;i<100;i++)
		ways[i]=ways[i-2]+ways[i-1];
	
	printf("계단의 수를 입력하시오 : 계단 오르는 방법의 수 : %d", ways[n]);
	return 0;
}
