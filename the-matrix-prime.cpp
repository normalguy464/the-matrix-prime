#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[100005] = {0};

void prime(){
	a[0] = a[1] = 1;
	for(int i=2; i<=sqrt(100005); i++){
		for(int j=i*i; j<=100005; j+=i){
			a[j] = 1;
		}
	}
}

bool check(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int tong(int n){
	int sum = 0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

bool dem(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n/=10;
	}
	if(cnt==5) return 1;
	else return 0;
}

int main(){
	int s; cin >> s;
	prime();
	string c[1005]; int k = 0; 
	int b[5][5];
	for(int i=2; i<=100005; i++){
		if(a[i]!=1 && tong(i)==s && dem(i)){
		c[k] = to_string(i);
		k++;
	}
	}
		for(int x0=0; x0<k; x0++){
			char d[5][5];
		//hang0
				d[0][0] = c[x0][0]; d[0][1] = c[x0][1]; d[0][2] = c[x0][2]; d[0][3] = c[x0][3]; d[0][4] = c[x0][4];
		//cot0
		for(int y0=0; y0<k ;y0++){
			if(c[y0][0]==d[0][0]){
				d[1][0] = c[y0][1]; d[2][0] = c[y0][2]; d[3][0] = c[y0][3]; d[4][0] = c[y0][4];
		//cheophu
		for(int t1=0; t1<k; t1++){
			if(c[t1][0]==d[4][0] && c[t1][4]==d[0][4]){
				d[3][1] = c[t1][1]; d[2][2] = c[t1][2]; d[1][3] = c[t1][3];
		//hang1
		for(int x1=0; x1<k; x1++){
			if(c[x1][0]==d[1][0] && c[x1][3]==d[1][3]){
				d[1][1] = c[x1][1]; d[1][2] = c[x1][2]; d[1][4] = c[x1][4];
		//cot1
		for(int y1=0; y1<k; y1++){
			if(c[y1][0]==d[0][1] && c[y1][1]==d[1][1] && c[y1][3]==d[3][1]){
				d[2][1] = c[y1][2]; d[4][1] = c[y1][4];
		//hang2
		for(int x2=0; x2<k; x2++){
			if(c[x2][0]==d[2][0] && c[x2][1]==d[2][1] && c[x2][2]==d[2][2]){
				d[2][3] = c[x2][3]; d[2][4] = c[x2][4];
		//cot2
		for(int y2=0; y2<k; y2++){
			if(c[y2][0]==d[0][2] && c[y2][1]==d[1][2] && c[y2][2]==d[2][2]){
				d[3][2] = c[y2][3]; d[4][2] = c[y2][4];
		//hang3
		for(int x3=0; x3<k; x3++){
			if(c[x3][0]==d[3][0] && c[x3][1]==d[3][1] && c[x3][2]==d[3][2]){
				d[3][3] = c[x3][3]; d[3][4] = c[x3][4];
		//cot3
		for(int y3=0; y3<k; y3++){
			if(c[y3][0]==d[0][3] && c[y3][1]==d[1][3] && c[y3][2]==d[2][3] && c[y3][3]==d[3][3]){
				d[4][3] = c[y3][4];
		//cheochinh
		for(int t2=0; t2<k; t2++){
			if(c[t2][0]==d[0][0] && c[t2][1]==d[1][1] && c[t2][2]==d[2][2] && c[t2][3]==d[3][3]){
				d[4][4] = c[t2][4];
				int tonghang[5] ={0}; int tongcot[5] = {0}; int tongcheo = 0; int res = 1;
				int hang4 = 0; int cot4 = 0;
				for(int i=0; i<5; i++){
					for(int j=0; j<5; j++){
						b[i][j] = d[i][j] - '0';
						}
					}
				for(int i=0; i<5; i++){
					for(int j=0; j<5; j++){
						tonghang[i]+=b[i][j];
						tongcot[i]+=b[j][i];
						if(i==j) tongcheo+=b[i][j];
						}
					}
				for(int i=0; i<5; i++){
					if(tonghang[i]!=s && tongcot[i]!=s) res = 0;
				}
				for(int i=0; i<5; i++){
					hang4+=b[4][i]*pow(10,4-i);
					cot4+=b[i][4]*pow(10,4-i);
				}
				if(check(hang4)==0 || check(cot4)==0) res = 0;
				if(res){
					for(int i=0; i<5; i++){
						for(int j=0; j<5; j++){
						cout << b[i][j] << " ";
						}
						cout << endl;
					}
					cout << endl;
				}
			}
		}
			}
		}
			}
		}
			}
		}
			}
		}
			}
		}
			}
		}
			} 
		}
			}		
		}
		
//		int reshang = 0; int rescot = 0;
//		for(int i=0; i<5; i++){
//			int b1 = d[4][i] - '0'; 
//			int b2 = d[i][4] - '0';
//			reshang+=b1;
//			rescot+=b2;
//		}
//		string xauhang4 = ""; string xaucot4 = "";
//		for(int i=0; i<5; i++){
//			xauhang4+=d[4][i];
//			xaucot4+=d[i][4];
//		}
//		if((reshang == rescot == s) && check(xauhang4) && check(xaucot4)){
//			for(int i=0; i<5; i++){
//				for(int j=0; j<5; j++){
//				cout << d[i][j] << " ";
//					}
//			cout << endl;
//				}
//				cout << endl; 
//			}
		} 
	return 0;
}
