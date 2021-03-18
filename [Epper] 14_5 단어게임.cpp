#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	vector<pair<string,int>> str;
	vector<char> ch;
	
	string s;
	char c;
	
	for(int i=0;i<n;i++){
		cin>>s;
		str.push_back({s,0});
	}
	for(int i=0;i<m;i++){
		cin>>c;
		ch.push_back(c);
	}
	
	sort(str.begin(),str.end());
	int* flag=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<m;i++){
		int count=0;
		c=ch[i];
		for(int j=0;j<n;j++){
			if(c==str[j].first.at(0)){
				flag[count++]=j;
			}
		}
		if(count==1){
			cout<<str[flag[0]].first<<endl;
			str[flag[0]].second++;
		}
		else{
			int min=str[flag[0]].second;
			int pos=flag[0];
			for(int k=1;k<count;k++){
				if(min>str[flag[k]].second){
					min=str[flag[k]].second;
					pos=flag[k];
				}
			}
			cout<<str[pos].first<<endl;
			str[pos].second++;
		}
		
	}
	
	return 0;
}
