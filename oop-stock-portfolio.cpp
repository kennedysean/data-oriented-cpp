#include "oop-stock-portfolio.h"

bool OopStockPortfolio::constructPortfolioFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::srand(std::time(0));
    size = 0;
    std::string line;
    std::getline(file, line);
    if (line.length() == 0) {
        return false;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        StockPosition stockPosition;
        std::getline(ss, stockPosition.stockSymbol, ',');
        std::getline(ss, token, ',');
        stockPosition.numShares = std::stoi(token);
        std::getline(ss, token, ',');
        stockPosition.stockAverageCost = std::stod(token);
        std::getline(ss, token);
        stockPosition.stockValue = std::stod(token);
        stockPortfolio.push_back(stockPosition);
        ++size;
    }
    file.close();
    return true;
}

double OopStockPortfolio::getPortfolioValue()
{
    double returnVal = 0;
    std::for_each(stockPortfolio.begin(), stockPortfolio.end(), 
        [&returnVal](const StockPosition &a) { returnVal += (a.numShares * a.stockValue); });
    return returnVal;
}

double OopStockPortfolio::getPortfolioCost()
{
    double returnVal = 0;
    std::for_each(stockPortfolio.begin(), stockPortfolio.end(), 
        [&returnVal](const StockPosition &a) { returnVal += (a.numShares * a.stockAverageCost); });
    return returnVal;
}

double OopStockPortfolio::getTotalReturn()
{
    return (getPortfolioValue() / getPortfolioCost()) * 100 - 100.0;
}
