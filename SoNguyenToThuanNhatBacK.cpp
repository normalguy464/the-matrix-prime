#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sapxep(int a[], int n, int t){
	for(int i=t; i<=n-1; i++){
		for(int j=i+1; j<=n; j++){
			if(a[j]<a[i]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
// ham dung de sap xep cac phan tu trong mang theo thu tu tang dan
// sap xep tu phan tu thu t den phan tu thu n

bool prime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}
// ham kiem tra so nguyen to
int main(){
	int n , k; cin >> n >> k;
	int a[1000]; a[0] = 0;
	for(int i=1 ; i<=n; i++){
		cin >> a[i];
	}
	sort(a, a+n); //sap xep cac phan tu trong mang theo thu tu tang dan
	//gia su cau hinh co dang a[0]a[1]...a[n].
	bool check = true;
	while(check){
		int t = 0; int res1 = 0;
		for(int i=1; i<n; i++){
			if(a[i+1]-a[i]>0) t = i+1; 
			if(t>res1) res1 = t; //chon ra chi so t lon nhat, luu t vao bien ki luc res1
		}
		int res2 = INT_MAX;
		for(int i=res1; i<=n; i++){
			if(a[i]>a[res1-1] && a[i]<res2){
				res2 = a[i];
				// tim a[i] sao cho a[i] la so nho nhat trong khoang a[res1]->a[n]
				// va a[i] > a[res-1]
				// luu a[i] vao bien ki luc res2
			}
		}
		for(int i=1; i<=n; i++){
			if(a[i]==res2){
				int temp = a[res1-1]; // doi cho 2 phan tu a[i] va a[res-1] de thuc hien sap xep
				a[res1-1] = a[i];
				a[i] = temp;
			}
		}
		sapxep(a,n,res1);
		bool kiemtra = 1;
		for(int i=1; i<=n-k+1; i++){
			int z = 0;
			for(int j=i; j<=i+k-1; j++){
				z+=a[j];
				}
			if(prime(z)==0) kiemtra = 0; // kiem tra xem tong k phan tu lien tiep bat ki có phai so nguyen to
			}
		if(kiemtra){
			for(int i=1; i<=n; i++){
				cout << a[i] << " "; // in ra cac truong hop thoa man.
				}
			cout << endl;
			}
		int cnt = 0;
		for(int i=1; i<n; i++){
			if(a[i+1]-a[i]<0) cnt++;
		}
		if(cnt==n-1) check = false; //kiem tra xem a[i+1]-a[i]>0 voi moi i.
		}
	}
