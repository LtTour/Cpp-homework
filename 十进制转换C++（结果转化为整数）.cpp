#include<iostream>
#include<cmath>
using namespace std;

class Number{
	private:
		int num,orjin,count,ans;
		int q[100];
	public:
		Number(int ,int );
		int converto(int );
		void show();
};
Number::Number(int a,int b){
	num=a;
	orjin=b;
	ans=0;
}
int Number::converto(int b){
	int a=num;
	for(int i=0;;i++){
		q[i]=a%b;
		a=a/b;
		if(a==0){
			break;
		}
		count=i+1;
	}
	for(int i=count;i>=0;i--){
		int t=(int) pow(10,i);
		ans += q[i]*t ;
	}
	return ans;
}
void Number::show(){
	cout<<ans<<endl;
}

int main(){
	int n,n1,n2;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>n1>>n2;
		if (n1<n2){
			cout<<n1<<endl;
		}else{
			Number no1(n1,10);
			no1.converto(n2);
			no1.show();
		}
		
	}
	return 0;
} 

