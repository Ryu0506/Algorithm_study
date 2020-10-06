/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42842
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int wide, height;

	if (brown == (6 + 2 * yellow)) {
		height = 3;
		wide = yellow + 2;
	}
	else if(brown==3*yellow){
		wide = sqrt(yellow) + 2;
		height = sqrt(yellow) + 2;
	}
	else {
		for (int i=2;i<1000000;i++) {
			height = i + 2;
			wide = ((brown - 2 * height) / 2) + 2;
			if (height*wide - yellow == brown)
				break;
		}
	}
	
	answer.push_back(wide);
	answer.push_back(height);

	return answer;
}
