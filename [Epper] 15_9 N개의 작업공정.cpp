#include <cstdio>
#include <queue>
#define MAX 101
#include <algorithm>

using namespace std;
int adj[MAX][MAX]={0, };
int indegree[MAX]={0, };
int tm[MAX]={0, };

int solution(int n[],int r[][100],int goal,int N,int R){
	int answer=0;
	queue<int> q;
	int u,v;
	
	for(int i=0;i<R;i++){
		u=r[i][0];
		v=r[i][1];
		adj[u][v]=1;
		indegree[v]++;
	}
	
	for(int i=1;i<=N;i++){
		if(indegree[i]==0){
			tm[i]=n[i-1];
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=1;i<=N;i++){
			if(adj[p][i]==1){
				tm[i]=max(tm[i],tm[p]+n[i-1]); // 시간계산 
				indegree[i]--;
				if(indegree[i]==0) q.push(i);
			}
		}
	}
	return tm[goal];
}


int main() {
    int N;
    int R;
    int n[100] = {0};
    int r[100][100] = {0};
    int goal, k;

    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
	
    for (int k = 0; k < R; k++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &r[k][j]);
        }
    }

    scanf("%d", &goal);
    k = solution(n, r, goal, N, R);
    printf("%d\n", k);
}
