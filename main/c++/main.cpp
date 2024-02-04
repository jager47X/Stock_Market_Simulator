#include <iostream>
#include <fstream>
#include <string>
#include "stocks/Stock.h"
#include "stocks/BankStocks.h"
#include "stocks/BeverageCompanyStock.h"
#include "stocks/AutomotiveCompanyStock.h"
#include "stocks/RealEstateStock.h"
#include "portfolio/Portfolio.h"

using namespace std;
int main()
{
    const int Max = 23;
    Stock* stocks[Max];
    Portfolio player(100000);

    stocks[0] = new BeverageCompanyStock("", "", 01,
                                         0, 0, 0, 0);
    stocks[1] = new BeverageCompanyStock("Beverage", "Black Coffee Company inc.", 421420,
                                         0, 0, 1000, 0.00);
    stocks[2] = new BeverageCompanyStock("Beverage", "Mr.Green Tea inc.", 12131,
                                         0, 0, 10, 0.00);
    stocks[3] = new BeverageCompanyStock("Beverage", "Space Water inc.", 34532,
                                         0, 0, 190, 0.01);
    stocks[4] = new BeverageCompanyStock("Beverage", "Secret Drinks Company inc.", 150320,
                                         0, 0, 230, 0.00);

    stocks[5] = new AutomotiveCompanyStock("Automotive", "The Japanese Car inc.", 50000,
        0, 0, 12200, 0.1);
    stocks[6] = new AutomotiveCompanyStock("Automotive", "American truck inc.", 59000,
                                           0, 0, 2200, 0.01);
    stocks[7] = new AutomotiveCompanyStock("Automotive", "Super fast cars inc.", 15900,
                                           0, 0, 122, 0.01);
    stocks[8] = new AutomotiveCompanyStock("Automotive", "Future cars inc.", 364630,
                                           0, 0, 623330, 0.0);
    stocks[9] = new AutomotiveCompanyStock("Automotive", "Russian Tank inc.", 52411,
                                           0, 0, 12200, 0.001);
    stocks[10] = new AutomotiveCompanyStock("Automotive", "Classic Cars Only inc.", 530400,
                                           0, 0, 1324, 0.2);

    stocks[11] = new RealEstateStock("RealEstate", "LA Real-Estate", 11200,
        0, 0, 150, 0.001);
    stocks[12] = new RealEstateStock("RealEstate", "South Park Real-Estate", 12400,
                                    0, 0, 1120, 0.002);
    stocks[13] = new RealEstateStock("RealEstate", "SF Real-Estate", 112300,
                                    0, 0, 150, 0.101);
    stocks[14] = new RealEstateStock("RealEstate", "Space Real-Estate", 12130,
                                    0, 0, 112220, 2.3);
    stocks[15] = new RealEstateStock("RealEstate", "NYC Real-Estate", 121321,
                                    0, 0, 1230, 0.21);
    stocks[16] = new RealEstateStock("RealEstate", "Hood Real-Estate", 100000,
                                    0, 0, 150, 0.31);

    stocks[17] = new BankStocks("Bank", "Bank of America", 1300,
                                     0, 0, 1320, 0.0231);
    stocks[18] = new BankStocks("Bank", "Bank of Japan", 123420,
                                     0, 0, 11240, 0.0563);
    stocks[19] = new BankStocks("Bank", "Bank of Singapore", 11230,
                                     0, 0, 132, 0.01324);
    stocks[20] = new BankStocks("Bank", "Bank of Mars", 12130,
                                     0, 0, 112220, 0.143);
    stocks[21] = new BankStocks("Bank", "Bank of China", 121213,
                                     0, 0, 1132, 0.231);
    stocks[22] = new BankStocks("Bank", "Bank of Apple", 121312,
                                     0, 0, 2340, 0.01);
    char choice = ' ';
    int day = 1;
    double inputTrade = 0;
    int stockNum = 0;
    double newOwed = 0;
    double before_trade = 0;
    double after_trade = 0;
    string saveFile="Stock-simulator-Save.txt";

    ofstream save;
    ifstream load;
    cout << "-------STOCK-SIMULATOR-GAME-------";
    cout << "\n(1)New Game\n(2)Continue Game\n";   //choose new or continue
    while (choice != '1' && choice != '2') {
        cin >> choice;
    }
    cout << "";
    switch (choice)
    {
    case '1':
        break;
    case '2':
        load.open(saveFile.c_str());
        string input;

    if(!load.is_open()){
        cout<<"No saveData found Starting a New Game\n";
        break;
    }else{


        getline(load, input);
        player.setCash(stod(input));
        getline(load, input);
        day= stoi(input);
        for (int i = 0; i < Max; i++)
        {
            getline(load, input); stocks[i]->setIndustry(input);
            getline(load, input); stocks[i]->setName(input);
            getline(load, input);
            stocks[i]->setValue(stod(input));
            getline(load, input); stocks[i]->setTotalstock(stod(input));
            getline(load, input); stocks[i]->setShare(stod(input));
            getline(load, input); stocks[i]->setOwned(stod(input));
            getline(load, input); stocks[i]->setDay_changePer(stod(input));

        }
    }


        break;
    }

    for (int i = 0; i < Max; i++) {


  // Calculate the stock change percentage
        stocks[i]->setDay_changePer(stocks[i]->stockChange());

        // Update the stock value based on the percentage change

        stocks[i]->setDay_changePer(stocks[i]->stockChange());
        double changedValue=1+(stocks[i]->getDay_changePer()/100);
        if(changedValue>100){
            changedValue=1;
        }
        double newValue = stocks[i]->getvalue() * (changedValue);
        stocks[i]->setValue(newValue);

    }
    while (choice != '6') {

        bool isEmpty= true;
        cout << "\nDAY " << day<<endl;
        before_trade = 0;
        after_trade = 0;
        cout << " (1)Display Stock List\n (2)Purchase Stock\n (3)Sell Stock \n (4)End the day of Trade\n (5)View portfolio\n (6)Save&Exit\n\n";
        cout<<"Select from the options:";
        cin >> choice;

        switch (choice) {

            case '1':
                cout << " ----------Stock List---------- \n";
                for (int i = 1; i < Max; i++) {
                    cout << "Industry Type:\t\t" << stocks[i]->getIndustry() << endl;
                    cout << "Company Name:\t\t" << stocks[i]->getName() << endl;
                    cout << "Stock Value:\t\t" << stocks[i]->getvalue() << endl;
                    cout << "Total Stock:\t\t" << stocks[i]->getTotalstock() << endl;
                    cout << "Share Percentage:\t\t" << stocks[i]->getShare() * 100 << "%" << endl;
                    cout << "Owned Stock by player:\t\t" << stocks[i]->getOwned() << endl;
                    cout << "Stock changed from yesterday:\t\t";
                    if((stocks[i]->getDay_changePer()>50)||(stocks[i]->getDay_changePer()<-50)){
                        stocks[i]->setDay_changePer(0);
                    }
                    if (stocks[i]->getDay_changePer()  > 0) {
                        cout << "+";
                    }

                    cout << stocks[i]->getDay_changePer()  << "%" << endl;
                }
                cout << "\n ----------END of Stock List---------- \n";
                cout << "Press any key to go back to the main menu:";
                cin >> choice;


                break;
            case '2':{
                cout << "Buy Stock \n";

                cout << "Current Balance is " << player.getCash() << endl << endl;
                cout << "Choose Stock from the list \n";

                for (int i = 1; i < Max; i++) {
                    int index = i + 1;
                    cout << "(" << index << ") Company Name:" << stocks[i]->getName() << ", Stock Price:"
                         << stocks[i]->getvalue() << ", Available stocks:"
                         << stocks[i]->getTotalstock() - stocks[i]->getOwned() << ", Stock owned by the player:"
                         << stocks[i]->getOwned() << endl;
                }

                cout << "Select the Stock:";
                cin >> stockNum;
                stockNum = stockNum - 1; // adjust on the array index 1-3->0-2
                cout << endl;

                cout << "Selected stock is " + stocks[stockNum]->getName() << endl;
                cout << "Set the trade amount:";
                cin >> inputTrade;
                cout << endl;

                before_trade = stocks[stockNum]->getOwned();
                newOwed = player.buyStock(inputTrade, stocks[stockNum]->getvalue(), stocks[stockNum]->getOwned());
                // Calculate the overall change in the portfolio based on the purchased stock's change
                double portfolioChange = newOwed - before_trade;
                // Apply the overall change to all stocks in the portfolio
                for (int i = 1; i < Max; i++) {
                    stocks[i]->setDay_changePer(stocks[i]->stockChange());
                }
                // Update the stock value based on the new percentage change
                for (int i = 1; i < Max; i++) {
                    double newValue = stocks[i]->getvalue() * (1 + stocks[i]->getDay_changePer());
                    stocks[i]->setValue(newValue);
                }
                after_trade = newOwed + before_trade;
                stocks[stockNum]->setChange(after_trade);
                break;}
        case '3':
            cout << "\n Sell Stock \n";
            cout << "Current Balance is " << player.getCash() << endl << endl;
            cout << "Choose Stock from the list \n";
            for (int i = 1; i < Max; i++)
            {
                int index=i+1;
                cout << "(" << index << ") Company Name:" << stocks[i]->getName() << ", Stock Price:" << stocks[i]->getvalue() << ", Available stocks:" << stocks[i]->getTotalstock() - stocks[i]->getOwned() << ", Stock owned by the player:" << stocks[i]->getOwned() << endl;
            }

                cout << "Select the Stock:";
                cin >> stockNum;
                stockNum=stockNum-1;//adjust on the array index 1-3->0-2



                cout << "Selected  stock  is "+stocks[stockNum]->getName()<<endl;
            cout << "Set the trade amount:";
            cin >> inputTrade;
                cout << endl;
            before_trade = stocks[stockNum]->getOwned();


            newOwed = player.sellStock(inputTrade, stocks[stockNum]->getvalue(), stocks[stockNum]->getOwned());
            if (newOwed > -1) {
                stocks[stockNum]->setOwned(newOwed);
            }

            after_trade = newOwed - before_trade;
            stocks[stockNum]->setChange(after_trade);

            break;

        case '4':
            for (int i = 1; i < Max; i++) {
                stocks[i]->setDay_changePer(stocks[i]->stockChange());

                // Update the stock value based on the percentage change

                stocks[i]->setDay_changePer(stocks[i]->stockChange())   ;
                double changedValue=1+(stocks[i]->getDay_changePer()/100);
                double newValue = stocks[i]->getvalue() * (changedValue);
                stocks[i]->setValue(newValue);
            }

                day++;
                cout << "\nMove to the next day\n";
                break;
        case '5':
            cout << "\nPlayer's Portfolio\n\n";

            for (int i = 1; i < Max; i++)
            {
                if(  stocks[i]->getOwned()>0){
                    cout << "Industry Type:\t\t" << stocks[i]->getIndustry() << endl;
                    cout << "Company Name:\t\t" << stocks[i]->getName() << endl;
                    cout << "Stock Value:\t\t" << stocks[i]->getvalue() << endl;
                    cout << "Owned Stock by player:\t\t" << stocks[i]->getOwned() << endl;
                    isEmpty= false;
                }


            }
            if(isEmpty){
                cout << "Player currently does not own any stock." << endl;
            }
            cout << "Current Balance is " << player.getCash() << endl << endl;
            break;
        case '6':
            save.open(saveFile.c_str());
            save << player.getCash() << endl;
            save << day << endl;
            for (int i = 1; i < Max; i++)
            {
                save<< stocks[i]->getIndustry() << endl;
                save<< stocks[i]->getName() << endl;
                save<< stocks[i]->getvalue() << endl;
                save<< stocks[i]->getTotalstock() << endl;
                save<< stocks[i]->getShare() << endl;
                save<< stocks[i]->getOwned() << endl;
                save<< stocks[i]->getDay_changePer()<< endl;
            }

            cout << "Saved.\n";

            break;



        }


    }


}