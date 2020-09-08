/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42579
개념 설명 : 
*/

// 내가 푼 
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> g;
	vector<int> p;
	vector<int> idx;
	unordered_map<string, int> hash;

	for (int i = 0; i < genres.size(); i++)
		idx.push_back(i);
	for (int i = 0; i < genres.size(); i++) {
		if (hash[genres[i]] == 0) {
			hash[genres[i]] += plays[i];
			g.push_back(genres[i]);
		}
		else
			hash[genres[i]] += plays[i];
	}
	
	for (int i = 0; i < g.size();i++) 
		p.push_back(hash[g[i]]);
	
	for (int i = 1; i < g.size(); i++) {
		int temp1, j;
		string temp2;
		temp1 = p[i];
		temp2 = g[i];
		for (j = i - 1; j >= 0; j--) {
			if (p[j] > temp1) break;
			g[j + 1] = g[j];
			p[j + 1] = p[j];	
		}
		g[j + 1] = temp2;
		p[j + 1] = temp1;
	}
	
	for (int i = 1; i < plays.size(); i++) {
		int temp1, temp3, j;
		string temp2;
		temp1 = plays[i];
		temp2 = genres[i];
		temp3 = idx[i];
		for (j = i - 1; j >= 0; j--) {
			if (plays[j] < temp1) break; 
			plays[j + 1] = plays[j];
			genres[j + 1] = genres[j];
			idx[j + 1] = idx[j];
			
		}
		genres[j + 1] = temp2;
		plays[j + 1] = temp1;
		idx[j + 1] = temp3;
	}
	for (int i = 1; i < genres.size(); i++) {
		int temp1, temp3, j;
		string temp2;
		temp1 = plays[i];
		temp2 = genres[i];
		temp3 = idx[i];
		for (j = i - 1; j >= 0; j--) {
			if (genres[j] <= temp2) break;
			plays[j + 1] = plays[j];
			genres[j + 1] = genres[j];
			idx[j + 1] = idx[j];
		}
		genres[j + 1] = temp2;
		plays[j + 1] = temp1;
		idx[j + 1] = temp3;
	}

	int n = g.size();
	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = genres.size()-1; j >=0 ; j--) {
			if (genres[j].compare(g[i]) == 0) {
				if (num == 2) break;
				answer.push_back(idx[j]);
				num++;
			}
		}
	}

	return answer;
}

// short ver.
