cmake_minimum_required(VERSION 3.26)
project(Stock_Simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stock_Simulator main/c++/main.cpp
        main/c++/Stock.cpp
        main/c++/RealEstateStock.cpp
        main/c++/Portfolio.cpp
        main/c++/BeverageCompanyStock.cpp
        main/c++/AutomotiveCompanyStock.cpp)
