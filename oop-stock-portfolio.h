#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>

struct StockPosition
{
    std::string stockSymbol;
    double stockValue;
    double stockAverageCost;
    unsigned int numShares;
};

class OopStockPortfolio
{
private:
    std::vector<StockPosition> stockPortfolio;
    unsigned int size;

public:
    bool constructPortfolioFromFile(const std::string &fileName);
    double getPortfolioValue();
    double getPortfolioCost();
    double getTotalReturn();
};
