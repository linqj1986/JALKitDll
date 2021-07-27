#pragma once

#include <string>
using namespace std;

#ifdef JAL_DLL
#define JAL_API _declspec(dllexport)
#else
#define JAL_API _declspec(dllimport)
#endif

class JAL_API JALBye
{
public:
	JALBye(void);
	~JALBye(void);

	string ByeMustStaticCall();
	virtual string Bye();
};

typedef JALBye* (*pFunCreateBye)();

extern "C" {
	JAL_API JALBye* CreateBye();
};

