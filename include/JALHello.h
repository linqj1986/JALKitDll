#pragma once

#include <string>
using namespace std;

#ifdef JAL_DLL
#define JAL_API _declspec(dllexport)
#else
#define JAL_API _declspec(dllimport)
#endif

class JAL_API JALHello
{
public:
	JALHello(void);
	~JALHello(void);

	string HelloWorld();
};
