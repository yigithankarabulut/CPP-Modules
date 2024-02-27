#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <sstream>

Btc::Btc() {}

Btc::~Btc() {}

Btc::Btc(const Btc& other) { *this = other; }

Btc& Btc::operator=(const Btc& other) { (void)other; return *this; }

void Btc::exitError(std::string error)
{
    std::cout << "Error: " << error << std::endl;
    exit(1);
}

void Btc::printMap(std::map<std::string, double> &map)
{
    dataIt it;

    for (it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << " = " << it->second << std::endl;
    }
}

void Btc::readData()
{
    std::ifstream dataFile("data.csv");
    if (!dataFile)
        exitError("could not read data file.");

    std::string line;
    getline(dataFile, line);
    while (getline(dataFile, line))
    {
        std::istringstream strIn(line);
        std::string date, value;
        getline(strIn, date, ',');
        getline(strIn, value);
        data[date] = atof(value.c_str());
    }
    dataFile.close();
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

inputMap Btc::readInput(const char* inputFile)
{
    std::ifstream inFileStream(inputFile);
    if (!inFileStream)
        exitError("could not open input file.");

    inputMap iMap;
    std::string line, key, value;
    std::map<std::string, std::vector<double> > tmp;
    for (size_t i = 0; getline(inFileStream, line); ++i) {
        std::istringstream inStringStream(line);
        getline(inStringStream, key, '|');
        getline(inStringStream, value);
        key = trim(key);
        value = trim(value);
        if (i == 0)
        {
            if (key != "date" && value != "value")
                exitError("invalid file format.");
            continue;
        }
        if (tmp.find(key) == tmp.end())
            tmp[key] = std::vector<double>();
        if (value.empty() || !atof(value.c_str()))
            tmp[key].push_back(std::string::npos);
        else
            tmp[key].push_back(atof(value.c_str()));
        iMap[i] = tmp;
        key.clear();
        value.clear();
        tmp.clear();
    }

    inFileStream.close();
    return iMap;
}

size_t Btc::checkDate(std::string date)
{
    if (date.size() != 10)
        return 0;
    std::istringstream dateStream(date);
    std::string strYear, strMonth, strDay;
    int year, month, day;
    getline(dateStream, strYear, '-');
    year = atoi(strYear.c_str());
    if (year < 2009 || year > 2023)
        return 0;
    getline(dateStream, strMonth, '-');
    month = atoi(strMonth.c_str());
    if (month < 1 || month > 12)
        return 0;
    getline(dateStream, strDay);
    day = atoi(strDay.c_str());
    if (year % 4 == 0 && month == 2 && day > 29)
        return 0;
    if (year % 4 != 0 && month == 2 && day > 28)
        return 0;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;
    if ((day < 1 || day > 31) || (year == 2009 && month == 1 && day < 2))
        return 0;
    return 1;
}

double Btc::exchangeBtc(std::string key, double amount)
{
    dataIt it;
    dataIt prev = data.begin();

    for (it = data.begin(); it != data.end(); ++it) {
        if (it->first >= key)
        {
            if (key == it->first)
                return (amount * it->second);
            else
                return (amount * prev->second);
        }
        prev = it;
    }
    return 0;
}

void Btc::processInput(inputMap& iMap)
{
    inputIt it;
    std::vector<double>::iterator vecIt;
    std::map<std::string, std::vector<double> >::iterator secondIt;
    for (it = iMap.begin(); it != iMap.end(); ++it) {
        for (secondIt = it->second.begin(); secondIt != it->second.end(); ++secondIt) {
            if (checkDate(secondIt->first))
            {
                for (vecIt = secondIt->second.begin(); vecIt != secondIt->second.end(); ++vecIt) {
                    if (*vecIt == std::string::npos)
                        std::cout << "Error: there is no value or value is not a number." << std::endl;
                    else if (*vecIt > 1000)
                        std::cout << "Error: too large a number." << std::endl;
                    else if (*vecIt < 0)
                        std::cout << "Error: not a positive number." << std::endl;
                    else
                        std::cout << secondIt->first << " => " <<
                        *vecIt << " = " << exchangeBtc(secondIt->first, *vecIt) << std::endl;
                }
            }
            else
                std::cout << "Error: bad input => " << secondIt->first << std::endl; 
        }
    }
}

void Btc::processBtc(const char* inputFile)
{
    readData();
    inputMap iMap = readInput(inputFile);
    processInput(iMap);
}
