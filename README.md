# Stock Simulator Game

## Table of Contents
- [Introduction](#introduction)
- [Classes](#classes)
  - [Stock](#stock)
  - [BeverageCompanyStock](#beveragecompanystock)
  - [AutomotiveCompanyStock](#automotivecompanystock)
  - [RealEstateStock](#realestatestock)
  - [Portfolio](#portfolio)
- [Main Function](#main-function)
- [Game Flow](#game-flow)
- [File Handling](#file-handling)
- [Conclusion](#conclusion)

## 1. Introduction
The Stock Simulator Game is a console-based application written in C++. The game allows players to simulate buying and selling stocks from different industries, managing their portfolio, and making investment decisions. The project is structured using various classes to represent different aspects of the game.

## 2. Classes 
### 2.1 Stock
Represents a generic stock with common attributes.
- Attributes:
  - Industry type
  - Company name
  - Stock value
  - Total stock
  - Share percentage
  - Owned stock by the player
  - Stock change percentage for the day
- Methods:
  - stockChange: Calculates the stock change percentage for the day.

### 2.2 BeverageCompanyStock
Derived from the Stock class.
Represents a stock of a beverage company.


### 2.3 AutomotiveCompanyStock 
Derived from the Stock class.
Represents a stock of an automotive company.


### 2.4 RealEstateStock 
Derived from the Stock class.
Represents a stock of a real estate company.


### 2.5 Portfolio 
Manages the player's portfolio.
- Attributes:
  - Player's cash balance.
- Methods:
  - buyStock: Handles the logic for buying stocks.
  - sellStock: Handles the logic for selling stocks.

## 3. Main Function 
- Initializes an array of Stock pointers to hold different stocks.
- Creates instances of various stock types and adds them to the array.
- Manages player interaction, including buying, selling, displaying stock information, and progressing to the next day.
- Saves and loads game progress using file handling.

## 4. Game Flow 
- Player starts with a cash balance and a portfolio of stocks.
- Player can choose to display the stock list, buy or sell stocks, view the portfolio, or end the day.
- Buying or selling stocks updates the player's portfolio and the stock information.
- At the end of each day, stock values are updated based on a random change percentage.
- The game progresses as the player makes decisions and manages their portfolio.

## 5. File Handling 
- The game allows saving and loading of the player's progress.
- Saves player's cash balance, current day, and details of each stock in the portfolio.

## 6. Conclusion
The Stock Simulator Game provides an interactive environment for users to simulate stock trading. By using different classes to represent stock types and player portfolios, the code structure is modular and extensible. The file handling functionality allows players to save and continue their progress in the game. Further enhancements and features can be added to make the game more engaging and realistic.
