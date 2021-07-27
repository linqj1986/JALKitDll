#include "StdAfx.h"
#include "JALBye.h"

JALBye *CreateBye()
{
	return new JALBye();
}

JALBye::JALBye(void)
{
}


JALBye::~JALBye(void)
{
}

string JALBye::ByeMustStaticCall()
{
	return "ByeMustStaticCall";
}

string JALBye::Bye()
{
	return "Bye";
}