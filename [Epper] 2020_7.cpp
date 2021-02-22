#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second)
		return a.first<b.first;
	else{
		return a.second<b.second;
	}
}
int main() {
	int n;
	int answer=0;
	int s1=-1;
	int s2=-1;
	vector<pair<int,int>> v;
	scanf("%d",&n);
	int *s=(int*)malloc(sizeof(int)*n);
	int *e=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++) scanf(" %d",&s[i]);
	for(int i=0;i<n;i++) scanf(" %d",&e[i]);
	
	for(int i=0;i<n;i++)
		v.push_back({s[i],e[i]});
	
	sort(v.begin(),v.end(),compare);
	
	for(int i=0;i<n;i++){
		if(s1<=v[i].first){
			s1=v[i].second;
			answer++;
		}
		else if(s2<=v[i].first){
			s2=s1;
			s1=v[i].second;
			answer++;
		}
	}
	
	cout<<answer;
	return 0;
}
