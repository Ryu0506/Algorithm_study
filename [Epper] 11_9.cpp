#include <iostream>
using namespace std;

int func(int left,int right){
	if (left==0 && right==0)
		return 1;
	else{
		if(left==0) // 조건문 순서 주의
			return 1;
		else if(left<right) 
			return func(left-1, right) + func(left, right-1);
		else if(left==right)
			return func(left-1, right);
	}	
}

int main() {
	int n=0;
	int num=0;
	cin >> n;
	
	num = func(n,n);
	printf("%d", num);
	
	return 0;
}
