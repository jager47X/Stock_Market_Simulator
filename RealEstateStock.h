

#pragma once
#include "Stock.h"
#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

class RealEstateStock :public Stock
{
public:
	RealEstateStock(string = "Realestate", string = " ", double = 0, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	double virtual stockChange();

private:
	double owned;
	double change;
};