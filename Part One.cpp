/*Antonio Lopez Garcia
Quiz
12 September 2017
Ray Ahmadnia
Purpose: Compute the total of digits and display them
*/

#include <iostream>
using namespace std;

int calculateTotalDigits(int n){
	int d1, d2, d3, d4, r, total = 0;
	int THOUSAND = 1000;
	int HUNDERED = 100;
	int TEN = 10;
	
	_asm{
		//gets individual numbers
		mov eax, n;
		cdq;
		idiv THOUSAND;
		mov d1, eax;
		mov r, edx;
		mov eax, r;
		cwd;
		idiv HUNDERED;
		mov d2, eax;
		mov r, edx;
		mov eax, r;
		cdq;
		idiv TEN;
		mov d3, eax;
		mov r, edx;
		mov d4, edx;
		//adds digits and moves to total
		mov ebx, d1;
		add ebx, d2;
		mov ecx, d3;
		add ecx, d4;
		add ebx, ecx;
		mov total, ebx;
	}

	return total;
}


int main(){
	int n, totalDigits;
	cout << "enter a four digit number: ";
	cin >> n;

	totalDigits = calculateTotalDigits(n);

	cout << "The total of digints in n is: " << totalDigits << endl;
	
	system("pause");
	return 0;
}
