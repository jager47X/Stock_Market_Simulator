#pragma once
#include "Stock.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#ifndef STOCK_SIMULATOR_BANKSTOCKS_H
#define STOCK_SIMULATOR_BANKSTOCKS_H

class BankStocks :public Stock
{
public:
    BankStocks(string = "Automotive", string = " ", double = 0, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
    double virtual stockChange();

private:
    double owned;
    double change;
};


#endif //STOCK_SIMULATOR_BANKSTOCKS_H
