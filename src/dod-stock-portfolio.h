#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>

class DodStockPortfolio
{
private:
    std::vector<std::string> stockSymbols;
    std::vector<double> stockValues;
    std::vector<double> stockAverageCosts;
    std::vector<unsigned int> numShares;
    std::unordered_map<std::string, int> stockIndices;
    unsigned int size;
    unsigned int getStockIndex(const std::string &stockSymbol);

public:
    bool constructPortfolioFromFile(const std::string &fileName);
    double getPortfolioCost();
    double getPortfolioValue();
    double getTotalReturn();
};