#include <iostream>
using namespace std;

// Binary exponentiation works by repeatedly squaring the base and reducing the exponent by half (n // 2),
// multiplying the result only when the exponent is odd. 
// This reduces the number of multiplications to O(log n) instead of O(n), making it much faster

int main(){
	int number;
	int power;
	int ans = 1;

	cout<<"Enter a number: " << endl;
	cin >> number;
	
	cout<<"Enter its power: " << endl;
	cin >> power;

	while(power){
		if(power % 2 == 1){
			ans = ans * number;
		}
		number = number * number;
		power /= 2;
	}
	cout << ans;
}
