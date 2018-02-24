#include "DataDef.h"
#define UNINIT -10010

Member::Member()
{
	this->id = UNINIT;
	strcpy_s(this->name, "");
	strcpy_s(this->description, "");
}

Member::~Member()
{
}