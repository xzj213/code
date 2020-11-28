/************************************************
*Author        :  xzj213
*Created Time  :  2020.11.28.14:13
*Mail          :  xzj213@qq.com
*Problem       :  A
************************************************/
#include <bits/stdc++.h>
using namespace std;
int a,b,c;
void chkmax(int &a,int b) {if (a<b)a=b;}
void chkmin(int &a,int b) {if (a>b)a=b;}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch>57 || ch<48) {if(ch==45)f=-1;ch=getchar();}
	while (ch<=57 && ch>=48) {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int get(string s) {
	int sum=0;
	for (int i=0;i<2;i++) {
		if (s[i]>='0' && s[i]<='9') sum=sum*16+s[i]-'0';
		if (s[i]>='A' && s[i]<='F') sum=sum*16+(s[i]-'A')+10;
	}
	return sum;
}
char put(int x) {
	if (x>=10) return char(x-10+'A');
	else return char(x+'0');
}
int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
    string str;cin>>str;
	string s1;
	s1+=str[1];s1+=str[2];
	int x=get(s1);
	string s2;
	s2+=str[3];s2+=str[4];
	int y=get(s2);
	string s3;
	s3+=str[5];s3+=str[6];
	int z=get(s3);
	x=255-x;y=255-y;z=255-z;
	cout<<"#"<<put(x/16)<<put(x%16)<<put(y/16)<<put(y%16)<<put(z/16)<<put(z%16)<<endl;
	//cerr<<"Time : "<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
