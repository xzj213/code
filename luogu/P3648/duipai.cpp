/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.30.20:35
*Mail          :  xzj213@qq.com
*Problem       :  duipai
************************************************/
#include <bits/stdc++.h>
using namespace std;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main() {
 	for (int i=1;i<=100000;i++) {
		cout<<"Test : "<<i<<endl;
		system("./data");
		system("./P3648");
		system("./answer");
		if (system("diff P3648.out answer.out")) {
			puts("Wrong answer!!!");
			return 0;
		}
		puts("Accepted!!!");
	}
    return 0;
}
