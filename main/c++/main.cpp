#include <iostream>
#include <fstream>
#include <string>
#include "Stock.h"
#include "BeverageCompanyStock.h"
#include "AutomotiveCompanyStock.h"
#include "RealEstateStock.h"
#include "Portfolio.h"

using namespace std;
int main()
{
    const int Max = 3;
    Stock* stocks[Max];
    Portfolio player(100000);

    stocks[0] = new BeverageCompanyStock("Beverage", "Soda Company", 15000,
        0, 0, 1000, 0.05);
    stocks[1] = new AutomotiveCompanyStock("Automotive", "Toyota", 5000,
        0, 0, 12200, 0.1);
    stocks[2] = new RealEstateStock("RealEstate", "LA real-estate", 100000,
        0, 0, 150, 0.001);
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


        getline(load, input);  player.setCash(stod(input));

        getline(load, input);  day= stoi(input);
        for (int i = 0; i < Max; i++)
        {
            getline(load, input); stocks[i]->setIndustry(input);
            getline(load, input); stocks[i]->setName(input);
            getline(load, input); stocks[i]->setvalue(stod(input));
            getline(load, input); stocks[i]->setTotalstock(stod(input));
            getline(load, input); stocks[i]->setShare(stod(input));
            getline(load, input); stocks[i]->setOwned(stod(input));
            getline(load, input); stocks[i]->setDay_changePer(stod(input));

        }
    }


        break;
    }

    while (choice != '6') {
        bool isEmpty= true;
        cout << "\nDAY " << day<<endl;
        before_trade = 0;
        after_trade = 0;
        cout << " (1)Display Stock List\n (2)Purchase Stock\n (3)Sell Stock \n (4)End the day of Trade\n (5)View portfolio\n (6)Save&Exit\n\n";
        cout<<"Select from the options:";
        cin >> choice;

        switch (choice)
        {

        case '1':
            cout << " ----------Stock List---------- \n";
            for (int i = 0; i < Max; i++)
            {
                cout << "Industry Type:\t\t" << stocks[i]->getIndustry() << endl;
                cout << "Company Name:\t\t" << stocks[i]->getName() << endl;
                cout << "Stock Value:\t\t" << stocks[i]->getvalue() << endl;
                cout << "Total Stock:\t\t" << stocks[i]->getTotalstock() << endl;
                cout << "Share Percentage:\t\t" << stocks[i]->getShare() * 100 << "%" << endl;
                cout << "Owned Stock by player:\t\t" << stocks[i]->getOwned() << endl;
                cout << "Stock changed from yesterday:\t\t";
                if (stocks[i]->getDay_changePer() * 100 > 0) {
                    cout << "+";
                }
                cout << stocks[i]->getDay_changePer() * 100 << "%" << endl;
            }
                cout << "\n ----------END of Stock List---------- \n";
            cout << "Press any key to go back to the main menu:";
            cin>>choice;


            break;
        case '2':
            cout << "Buy Stock \n";

            cout << "Current Balance is " << player.getCash() << endl << endl;
            cout << "Choose Stock from the list \n";

            for (int i = 0; i < Max; i++)
            {
                int index=i+1;
                cout << "(" <<  index << ") Company Name:" << stocks[i]->getName() << ", Stock Price:" << stocks[i]->getvalue() << ", Available stocks:" << stocks[i]->getTotalstock() - stocks[i]->getOwned() << ", Stock owned by the player:" << stocks[i]->getOwned() << endl;

            }

            cout << "Select the Stock:";
            cin >> stockNum;
            stockNum=stockNum-1;//adjust on the array index 1-3->0-2
                cout << endl;

            cout << "Selected stock is "+stocks[stockNum]->getName()<<endl;
            cout << "Set the trade amount:";
            cin >> inputTrade;
                cout << endl;


            before_trade = stocks[stockNum]->getOwned();
            newOwed = player.buyStock(inputTrade, stocks[stockNum]->getvalue(), stocks[stockNum]->getOwned());
            if (newOwed > -1) {
                stocks[stockNum]->setOwned(newOwed);
            }
            after_trade = newOwed + before_trade;
            stocks[stockNum]->setChange(after_trade);

            break;
        case '3':
            cout << "\n Sell Stock \n";
            cout << "Current Balance is " << player.getCash() << endl << endl;
            cout << "Choose Stock from the list \n";
            for (int i = 0; i < Max; i++)
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
            for (int i = 0; i < Max; i++)
            {
                stocks[i]->setDay_changePer(stocks[i]->stockChange(after_trade));
                double newValue = stocks[i]->getvalue() * (1 + stocks[i]->getDay_changePer());
                stocks[i]->setvalue(newValue);

            }


            day++;
            cout << "\nMove next day\n";

            break;
        case '5':
            cout << "\nPlayer's Portfolio\n\n";

            for (int i = 0; i < Max; i++)
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
            for (int i = 0; i < Max; i++)
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