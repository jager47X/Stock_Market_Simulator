#pragma once
#include "Stock.h"
#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

class AutomotiveCompanyStock :public Stock
{
public:
	AutomotiveCompanyStock(string = "Automotive", string = " ", double = 0, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	double virtual stockChange();

private:
	double owned;
	double change;
};