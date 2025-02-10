#include <bits/stdc++.h>
 
using namespace std;
 
int n, q[100], cross1[100] = {0}, cross2[100] = {0}, col[100] = {0};
int cnt = 0;
 
void print(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(q[i] == j) cout << "Q ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
 
}
 
void backTrack(int i){
 
	for(int j = 1; j <= n; j++){
		if(col[j] == 0 && cross1[i - j + n] == 0 && cross2[i + j - 1] == 0){
			q[i] = j;
			col[j] = cross1[i - j + n] = cross2[i + j - 1] = 1;
			if(i == n){
				print();
				cnt ++;
			}
			else{
				backTrack(i + 1);
			}
			col[j] = cross1[i - j + n] = cross2[i + j - 1] = 0;
		}
	}
}
 
void reset() {

	fill(q, q + 100, 0);
	fill(col, col + 100, 0);
	fill(cross1, cross1 + 100, 0);
	fill(cross2, cross2 + 100, 0);
	cnt = 0;
}
 
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		backTrack(1);
		
		reset();  
	}
}
