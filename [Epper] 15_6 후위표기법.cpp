#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
int main() {
	int m;
	cin>>m;
	int a,b;
	int answer;
	char* input = (char*)malloc(sizeof(char) * m);
	stack<int> s;
	
	for(int i=0;i<m;i++)
		scanf(" %c", &input[i]);
	
	for(int j=0;j<m;j++){
		if(input[j]>='0' && input[j]<='9'){
			s.push(input[j]-'0');
		}
		else{
			switch(input[j]){
				case '+':
					a = s.top();
					s.pop();
					b = s.top();
					s.pop();
					s.push(a+b);
					break;
					
				case '-':
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				s.push(b-a);
				break;
					
				case '*':
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				s.push(a*b);
				break;
					
				case '/':
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				s.push(b/a);
				break;
			}
		}
	}
	
	cout<<s.top();
	return 0;
}
