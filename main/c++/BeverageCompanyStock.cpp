#include "BeverageCompanyStock.h"

BeverageCompanyStock::BeverageCompanyStock(string ind, string name,double total,double own, double day_c,double val,double share):Stock(ind, name, own, total,day_c,val,share) {
	srand(time(NULL));
}


double BeverageCompanyStock::stockChange() {
	
	int next_move = rand() % 100 + 1;

	if (next_move > 0 && next_move < 11) {
		setDay_changePer(5);
	}
	else if (next_move > 10 && next_move < 21) {
		setDay_changePer(-5);
	}
	else if (next_move > 20 && next_move < 41) {
		setDay_changePer(1);
	}
	else if (next_move > 40 && next_move < 61) {
		setDay_changePer(-1);
	}
	else if (next_move > 60 && next_move < 66) {
		setDay_changePer(10);
	}
	else if (next_move > 65 && next_move < 71) {
		setDay_changePer(-10);
	}
	else if (next_move > 70 && next_move < 73 ) {
		setDay_changePer(20);
	}
	else if (next_move > 72 && next_move < 76) {
		setDay_changePer(-20);
	}
	else if (next_move > 75 && next_move < 86) {
		setDay_changePer(2);
	}
	else if (next_move > 85 && next_move < 96) {
		setDay_changePer(-2);
	}
	else {
		setDay_changePer(0);
	}
	
	double result = Stock::stockChange(getChange()) + getDay_changePer();
	return result;//return percentange
}