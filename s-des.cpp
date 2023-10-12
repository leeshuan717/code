#include<iostream>
#include<cstring>
using namespace std;
string kr_end="";
string kr="00",rep[16] ={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},reps[16]={"","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
string leftkey;
void left(string key){
		leftkey = "";
		for(int i=1;i<5;i++){
				leftkey += key[i];
		}
		leftkey += key[0];
		for(int i=6;i<10;i++){
				leftkey += key[i];
		}
		leftkey += key[5];
}
void switch_16(string key){
		kr ="00";
		kr_end="";
		int n =key.length();
		if(n == 10) kr += key;
		else {
				kr += "00";
				kr += key;
		}
		kr += key;
		string kr1[3];
		for(int i=0;i<4;i++) kr1[0] += kr[i];	
		for(int i=4;i<8;i++) kr1[1] += kr[i];	
		for(int i=8;i<12;i++) kr1[2] += kr[i];
		for(int i=0;i<3;i++){
				int j=0;
				while(1){
						if(kr1[i] == rep[j]){
								kr_end+=reps[j];
								break;
						}
						j++;
				}
		}

}
int main(){
		//十六進制轉換
		string key;
		cout<<"請輸入十位元的key:";
		cin>>key;
		switch_16(key);
		//0000 ,0001 ,0010 ,0011 ,0100 ,0101 ,0110 ,0111, 1000 ,1001 ,1010 ,1011 ,1100 ,1101 ,1110 ,1111
		cout<<"輸入 key:"<<key<<" =";
		cout<<"0x"<<kr_end<<endl;
		//十位元重排
		string swap_10="";
		swap_10 += key[2];	
		swap_10 += key[4];
		swap_10 += key[1];
		swap_10 += key[6];
		swap_10 += key[3];
		swap_10 += key[9];
		swap_10 += key[0];
		swap_10 += key[8];
		swap_10 += key[7];
		swap_10 += key[5];
		switch_16(swap_10);
		cout<<"重排列10:"<<swap_10<<" =";
		cout<<"0x"<<kr_end<<endl;
		left(swap_10);
		switch_16(leftkey);
		cout<<"左旋轉1 :"<<leftkey<<" =";
		cout<<"0x"<<kr_end<<endl;
		//八位元重排
		string swap_8="";
		swap_8 += leftkey[5];
		swap_8 += leftkey[2];
		swap_8 += leftkey[6];
		swap_8 += leftkey[3];
		swap_8 += leftkey[7];
		swap_8 += leftkey[4];
		swap_8 += leftkey[9];
		swap_8 += leftkey[8];
		switch_16(swap_8);
		cout<<"key1輸出:"<<swap_8<<"   =";
		cout<<"0x"<<kr_end<<endl;
		//左旋轉2
		left(leftkey);
		left(leftkey);
		switch_16(leftkey);
		cout<<"左旋轉2 :"<<leftkey<<" =";
		cout<<"0x"<<kr_end<<endl;
		swap_8 ="";
		swap_8 += leftkey[5];
		swap_8 += leftkey[2];
		swap_8 += leftkey[6];
		swap_8 += leftkey[3];
		swap_8 += leftkey[7];
		swap_8 += leftkey[4];
		swap_8 += leftkey[9];
		swap_8 += leftkey[8];
		switch_16(swap_8);
		cout<<"key2輸出:"<<swap_8<<"   =";
		cout<<"0x"<<kr_end<<endl;
}
