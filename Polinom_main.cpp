#include "TPolinom.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	int step = 0;
	int StepOfVariable;
	int mas[100][2];
	int standmas[][2] = { { 1, 222 }, {1,20} };
	TPolinom standpolinom(standmas, 2);
	cout << "������� ������ ��������: ";
	cin >> size;
	for (int i = 0; i<size; i++)
	{
		step = 0;
		cout <<endl<< "������� �����������: ";
		cin >> mas[i][0];
		cout << "������� ������� �: ";
		cin >> StepOfVariable;
		step += StepOfVariable * 100;
		cout << "������� ������� y: ";
		cin >> StepOfVariable;
		step += StepOfVariable * 10;
		cout << "������� ������� z: ";
		cin >> StepOfVariable;
		step += StepOfVariable;
		mas[i][1] = step;
	}
	TPolinom polinom(mas, size);
	int comand;
	cout << endl << "1 - �������� �����" << endl;
	cout << "2 - operator +=" << endl;
	cout << "3 - ������� ������� �� �����" << endl;
	cout << "4 - ����� �� ���������" << endl;
	for (;;)
	{
		cout << endl << "������ �������: ";
		cin >> comand;
		switch (comand)
		{
		case 1:
		{
				  TMonom monom;
				  step = 0;
				  cout << "������� �����������: ";
				  cin >> monom.coeff;
				  cout << "������� ������� �: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable * 100;
				  cout << "������� ������� y: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable * 10;
				  cout << "������� ������� z: ";
				  cin >> StepOfVariable;
				  step += StepOfVariable;
				  monom.power = step;
				  polinom.InsMonom(monom);
				  break;
		}
		case 2:
		{
				  polinom += standpolinom;
				  cout << polinom << endl;
				  break;
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
	}
}