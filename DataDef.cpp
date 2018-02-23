#include "DataDef.h"
#define UNINIT -10010

Member::Member()
{
	this->id = UNINIT;
	this->name = "";
	this->description = "";
}

Member::~Member()
{
}