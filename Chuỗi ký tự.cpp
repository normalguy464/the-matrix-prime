//Made by DangQuocDung
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n; cin >> n;
	bool check = true;
	int a[1000] = {0};
	char b[1000];
	while(check){
		int cnt = 0;
		for(int i=0; i<=n; i++){
			if(a[i+1]-a[i]==1 || a[i+1] - a[i] == -1) cnt++; //kiem tra tinh lien tuc cua cac ky tu A
		}
		if(cnt==2){
			for(int i=1; i<=n; i++){
				if(a[i]==1) b[i] = 'A'; //chuyen cac chu so 1 thanh ky tu A
				else b[i] = 'B'; // chuyen cac chu so 0 thanh ky tu B
			}
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
		// duyet cac xau nhi phan
	}
} 
