#pragma once
#include <iostream>;

using namespace std;

template <class Type>
class Tlink
{
public:
	Type val;
	Tlink *pNext; //указатель на следующий элемент
};

template <class Type>
class THeadList
{
protected:
	Tlink <Type> *pHead, *pFirst, *pPred, *pCurr, *pLast, *pStop;
	int pos; //позиция
	int len;
public:
	THeadList()
	{
		pHead = new Tlink <Type>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pPred = pCurr = 0;
		pos = -1;
		len = 0;
	}
	~THeadList()
	{
		if (len != NULL)
		{
			pCurr = pFirst;
			while (pCurr != pStop)
			{
				pPred = pCurr;
				pCurr = pCurr->pNext;
				delete pPred;
			}
		}
		delete pHead;
	}
	void InsFirst(Type elem)
	{
		Tlink <Type> *tmp = new Tlink <Type>;
		tmp->val = elem;
		pHead->pNext = tmp;
		if (len == 0)
		{
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		else
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		len++;
		pos++;
	}
};