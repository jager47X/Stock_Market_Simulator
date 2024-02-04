#include "Stock.h"
#include "BeverageCompanyStock.h"
#include "Portfolio.h"

Portfolio::Portfolio(double cash) {
    this->cash = cash;
}

double Portfolio::buyStock(double input, double value, double ownval) {
    double total= input* value; 
    
    if (total <= cash) {
       cash = cash - total;
       ownval = ownval + input;
       cout << "Transition was succeed\n";
        return ownval;
    }
    else {
        cout << "insufficient cash\n";
        return -1;
    }
    
}
double Portfolio::sellStock(double input, double value,double ownval) {
 
    if (input <= ownval) {
        double total = input * value;
        cash = cash+total;
        ownval = ownval - input;
        cout << "Transition was succeed\n";
        return ownval;
    }
    else {
        cout << "insufficient stock\n";
        return -1;
    }
}


void Portfolio::setCash(double cash) {
   this->cash=cash;
}
double Portfolio::getCash() {
    return cash;
}