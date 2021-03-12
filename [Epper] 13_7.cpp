#include <iostream>
#include <stdlib.h>

using namespace std;
	
int solution(int n, int* arr, int start, int end) {
    int answer = 0;
		while(start!=(n/2-1) || end!=n/2){
			if(arr[start]!=arr[end]){
				if(arr[start]<arr[end]){
					arr[start+1]=arr[start] + arr[start+1];
					answer++;
					end+=1;
				}
				else{
					arr[end-1]=arr[end] + arr[end-1];
					answer++;
					start-=1;
				}
			}
			start+=1;
			end-=1;
		}	
	  return answer;
}

int main(void) {
    int n, i;
    int start = 0;
    int end = 0;
	
    cin >> n;
		int* arr = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
		
    end = n - 1;

    cout << solution(n, arr, start, end);

    return 0;
}
