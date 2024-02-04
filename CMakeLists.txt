cmake_minimum_required(VERSION 3.26)
project(Stock_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stock_Simulator main/c++/main.cpp
        main/c++/stocks/Stock.cpp
        main/c++/stocks/RealEstateStock.cpp
        main/c++/portfolio/Portfolio.cpp
        main/c++/stocks/BeverageCompanyStock.cpp
        main/c++/stocks/AutomotiveCompanyStock.cpp
        main/c++/stocks/BankStocks.h
        main/c++/stocks/BankStocks.cpp)
