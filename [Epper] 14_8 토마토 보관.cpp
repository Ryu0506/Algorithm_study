// 실제 시험에서는 solution 함수를 사용한다는 점을 감안하고 풀이해주세요.
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility> //pair 사용위해

using namespace std;
int main() {
	int n,m;
	int num=0; //초기화 해주기
	int x,y;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	int **tomato = (int **)malloc(sizeof(int*)*m);
	for(int i=0;i<m;i++)
		tomato[i]=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&tomato[i][j]);
	}

	queue<pair<int, int>> q; // pair queue 만들기
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(tomato[i][j]==0) num+=1;
			else if(tomato[i][j]==1) q.push(make_pair(i,j)); //make_pair
		}
	}
	
	int vectX[4]={-1,1,0,0};
	int vectY[4]={0,0,1,-1};
	
	while(!q.empty()){ //비어있지 않은 경우
		x=q.front().first;
		y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nearX = x+vectX[i];
			int nearY = y+vectY[i];
			
			if((nearX>=0 && nearX<m) && (nearY>=0 && nearY<n)){
				if(tomato[nearX][nearY]==0){
					num--;
					tomato[nearX][nearY]=tomato[x][y]+1;
					q.push(make_pair(nearX, nearY));
				}
			}
		}
	}
	
	if(num==0) printf("%d", tomato[x][y]-1);
	else printf("%d", -1);
	
	return 0;
}
