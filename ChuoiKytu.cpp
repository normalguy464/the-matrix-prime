#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[10000];
char b[10000];
void mang(){
	for(int i=0; i<10000; i++){
		a[i] = 0;
	}
}
// ham danh dau mang a[10000] co cac phan tu bang 0

int main(){
	int n; cin >> n;
	bool check = true;
	while(check){
		int cnt = 0;
		for(int i=0; i<=n; i++){
			if(a[i+1]-a[i]==1 || a[i+1] - a[i] == -1) cnt++;
		}
		if(cnt==2){
			for(int i=1; i<=n; i++){
				cout << b[i];
			}
					cout << endl;
		}
		int k = n;
		while(a[k]==1 && k!=0){
			a[k] = 0;
			k--;
		}
		a[k] = 1;
		if(k==0) check = false;
		for(int i=1; i<=n; i++){
			if(a[i]==1) b[i] = 'A';
			else b[i] = 'B';
		}
	}
} 