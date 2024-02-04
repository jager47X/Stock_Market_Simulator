#pragma once
#include <string>
#include <iostream>
using namespace std;
class Stock
{
public:
	Stock(string=" ",string=" ", double= 0,  double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	string getIndustry();
	string getName();
	double getOwned();
	double getvalue();
	double getDay_changePer();


	double getTotalstock();
	void setTotalstock(int);
	void setIndustry(string);
	void setName(string);
	void setOwned(double);
	void setValue(double);
	void setDay_changePer(double);


	void setChange(double );
	double getChange();
	void setShare(double);
	double getShare();
	virtual double stockChange();
	virtual void display_stock()const;
private:
	string industry, name;
	double owned;
	double day_changePer;
	int totalStock;
	double value;
	double change;
	double share;
};

