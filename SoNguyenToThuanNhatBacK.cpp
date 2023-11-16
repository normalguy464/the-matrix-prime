#include<bits/stdc++.h>

using namespace std;

#define ll long long

int N, K, X[100], used[100], a[100];
int so_cau_hinh = 0; 
vector<int> v;

//ham in ra cac cau hinh thoa man
void inkq(){
	int dem = 0;
	for(auto x : v){
		cout << x << " "; dem++;
		if(dem == N){
			cout << endl;
			dem = 0;
		}
	}
}

//ham kiem tra so nguyen to
bool prime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}

//ham kiem tra tong k so lien tiep co phai so nguyen to
bool tong_nguyen_to(int X[]){
	for(int i=1; i<=N-K+1; i++){
		int z = 0;
		for(int j=i; j<=i+K-1; j++){
			z+=X[j];
		}
		if(prime(z)==0) return 0;
	}
	return 1;
} 

//dung thuat toan quay lui de duyet cac cau hinh
void Try(int i){
	for(int j=1; j<=N ;j++){
		if(used[j]==0){
			X[i] = a[j];
			used[j] = 1;
			if(i == N && tong_nguyen_to(X)){
				so_cau_hinh++;
			for(int i=1; i<=N; i++)  v.push_back(X[i]);
			}
			else{
				Try(i+1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> a[i];
	}
	sort(a,a+N);
	Try(1);
	cout << "So cau hinh thoa man la: " << so_cau_hinh << endl;
	inkq(); 
	return 0;
}
