#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (b == 0)
	{
		return a;
	}
	else{
		while (b > 0)
		{
			int r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}

int main(){
	int a, b;

	cout << "Enter the value of A : ";
	cin >> a;
	cout << "Enter the value of B : ";
	cin >> b;

	if (a > b){
		cout << "the HCF is : " << gcd(a, b) << endl;
	}
	else{
		cout << "the HCF is : " << gcd(b, a) << endl;
	}
}
