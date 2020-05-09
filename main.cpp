#include "dod-stock-portfolio.h"
#include "oop-stock-portfolio.h"
#include <chrono>

#define LOOPS 10000
#define PORTFOLIO_CSV "fake-stock-portfolio.csv"

int main()
{
    DodStockPortfolio dataOrientedPortfolio;
    OopStockPortfolio objectOrientedPortfolio;
    
    if (!dataOrientedPortfolio.constructPortfolioFromFile(PORTFOLIO_CSV) || 
    !objectOrientedPortfolio.constructPortfolioFromFile(PORTFOLIO_CSV)) {
        std::cout << PORTFOLIO_CSV << " is empty or does not exist." << std::endl;
        std::cout << "Try running 'make generate-portfolio' to generate the executable that creates the portfolio. Then run './generate-portfolio'" << std::endl;
        return 0;
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < LOOPS; i++)
    {
        dataOrientedPortfolio.getTotalReturn();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Data Oriented: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < LOOPS; i++)
    {
        objectOrientedPortfolio.getTotalReturn();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Object Oriented: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std:: endl;
}