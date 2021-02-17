#include <iostream>
#include <stdio.h>

bool desc(int a, int b) {
	return a > b;
}

using namespace std;
int main() {
	int input[100];
	scanf("%d %d %d %d %d %d %d %d %d", &input[0], &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7], &input[8]);
	int sum = 0;

	for(int i=0;i<9;i++)
		sum+=input[i];
	
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
				if(sum - input[i] - input[j]==100){
					input[i] = -1;
					input[j] = -1;
				}
		}
	}

	for (int k = 0; k < 9; k++){
		if(input[k]!=-1)
			cout<<input[k]<<" ";
	}
	
	return 0;
}
