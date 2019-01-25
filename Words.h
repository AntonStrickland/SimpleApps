#pragma once
#include "SimpleApp.h"

class Words : public SimpleApp
{
public:
	void Run();
	Words() {};
private:
	void Reverse();
};