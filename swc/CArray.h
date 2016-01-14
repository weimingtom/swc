#pragma once

#include "stdafx.h"

class CArray
{
	void** m_pData;
	int	   m_MaxSize;
	
	public:

	CArray()
	{
		m_pData=NULL;
		m_MaxSize=0;
	}


	~CArray() 
	{
		delete [] (LPBYTE) m_pData;
	}
	
	void Reset()
	{
		AllocMemory(0);
		delete [] (LPBYTE) m_pData;
		m_pData=NULL;
		m_MaxSize=0;
	}
	void AllocMemory(int NewSize)
	{
		
		if(NewSize < 0)
			return;
		if(NewSize==0)
		{
			delete[] (LPBYTE) m_pData;
			m_pData=NULL;
			m_MaxSize=0;
		}
		else if (m_pData == NULL)
		{
			m_pData = (void**) new BYTE[NewSize * sizeof(void*)];

			memset(m_pData, 0, NewSize * sizeof(void*));  

			m_MaxSize = NewSize;
		}
		else
		{
			if(NewSize > m_MaxSize) //se incrementa el arreglo en NewSize- m_MaxSize
			{
				void** m_pTempData= (void** ) new BYTE[NewSize* sizeof(void*)];
				memcpy(m_pTempData,m_pData,m_MaxSize * sizeof(void*));
				//memset(&m_pTempData,0x00,(NewSize-m_MaxSize)* sizeof(void*));
				delete[] (LPBYTE) m_pData;
				m_pData=m_pTempData;
				m_MaxSize=NewSize;
			}
			else  
				memset(&m_pData,0x00,(m_MaxSize-NewSize)* sizeof(void*));
			
		}
		
	}


	void SetAtGrow(int nIndex, void* newElement)
	{	
	
		if(nIndex < 0)
			return;
		if (nIndex >= m_MaxSize)
			AllocMemory(nIndex+1);
		
		m_pData[nIndex] = newElement;
	}
	
	void RemoveAt(int nIndex, int nNumItem)
	{
		if(nIndex >= 0 && nNumItem >= 0)
		{
			if(nIndex + nNumItem <= m_MaxSize)
			{	
			
				int nDiff = m_MaxSize - (nIndex + nNumItem);

				if (nDiff)
					memmove(&m_pData[nIndex], &m_pData[nIndex + nNumItem],nDiff * sizeof(void*));
				m_MaxSize -= nNumItem;
			}
		}
	}

	void InsertAt(int nIndex, void* newElement)
	{

		ASSERT(nIndex >= 0);  

		if (nIndex >= m_MaxSize)
			AllocMemory(nIndex+1);  
		else
		{
			int nSize = m_MaxSize;
			AllocMemory(m_MaxSize + 1);  
			memmove(&m_pData[nIndex+1], &m_pData[nIndex],
				(nSize-nIndex) * sizeof(void*));

			memset(&m_pData[nIndex], 0, sizeof(void*));
		}

		m_pData[nIndex] = newElement;

	}

	void SetAt(int nIndex, void* newElement)
	{

		ASSERT(nIndex >= 0);  

		if (nIndex >= m_MaxSize)
			return;  
		else
			m_pData[nIndex] = newElement;

	}

	void RemoveAll()
	{
		AllocMemory(0);
	}

	int GetSize()
	{
		return m_MaxSize;
	}

	void* operator[](int nIndex) 
	{
		ASSERT(nIndex <= m_MaxSize && nIndex >= 0);
		return m_pData[nIndex];
	}
	
	void* GetAt(int nIndex)
	{
		ASSERT(nIndex <= m_MaxSize && nIndex >= 0);
		return m_pData[nIndex];
	}
		
};	
