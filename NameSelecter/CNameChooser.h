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
	//const string charSet = "通常由于风格字符串与字符串字面值具有相同的数据类型而且都是以空字符结束因此可以把C风格字符串用在任何可以使用字符串字面值的地方如果程序不正常结束输出缓冲区将不会刷新在尝试调试已崩溃的程序时通常会根据最后的输出找出程序发生错误的区域如果崩溃出现在某个特定的输出语句后面则可知是在程序的这个位置之后出错调试程序时必须保证期待写入的";
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

//const CString charSet " 通常由于 C 风格字符串与字符串字面值具有相同的数据类型而且都是以空字符 null 结束因此可以把 C 风格字符串用在任何可以使用字符串字面值的地方如果程序不正常结束输出缓冲区将不会刷新在尝试调试已崩溃的程序时通常会根据最后的输出找出程序发生错误的区域如果崩溃出现在某个特定的输出语句后面则可知是在程序的这个位置之后出错调试程序时必须保证期待写入的 ";