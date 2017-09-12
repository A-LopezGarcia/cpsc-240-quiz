#include <iostream>
using namespace std;

//calulate r= [20 * (a+b) * (a-b)] / (a^3)*c]

int main() {
	short a = 5, b = 7, c = 2, d, r;
	short TWENTY = 20;

	_asm {
		mov ax, a;
		mov bx, b;
		add ax, bx;
		mov cx, ax;
		mov r, cx;

		mov ax, a;
		mov bx, b;
		sub ax, bx;
		imul cx;
		mov r, ax;

		mov ax, r;
		imul TWENTY;
		mov r, ax;

		mov ax, a;
		imul a;
		imul a;
		imul c;
		mov bx, ax;
		mov ax, r;
		idiv bx;
		mov r, ax;


	}

	cout << r << endl;

	system("pause");
	return 0;
}
