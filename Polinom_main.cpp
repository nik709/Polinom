#include "TPolinom.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	int step = 0;
	int StepOfVariable;
	int mas[][2] = { NULL };
	cout << "¬ведите размер полинома: ";
	cin >> size;
	for (int i = 0; i<size; i++)
	{
		step = 0;
		cout <<endl<< "¬ведите коэффициент: ";
		cin >> mas[i][0];
		cout << "¬ведите степень х: ";
		cin >> StepOfVariable;
		step += StepOfVariable * 100;
		cout << "¬ведите степень y: ";
		cin >> StepOfVariable;
		step += StepOfVariable * 10;
		cout << "¬ведите степень z: ";
		cin >> StepOfVariable;
		step += StepOfVariable;
		mas[i][1] = step;
	}
	TPolinom polinom(mas, size);
	int comand;
	/*for (;;)
	{
		cout << "¬вести команду: ";
		cin >> comand;
		switch (comand)
		{
		case 1:
		{
				  TMonom monom;
				  step = 0;
				  cout << "¬ведите коэффициент: ";
				  cin >> monom.coeff;
				  cout << "¬ведите степень х: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable * 100;
				  cout << "¬ведите степень y: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable * 10;
				  cout << "¬ведите степень z: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable;
				  monom.power = step;
				  polinom.InsMonom(monom);
				  break;
		}
		case 2:
		{
				  //сложить полиномы
		}
		case 3:
		{
				  cout << polinom<<endl;
				  break;
		}
		case 4:
			exit(1);
		default:
			break;
		}
	}*/
}