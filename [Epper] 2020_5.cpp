#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	string input;
	vector<char> answer;
	cin >> input;
	int n=1;
	
	if(input[0]=='1')	answer.push_back('1');
	for(int i=0;i<input.length();i++){
		if(input[i]==input[i+1]) n++;
		else {
			answer.push_back(n+'A'-1);
			n=1;
		}
	}
	for(int i=0;i<answer.size();i++)
		cout<<answer[i];

	return 0;
}
