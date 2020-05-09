#include "dod-stock-portfolio.h"

unsigned int DodStockPortfolio::getStockIndex(const std::string &stockSymbol)
{
    return stockIndices[stockSymbol];
}

bool DodStockPortfolio::constructPortfolioFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::srand(std::time(0));
    size = 0;
    std::string line = "";
    std::getline(file, line);
    if (line.length() == 0) {
        return false;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        stockSymbols.push_back(token);
        stockIndices[token] = size;
        std::getline(ss, token, ',');
        numShares.push_back(std::stoi(token));
        std::getline(ss, token, ',');
        stockAverageCosts.push_back(std::stod(token));
        std::getline(ss, token);
        stockValues.push_back(std::stod(token));
        ++size;
    }
    file.close();
    return true;
}

double DodStockPortfolio::getPortfolioValue()
{
    double returnVal = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        // std::cout << &(numShares[i]) << std::endl;
        // std::cout << &(stockValues[i]) << std::endl;
        returnVal += (numShares[i] * stockValues[i]);
    }
    return returnVal;
}

double DodStockPortfolio::getPortfolioCost()
{
    double returnVal = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        returnVal += (numShares[i] * stockAverageCosts[i]);
    }
    return returnVal;
}

double DodStockPortfolio::getTotalReturn()
{
    return (getPortfolioValue() / getPortfolioCost()) * 100 - 100.0;
}