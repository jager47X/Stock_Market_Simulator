#include "Stock.h"
Stock::Stock(string in, string na, double own, double total,  double dc,double val,double sha) {
	industry=in;
	name=na;
	totalStock = total;
	owned = own;
	day_changePer = dc;
	value = val;
	share = sha;
}
string Stock::getIndustry() {
	return industry;
}

string Stock::getName() {
	return name;
}

double Stock::getOwned() {
	return owned;
}

double Stock::getvalue() {
	return value;
}

double Stock::getDay_changePer() {
	return day_changePer;
}
double Stock::getTotalstock() {
	return totalStock;
}


void Stock::setTotalstock(int  total) {
	this->totalStock = total;
}


void Stock::setIndustry(string in) {
	this->industry = in;
}

void Stock::setName(string na) {
	this->name = na;
}

void Stock::setOwned(double own) {
	this->owned = own;
}

void Stock::setvalue(double val) {
	this->value = val;
}
void Stock::setDay_changePer(double dc) {
	this->day_changePer = dc;
}

void Stock::display_stock()const {
	cout << "show stock price";

}
void Stock::setChange(double change) {
	this->change = change;
}
double Stock::getChange() {
	return change;
}
double Stock::stockChange(double change) {

	double stockowened = change / totalStock ;

	return  stockowened *100;
 }

void Stock::setShare(double share) {
	this->share = share;
}
double Stock::getShare() {
	return share;
}