#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n; cin >> n;
	int check = 1;
	int a[1000] = {0};
	int cnt = 0; 
	while(check){
		cnt++;
		for(int i=1;i<=n; i++){
			cout << a[i];
		} 
		cout << endl;
		// in ra cac cau hinh thoa man
		int k = n;
		while(k>=1 && a[k]==1){
			// duyet tu phan tu a[k] ve a[1] voi k = n
			a[k] = 0; // neu a[k] = 1, ta dua a[k] ve bang 0
			k--;
		}
		if(k==0) check = 0;
		else a[k] = 1; // neu a[k] = 0, ta dua a[k] ve bang 1
	}
	cout << "So xau nhi phan " << n << " bit la: " << cnt;
}
