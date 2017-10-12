/*Arianne Arcebal, Antonio Lopez Garcia
* Project 7 Part 2
* 12 October 2017
* Ray Ahmadnia
* Purpose: To show the two real roots of aX^2 + bX + c = 0
*/

#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c;
float xOne, xTwo;
float d;
float Four = 4, Two = 2, Zero = 0;

void askForValue(){
	cout << "To see the two real values of aX^2 + bX + c = 0, \nenter the a, b, c values: 2.1 4.5 1.7" << endl;
}

float getValues(){
	cin >> a >> b >> c;
	return a, b, c;
}

void printAnswer(){
	cout << "X1 = " << fixed << showpoint << setprecision(2) << xOne << endl;
	cout << "X2 = " <<fixed << showpoint << setprecision(2) << xTwo << endl;
}

int main() {

	_asm{
		call askForValue;
		call getValues;

		fld b;
		fld b;
		fmul;	//st = b^2
		fld Four;
		fld a;
		fld c;
		fmul;
		fmul;	//st = 4*a*c, st(1) = b^2
		fsub;
		fsqrt;	// st = sqrt(b^2 - 4ac)
		fstp d;

		// solve for x1
		fld d;
		fld Zero;
		fld b;
		fsub; // st = 0 - b;
		fadd; // st = -b + d
		fld a;
		fld Two;
		fmul; // st = 2a, st(1) = (-b + d)
		fdiv; // st = (-b +	d) / 2a
		fstp xOne;

		// solve for x2
		fld d;
		fld Zero;
		fld b;
		fsub; // st = 0 - b;
		fsub; // st = -b - d
		fld a;
		fld Two;
		fmul; // st = 2a, st(1) = (-b - d)
		fdiv; // st = (-b -	d) / 2a
		fstp xTwo;

		
		call printAnswer;
	}
	
	system("pause");
	return 0;
} 
