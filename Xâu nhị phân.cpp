#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[1000];

void danhdau(){
	for(int i=0; i<1000;i++){
		a[i] = 0;
	}
}
// ham dua cac gia tri trong mang ve bang 0
int main(){
	int n; cin >> n;
	int check = 1;
	while(check){
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
}
