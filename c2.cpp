#include<iostream>
#include<cstring>
using namespace std;
long long int r[4] ={1,1,1,0},f_end[4] = {1,1,1,0};
//{1 1 { 1 1
// 1 0}  1 0}
void f(void){
		long long int a = f_end[0],
		b = f_end[1],
		c = f_end[2],
		d = f_end[3];
		f_end[0] = r[0]*a+r[1]*c;
		f_end[1] = r[0]*b+r[1]*d;
		f_end[2] = r[2]*a+r[3]*c;
		f_end[3] = r[2]*b+r[3]*d;
}
int main(){
		int n;
		cin>>n;
		for(int i=1;i<n;i++){
				f();
		}
		cout<<"a"<<n<<"= [";
		for(int i=0;i<4;i++){
				if(i == 2) cout<<endl;
				cout<<f_end[i]<<" ";
		}
		cout<<"]";
}
