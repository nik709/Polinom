#include "TPolinom.h"

void main()
{
	int mas[][2] = { { 2, 203 }, { 4, 1 } };
	TPolinom polinom(mas, 2);
	cout << polinom<<endl;
	TMonom monom;
	monom.coeff = 3;
	monom.power = 3;
	polinom.InsMonom(monom);
	cout << polinom << endl;
}