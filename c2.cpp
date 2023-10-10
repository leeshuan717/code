#include<iostream>
#include<cstring>
using namespace std;

long long f(long long n){
		if (n == 1||n == 2) return 1;
		else return f(n-1)+f(n-2);
}

int main(){
		long long n,f_end[4]={0};
		cin>>n;
		f_end[0] = f(n+1);
		f_end[1] = f(n);	
		f_end[2] = f_end[1];
		if(n-1 == 0) f_end[3] == 0;
		else f_end[3] = f(n-1);
		for(int i=0;i<4;i++){
			if(i == 2) cout<<endl;
			cout<<f_end[i]<<"  ";
		}
		//cout<<f_end[0];
}
