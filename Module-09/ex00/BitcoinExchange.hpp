#pragma once

#include <iostream>
#include <map>
#include <vector>

typedef std::map<size_t, std::map<std::string,
        std::vector<double> > >::iterator inputIt;
typedef std::map<size_t, std::map<std::string, std::vector<double> > > inputMap;
typedef std::map<std::string, double>::iterator dataIt;

class Btc
{
public:
    double exchangeBtc(std::string key, double amount);
    inputMap readInput(const char* inputFile);
    size_t checkDate(std::string date);
    void processInput(inputMap& iMap);
    void processBtc(const char* file);
    void readData();
    void printMap(std::map<std::string, double> &map);
    void exitError(std::string error);
    Btc();
    ~Btc();
    Btc(const Btc& other);
    Btc& operator=(const Btc& other);
private:
    std::map<std::string, double> data;
};
