#include<iostream>
#include<string>
using namespace std;
int main(){
		int n,item[5];
		int k=0;
		int left = 0,right =0;
		while(1){
				cout<<"\nitem system\n"<<"1.left +\n"<<"2.left -\n"<<"3.right +\n"<<"4.right -\n"<<"5.end\n"<<"?";
				cin>>n;
				if (n == 5) break;
				switch(n){
						case 1:
								if (k == 5) {
										cout<<"item is FULL\n"<<"item line"<<k;
										break;
								}
								if (k != 0) left++;
								cout<<"input item number:";
								cin>>item[left];
								cout<<"left+:\n";
								cout<<"left number:"<<left<<"\nright number:"<<right<<"\nnew item:"<<item[left]<<endl;
								k++;
								cout<<"item line"<<k<<endl;
								break;
						case 2:
								if(k == 0) {
										cout<<"item is NULL\n"<<"item line"<<k;
										break;
								}
								if(left == 0) left = 4;
								else left-=1;
								cout<<"left-:\n";
								int itemr;
								if (left == 4) itemr =item[0];
								else itemr =item[left+1];
								cout<<"left number:"<<left<<"\nright number:"<<right<<"\ndelete item:"<<itemr<<endl;
								k--;
								cout<<"item line"<<k<<endl;
								break;
						case 3:
								if (k == 5) {
										cout<<"item is FULL";
										break;
								}
								cout<<"input item number:";
								if(right == 0) right=4;
								else right--;
								cin>>item[right];
								cout<<"right+:\n";
								cout<<"left number:"<<left<<"\nright number:"<<right<<"\nnew item:"<<item[right]<<endl;
								k++;
								cout<<"item line"<<k<<endl;
								break;
						case 4:
								if(k == 0) {
										cout<<"item is NULL";
										break;
								}
								right++;
								cout<<"right-:\n";
								cout<<"left number:"<<left<<"\nright number:"<<right<<"\ndelete item:"<<item[right-1]<<endl;
								k--;
								cout<<"item line"<<k<<endl;
								break;
						default:
								cout<<"input erroe！ re-enter！\n";
				}
		}
		cout<<"item line end!";
}
