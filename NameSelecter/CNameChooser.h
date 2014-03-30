//CNameChooser class to generate random characters for name

#pragma once
#include <locale>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class CNameChooser
{
public:
	CNameChooser();
	virtual ~CNameChooser();

public:
	unsigned m_iNameIndex[3];
	wstring m_sFullName[3];
	
private:
	//For open file stream
	ifstream ifoper;
private:
	//const string charSet = "ͨ�����ڷ���ַ������ַ�������ֵ������ͬ���������Ͷ��Ҷ����Կ��ַ�������˿��԰�C����ַ��������κο���ʹ���ַ�������ֵ�ĵط�������������������������������ˢ���ڳ��Ե����ѱ����ĳ���ʱͨ���������������ҳ�����������������������������ĳ���ض���������������֪���ڳ�������λ��֮�������Գ���ʱ���뱣֤�ڴ�д���";
	//Random name generate
	void GenRandNameIndex(unsigned nameType, unsigned  indxRange);
	void GenSingleNameIndex(unsigned  indxRange);
	void GenRepeateNameIndex(unsigned  indxRange);
	void GenDoubleNameIndex(unsigned  indxRange);
	void GenFamilyNameIndex(unsigned  indxRange);

	//Load name character resoureces
	bool LoadFileCharRes(wstring filePath);
	bool GetIndxChsChar(unsigned charIndx,wstring& charStr);

public:
	void GenRandName(unsigned nameType);
	void GenFamilyName(void);
	
};

//const CString charSet " ͨ������ C ����ַ������ַ�������ֵ������ͬ���������Ͷ��Ҷ����Կ��ַ� null ������˿��԰� C ����ַ��������κο���ʹ���ַ�������ֵ�ĵط�������������������������������ˢ���ڳ��Ե����ѱ����ĳ���ʱͨ���������������ҳ�����������������������������ĳ���ض���������������֪���ڳ�������λ��֮�������Գ���ʱ���뱣֤�ڴ�д��� ";