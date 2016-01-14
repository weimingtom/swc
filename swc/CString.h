#pragma once

#include "stdafx.h"

class CString
{
	int m_nSize;
	int	m_nRef;

protected:
	LPTSTR	m_pData;
public:

	CString()
	{
		InitString();
	}

	
	CString(TCHAR ch, int nRepeat = 1)
	{
		InitString();
		if (nRepeat >= 1)
		{
			AllocMemory(nRepeat);
			memset(m_pData, ch, nRepeat);
		}
	}
	

	CString(LPCSTR lpsz)
	{
		InitString();
		m_nSize=strlen(lpsz);
		if (m_nSize > 0)
		{
			AllocMemory(m_nSize);
			memcpy(m_pData,lpsz, m_nSize* sizeof(TCHAR));
		}
	}

	CString(const unsigned char* lpsz)
	{ 
		InitString();
		*this=(LPCSTR)lpsz;
	}
	

	~CString()
	{
		if(m_nRef <= 0)
			delete [] (BYTE*)m_pData;
		m_pData=NULL;
	}

public:

	void InitString()
	{
		m_pData=NULL;
		m_nSize=0;
		m_nRef=0;
	}
	

	int GetLength() 
	{
		return m_nSize;
	}
	BOOL IsEmpty() 
	{
		return (BOOL) !m_nSize;
	}
	
	void Empty()
	{
		if (m_nSize) return;
		if(m_nRef <= 0)
			delete [] (BYTE*)m_pData;
	}

	TCHAR GetAt(int nIndex) 
	{
		ASSERT(nIndex >=0  && nIndex < GetLength());
		return m_pData[nIndex];
	}
	
	void SetAt(int nIndex, TCHAR ch)
	{
		ASSERT(nIndex < m_nSize);
		CopyBeforeWrite();
		if (m_pData)
			m_pData[nIndex]=ch;
		
	}
		
	
	LPCTSTR GetData()
	{
		return m_pData;
	}

	
	TCHAR operator[](int nIndex) 
	{
		return GetAt(nIndex);
	}
	
	operator LPCTSTR(){return m_pData;};

	const CString& operator=(const CString& stCopy)
	{	
		if (m_pData != stCopy.m_pData)
		{
			if ((m_nRef < 0 && m_pData) || m_nRef < 0)
				 CopyString(stCopy.m_pData);
			else
			{
				if(m_nRef <= 0)
				{
					delete [] (BYTE*)m_pData;
					m_pData=NULL;
					m_nSize=0;
					m_nRef=0;
				}
				ASSERT(stCopy.m_pData);
				m_pData = stCopy.m_pData;
				m_nSize = strlen(m_pData);
				m_nRef++;
			}
		}
		return *this;
	}

	const CString& operator=(TCHAR ch)
	{
		ASSERT( ch != _T( '\0' )); 
	
		CopyBeforeWrite();
		AllocMemory( 2 );
		m_pData[ 0 ] = ch;
		return *this;
	}
	
	const CString& operator=(LPCSTR lpsz)
	{
		ASSERT(lpsz == NULL);
		CopyString( lpsz);
		return *this;
	}
	
	const CString& operator=(const unsigned char* lpsz)
	{ 
		*this = (LPCSTR)lpsz;
		return *this; 
	}
	
	const CString& operator+=( TCHAR ch )
	{
		ASSERT( ch != _T( '\0' )); 
		CopyBeforeWrite();
		int nLen = GetLength();
		AllocMemory( nLen + 1);
		m_pData[ nLen ] = ch;
		return *this;
	}

	const CString& operator+=(LPCTSTR lpsz)
	{

		ASSERT( lpsz ); 
		LPTSTR m_pDatat=NULL;
		int nLen= GetLength();
		int nSrc =strlen(lpsz);
		m_pDatat=(LPTSTR) new BYTE[GetLength()*sizeof(TCHAR)];
		memcpy(m_pDatat,m_pData,GetLength()*sizeof(TCHAR));
		CopyBeforeWrite();
		AllocMemory( nLen +  nSrc );
		memcpy(m_pData, m_pDatat, nLen *sizeof(TCHAR));
		memcpy(m_pData+nLen, lpsz,nSrc *sizeof(TCHAR));
		return *this;
	}
	
	const CString& operator+=(CString& string)
	{
		ASSERT( lpsz ); 
		LPTSTR m_pDatat=NULL;
		int nLen= GetLength();
		int nSrc = string.GetLength();
		m_pDatat=(LPTSTR) new BYTE[GetLength()*sizeof(TCHAR)];
		memcpy(m_pDatat,m_pData,GetLength()*sizeof(TCHAR));
		CopyBeforeWrite();
		AllocMemory( nLen +  nSrc );
		m_pData=m_pDatat;
		memcpy(m_pData+GetLength(), string.m_pData, (nLen +  nSrc )*sizeof(TCHAR));
		return *this;
		
	}
	
	

	friend CString  operator+(const CString& str1,
			const CString& str2)
	{
		CString cs;
		cs.ConcatString(str1.m_pData,str2.m_pData);
		return cs;
	}
	friend CString  operator+(const CString& str1, TCHAR ch)
	{
		CString cs;
		TCHAR tempStr[2] = {ch, 0};
		cs.ConcatString((LPCTSTR)(str1.m_pData), (LPCTSTR)(tempStr));
		return cs;
	}
	friend CString  operator+(TCHAR ch, const CString& str)
	{
		CString cs;
		TCHAR tempStr[2] = {ch, 0};
		cs.ConcatString((LPCTSTR)tempStr, (LPCTSTR)(str.m_pData));
		return cs;
	}
	friend CString  operator+(const CString& str, LPCTSTR lpsz)
	{
		CString cs;
		cs.ConcatString(str.m_pData,lpsz);
		return cs;
	}
	friend CString  operator+(LPCTSTR lpsz, const CString& str)
	{
		CString cs;
		cs.ConcatString(lpsz,str.m_pData);
		return cs;
	}

	BOOL  operator==( const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData)? 1: 0;
	}
	BOOL  operator==( LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2)? 1: 0;
	}
	BOOL  operator!=(const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData)!=0;
	}
	BOOL  operator!=( LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2)!=0;
	}

	BOOL  operator<(const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData) <0;
	}
	BOOL  operator<(LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2) <0;
	}

	BOOL  operator>(const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData)>0;
	}
	BOOL  operator>(LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2) >0;
	}

	BOOL  operator<=(const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData) <=0;
	}
	BOOL  operator<=(LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2) <=0;
	}

	BOOL  operator>=(const CString& s2)
	{
		return _tcscmp(m_pData,s2.m_pData) >=0;
	}
	BOOL  operator>=(LPCTSTR s2)
	{
		return _tcscmp(m_pData,s2) >=0;
	}

	int CompareNoCase(LPCTSTR lpsz) 
	{
		return _tcsicmp(m_pData,lpsz);
	}
	
	void LoadString(HINSTANCE hInst,int idCtrl)
	{
		AllocMemory(256);
		::LoadStringA(hInst, idCtrl, m_pData, 256);	

	}
	
	CString Mid(int nFirst, int nCount) 
	{
		CString lpMid;
		if (nFirst <0) nFirst=0;
		if(nCount ==0) nCount=GetLength();
		if (nCount > (GetLength()-nFirst) ) nCount =GetLength()-nFirst;
		lpMid.AllocMemory( nCount );
		_tcsncpy( lpMid.m_pData, &m_pData[nFirst], nCount );
		return lpMid;
	}
	CString Mid(int nFirst)
	{
		return Mid(nFirst);
	}
	
	CString Left(int nCount) 
	{
		ASSERT( nCount <= GetLength());
		
		CString	cdest;
		cdest.AllocMemory( nCount );
		_tcsncpy( cdest.m_pData, m_pData, nCount );
		return cdest;
	}
	CString Right(int nCount) 
	{
		ASSERT( nCount <= GetLength());
		
		CString	cdest;
		cdest.AllocMemory( nCount );
		_tcsncpy( cdest.m_pData, &m_pData[GetLength()-nCount], nCount );
		return cdest;
	}


	void MakeUpper()
	{
		CopyBeforeWrite();
		_tcsupr(m_pData);
	}
	
	void MakeLower()
	{
		CopyBeforeWrite();
		_tcslwr(m_pData);
	}
	
	void MakeReverse()
	{
		CopyBeforeWrite();
		_tcsrev(m_pData);
	}
	
	int Collate( LPCTSTR pszStr ) 
	{
		ASSERT( m_pData!= NULL &&  pszStr != NULL);
		return _tcscoll( m_pData, pszStr );
	}
	
	int CollateNoCase( LPCTSTR pszString ) const
	{
		ASSERT( m_pData!= NULL &&  pszString != NULL);
		return _tcsicoll( m_pData, pszString );
	
	}

	void TrimRight(){};
	void TrimLeft(){};

		
	CString SpanIncluding(LPCTSTR lpszStr) 
	{
		ASSERT(lpszStr);
		return Left(_tcsspn(m_pData, lpszStr));
	}
	
	
	CString SpanExcluding(LPCTSTR lpszStr) 
	{
		ASSERT(lpszStr);
		return Left(_tcscspn(m_pData, lpszStr));
	}
	
	
	int Find(TCHAR ch) 
	{
		return Find(ch, 0);
	}
	
	int Find(TCHAR ch, int nStart)
	{
		if(nStart >= GetLength() )
			return -1;
		LPTSTR lpszSub;
		if(!( lpszSub = _tcsrchr(m_pData+nStart, (TCHAR) ch)))
			return -1;
		return (int) (lpszSub-m_pData);
		
	}
	int Find(LPCTSTR lpszStr) 
	{
		return Find(lpszStr, 0);
	}

	int Find(LPCTSTR lpszStr, int nStart)
	{
		if(nStart >= GetLength() ) return -1;
		LPTSTR lpSub;
		if(!(lpSub=_tcsstr(m_pData+nStart,lpszStr)))
			return -1;
		return (int)(lpszStr-m_pData);
	}
	

protected:
	
	void AllocMemory(int nLen)
	{
		ASSERT(nLen > 0)
		
		if ((nLen % 64) != 0 && nLen < 512)
		{
			if (nLen < 64 )  m_nSize=64;
			else
			{
				int res=(nLen % 128);
				m_nSize=nLen+(128-res);
			}
		}
		
		m_pData=(LPTSTR) new BYTE[(m_nSize+1)*sizeof(TCHAR)];
		
		m_nRef   = 1;
		m_nSize  = nLen;
		m_pData[ m_nSize ] = _T( '\0' );

	}
	
	void CopyBeforeWrite()
	{
		LPTSTR m_pDatat=NULL;
		m_pDatat=(LPTSTR) new BYTE[GetLength()*sizeof(TCHAR)];
		memcpy(m_pDatat,m_pData,GetLength()*sizeof(TCHAR));
		if(m_nRef <= 0)
			delete [] (BYTE*)m_pData;
		m_pData=m_pDatat;
	}
	
	void CopyString(LPCTSTR lpsz)
	{
		int nSize=strlen(lpsz);
		if (m_nRef > 1 || nSize > m_nSize )
		{
			if (m_nRef <= 0)
			 AllocMemory(nSize);
		}
		if (nSize <=0) return;
		memset(m_pData,0x00,nSize);
		memcpy(m_pData, lpsz, nSize*sizeof(TCHAR));
		m_nSize = nSize;
		m_pData[nSize] = '\0';
	}
	
	void ConcatString(LPCTSTR lpszSrc1, LPCTSTR lpszSrc2)
	{
	 	int nSize1=strlen(lpszSrc1);
		int nSize2=strlen(lpszSrc2);
		if (nSize1+nSize2 != 0)
		{
			AllocMemory(nSize1+nSize2);
			memcpy(m_pData, lpszSrc1, nSize1 *sizeof(TCHAR));
			memcpy(m_pData+nSize1, lpszSrc2, nSize2*sizeof(TCHAR));
		}
	}
	
};
