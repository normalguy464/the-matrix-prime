#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n; cin >> n;
	bool check = true;
	int a[1000] = {0};
	char b[1000];
	vector<char> v;
	int so_cau_hinh = 0; 
	while(check){
		//cau hinh co dang a[1]a[2]...a[n]
		//cau hinh dau tien la 000..0
		int cnt = 0;
		for(int i=0; i<=n; i++){
			if(abs(a[i+1]-a[i])==1) cnt++; //kiem tra tinh lien tuc cua cac ky tu A
		}
		if(cnt==2){
			so_cau_hinh++;
			for(int i=1; i<=n; i++){
				if(a[i]==1) b[i] = 'A'; //chuyen cac chu so 1 thanh ky tu A
				else b[i] = 'B'; // chuyen cac chu so 0 thanh ky tu B
			}
			for(int i=1; i<=n; i++){
				v.push_back(b[i]);
				}
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
	cout << "So cau hinh thoa man la: " << so_cau_hinh << endl;
	int dem = 0;
	for(auto x2 : v){
		cout << x2; dem++;
		if(dem==n){
			 cout << endl;
			 dem = 0;
		}
	}
	
} 
