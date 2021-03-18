#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
	int n;
	cin >> n;
	
	int* arr=(int *)malloc(sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	
	vector<int> v(30001,0);
	
	v[1]=arr[1];
	v[2]=arr[1] + arr[2];

	for(int i=3;i<=n;i++){
		v[i]=max(arr[i]+v[i-2],max(arr[i]+arr[i-1]+v[i-3],v[i-1]));
	}
	
	printf("%d", v[n]);
	return 0;
}
