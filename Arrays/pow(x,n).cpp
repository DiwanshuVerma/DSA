#include <iostream>
using namespace std;


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
