#include <fstream>
#include <ctime>
#define FILE_NAME "stock-symbols.txt"

int main()
{
    std::ifstream file(FILE_NAME);
    std::ofstream newFile("fake-stock-portfolio.csv");
    newFile << "Stock Symbol,"
            << "Number of Shares Owned,"
            << "Average Cost,"
            << "Current Value,\n";
    std::srand(std::time(0));
    std::string ss;
    while (file >> ss)
    {
        newFile << ss << ",";
        newFile << std::rand() % 10 + 1 << ",";
        newFile << (std::rand() % 10000 + 7500) / 100.0 << ",";
        newFile << (std::rand() % 10000 + 10000) / 100.0 << ",\n";
    }
    file.close();
}