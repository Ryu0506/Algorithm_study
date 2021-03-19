#include <iostream>
using namespace std;
int main() {
	int room_n;//방 번호
	int in_n; //방 안에서의 번호
	int num;
	
	scanf("%d",&num);
	
	if(num/15==0){
		room_n=1;
		in_n=num;
	}
	else if(num%15==0){
		room_n=num/15;
		in_n=15;
	}
	else{
		room_n=(num/15)+1;
		in_n=num%15;
	}
	
	printf("%d %d", room_n, in_n);
	return 0;
}
