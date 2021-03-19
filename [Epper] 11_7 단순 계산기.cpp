#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

double solution(int num_arr[], int n){
	double sol;
	sort(num_arr, num_arr+n);
	if(n==1){
		return num_arr[0];
	}
	sol=(num_arr[0] + num_arr[1])/2.0;
	
	for(int i=2;i<n;i++){
		sol = (num_arr[i]+sol)/2.0;
	}
	
	return sol;
}

int main() {
	int n;
	
	cin >> n;
	int *num_arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> num_arr[i];

	printf("%.6f\n", solution(num_arr,n));
}
