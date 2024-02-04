#pragma once

#include <string>
#include <iostream>
class Portfolio
{
public:
	Portfolio(double =0.0);
	//setget functions

	double buyStock(double ,double, double);
	double sellStock(double , double , double );
	void setCash(double);
	double getCash();
	
private:
	double cash=0;
};

