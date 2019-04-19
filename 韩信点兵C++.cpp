#include<iostream>
using namespace std;
class Hanxin{
	private:
		int sum;
	public:
		Hanxin();
		int line3(int n1);
		int line5(int n2);
		int line7(int n3);
		void showMany();
		
}
	
};
Hanxin::Hanxin(){
	sum=0;
}
int Hanxin::line3(int n1){
	sum += 70*n1;
	return sum;
}
int Hanxin::line5(int n2){
	sum += 21*n2;
	return sum;
}
int Hanxin::line7(int n3){
	sum += 15*n3;
	return sum;
}
void Hanxin::showMany(){
	sum = sum % 105;
	if(sum!=0&&sum<101)
		cout<<sum<<endl;
	else cout<<"impossible"<<endl;
}

int main(){
	int n,n1,n2,n3;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>n1>>n2>>n3;
		Hanxin hx;
		hx.line3(n1);
		hx.line5(n2);
		hx.line7(n3);
		hx.showMany();
	}
	return 0;
}
