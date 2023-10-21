#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sapxep(int a[], int n, int t){
	for(int i=t; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[j]<a[i]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

bool prime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	int n , k; cin >> n >> k;
	int a[1000]; a[0] = 0;
	for(int i=1 ; i<=n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	bool check = true;
	while(check){
		int t = 0; int res1 = 0;
		for(int i=1; i<n; i++){
			if(a[i+1]-a[i]>0) t = i+1;
			if(t>res1) res1 = t;
		}
		int res2 = INT_MAX;
		for(int i=res1; i<=n; i++){
			if(a[i]>a[res1-1] && a[i]<res2){
				res2 = a[i];
			}
		}
		for(int i=1; i<=n; i++){
			if(a[i]==res2){
				int temp = a[res1-1];
				a[res1-1] = a[i];
				a[i] = temp;
			}
		}
		sapxep(a,n,res1);
		int cnt = 0;
		for(int i=1; i<n; i++){
			if(a[i+1]-a[i]<0) cnt++;
		}
		if(cnt==n-1) check = false;
		bool kiemtra = 1;
		for(int i=1; i<=n-2; i++){
			if(prime(a[i]+a[i+1]+a[i+2])==0) kiemtra = 0; 
			}
		if(kiemtra){
			for(int i=1; i<=n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
		}
	}
