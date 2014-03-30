#include "stdafx.h"
#include "CNameChooser.h"


CNameChooser::CNameChooser()
{
	//Initialize variable members
	for (int i = 0; i < 3;i++)
	{
		m_iNameIndex[i] = 0;
		m_sFullName[i] = L'\0';
	}

	//Plant random seed
	srand((unsigned)time(NULL));
	//Load char set resource
	wstring filePath = L"G:\\Visual Studio 2010\\Projects\\NameSelecter\\Ç§¼ÒÐÕÊÏ.txt";
	LoadFileCharRes(filePath);
}


CNameChooser::~CNameChooser()
{
	//close file stream
	ifoper.clear();
	ifoper.close();
}

void CNameChooser::GenRandNameIndex(unsigned nameType, unsigned  indxRange)
{
	
	//Generate random numbers for name index
	switch (nameType)
	{
	//For double name
	case 2:
		GenDoubleNameIndex(indxRange);
		break;
		//For single name
	case 0:
		GenSingleNameIndex(indxRange);
		break;
		//For repeate name
	case 1:
		GenRepeateNameIndex(indxRange);
		break;

	default:
		break;
	}
		
	
}

void CNameChooser::GenSingleNameIndex(unsigned  indxRange)
{
	
	unsigned i = 0;
	//Get none-zero number
	while (i==0)
	{
		i = rand() % indxRange;
	}
	m_iNameIndex[1] = i;
	m_iNameIndex[2] = 0;//NULL for last character
}

void CNameChooser::GenRepeateNameIndex(unsigned  indxRange)
{
	unsigned i = 0;
	//Get none-zero number
	while (i == 0)
	{
		i = rand() % indxRange;
	}
	m_iNameIndex[1] = i;
	m_iNameIndex[2] = i;
}

void CNameChooser::GenDoubleNameIndex(unsigned  indxRange)
{
	unsigned i = 0;
	m_iNameIndex[1] = rand()%indxRange;
	if (m_iNameIndex[1]==0)
	{
		while (i == 0)
		{
			i = rand() % indxRange;
		}
	}
	else
		i = rand() % indxRange;

	m_iNameIndex[2] = i;
}

void CNameChooser::GenFamilyNameIndex(unsigned  indxRange)
{
	unsigned i = 0;
	//Get none-zero number
	while (i == 0)
	{
		i = rand() % indxRange;
	}
	m_iNameIndex[0] = i;
}

void CNameChooser::GenRandName(unsigned nameType)
{
	GenRandNameIndex(nameType, 100);
	GetIndxChsChar(m_iNameIndex[1],m_sFullName[1]);
	GetIndxChsChar(m_iNameIndex[2], m_sFullName[2]);
}

void CNameChooser::GenFamilyName(void)
{
	GenFamilyNameIndex(100);
	GetIndxChsChar(m_iNameIndex[0],m_sFullName[0]);
}

bool CNameChooser::LoadFileCharRes(wstring filePath)
{
	//File open 
	ios_base::open_mode fileMode = ios_base::in;
	//For chinese characters set locationto china
	locale china("chs");
	ifoper.imbue(china);
	ifoper.open(filePath, fileMode);

	if (!(ifoper.is_open()))
	{
		ifoper.clear();
		ifoper.close();
		return false;
	}

	return true;
}

bool CNameChooser::GetIndxChsChar(unsigned charIndx,wstring& charStr)
{
	//Get chs character by index except control char
	if (!ifoper.is_open())
		return false;

	wstring charBuff = L"\0";
	if (charIndx == 0)
	{
		charBuff = L"\0";
		return true;
	}
		
	unsigned i = 0;
	while (!ifoper.eof()&&i<=charIndx)
	{
		charBuff = ifoper.get();
		//Just index the none-control chars
		if (charBuff!=L"\0" && charBuff != L"\n")
		{
			i++;
		}
	}
	ifoper.seekg(0,ios_base::beg);
	if (charBuff == L"\0")
		return false;
	else
	{
		charStr = charBuff;
		return true;
	}

}