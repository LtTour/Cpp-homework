#include<iostream>
using namespace std;

class Number{
	public:
		Number(int );
		int maxDivisor(Number );
		void show();
	private:
		int n;
};
Number::Number(int a){
	n=a;
}
int Number::maxDivisor(Number n2){
	int tem;
	if(n<n2.n){
		tem=n;
		n=n2.n;
		n2.n=tem;	
	}
	while (n%n2.n!=0){
		tem=n%n2.n;
		n=n2.n;
		n2.n=tem;
	}
	n=n2.n;
	return n;
}
void Number::show(){
	cout<<n<<endl;
}

int main() {
	int n, n1, n2;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> n1 >> n2;
		Number no1(n1), no2(n2);
		Number no3 = no1.maxDivisor(no2); //最大公约数
		no3.show();
	}
	return 0;
}
