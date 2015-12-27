#pragma once
#include <iostream>

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
		Tlink <Type> *tmp = new Tlink<Type>;
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
	void DelFirst()
	{
		if (len != 0)
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			len--;
			pos--;
		}
	}
	void InsCurr(Type elem)
	{
		Tlink <Type> *tmp = new Tlink <Type>;
		tmp->val = elem;
		pPred->pNext = tmp;
		tmp->pNext = pCurr;
		pCurr = tmp;
		len++;
	}
	void DelCurr()
	{
		if (pCurr == pFirst)
			DelFirst();
		else
		{
			pPred->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPred->pNext;
		}
	}
	void Reset()
	{
		pCurr = pFirst;
	}
	void GoNext()
	{
		pPred = pCurr;
		pCurr = pCurr->pNext;
	}
	bool IsEnd()
	{
		return pCurr == pStop;
	}
	void InsLast(Type elem)
	{
		Tlink <Type> *tmp = new Tlink<Type>;
		tmp->val = elem;
		if (len == 0)
		{
			pHead->pNext = tmp;
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		else
		{
			pLast->pNext = tmp;
			tmp->pNext = pStop;
			pLast = tmp;
		}
		len++;
		pos++; 
	}
};