#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    Btc bitcoin;

    if (ac != 2)
        bitcoin.exitError("could not open file.");
    bitcoin.processBtc(av[1]);
    return 0;
}
