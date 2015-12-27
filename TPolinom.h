#include "THeadList.h"

struct TMonom
{
	double coeff;
	int power;
};

bool operator <(const TMonom &m1, const TMonom &m2)
{
	return m1.power < m2.power;
}

bool operator >(const TMonom &m1, const TMonom &m2)
{
	return m1.power > m2.power;
}

class TPolinom : THeadList <TMonom>
{
public:
	TPolinom()
	{
		pHead->val.coeff = 0;
		pHead->val.power = -1;
	}
	TPolinom(int mas[][2], int size)
	{
		pHead->val.coeff = 0;
		pHead->val.power = -1;
		for (int i = 0; i < size; i++)
		{
			TMonom monom;
			monom.coeff = mas[i][0];
			monom.power = mas[i][1];
			InsLast(monom);
		}
	}
	void InsMonom(TMonom monom)
	{
		Reset();
		while (pCurr->val.power > monom.power)
			GoNext();
		if (pCurr->val.power < monom.power)
		{
			if (pCurr != pFirst)
				InsCurr(monom);
			else InsFirst(monom);
		}
		else
		{
			pCurr->val.coeff += monom.coeff;
			if (pCurr->val.coeff == 0)
				DelCurr();
		}
	}
	TPolinom &operator +=(TPolinom &p)
	{
		Reset();
		p.Reset();
		while (p.pCurr->val.power != -1)
		{
			InsMonom(p.pCurr->val);
			p.GoNext();
		}
		return *this;
	}
	friend ostream& operator<<(ostream &out, TPolinom &polinom)
	{
		if (polinom.len != 0)
		{
			for (polinom.Reset(); !polinom.IsEnd(); polinom.GoNext())
			{
				out << polinom.pCurr->val.coeff;
				if (polinom.pCurr->val.power / 100 > 0)
					cout << "(x^" << polinom.pCurr->val.power / 100 << ')';
				if ((polinom.pCurr->val.power / 10) % 10 > 0)
					cout << "(y^" << (polinom.pCurr->val.power / 10) % 10 << ')';
				if (polinom.pCurr->val.power % 10 > 0)
					cout << "(z^" << polinom.pCurr->val.power % 10 << ')';
				if (polinom.pCurr->pNext != polinom.pStop && polinom.pCurr->pNext->val.coeff > 0)
					out << '+';
			}
		}
		else 
			out << "Пустой полином";
		return out;
	}
};