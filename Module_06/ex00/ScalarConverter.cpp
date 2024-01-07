#include "ScalarConverter.hpp"

static int findtwo(std::string str)
{
    char tmp2;
    int moref = 0, moreinc = 0, moredec = 0, morepoint = 0;
    int j = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        char tmp = str[i];
		switch (tmp)
		{
			case 'f':
				moref += 1;
				break;
			case '+':
				moreinc += 1;
				break;
			case '-':
				moredec += 1;
				break;
			case '.':
				morepoint += 1;
				break;
		}
        j = i;
    }
    tmp2 = str[j];
    if(moref > 1 || moreinc > 1 || moredec > 1 || morepoint > 1 || (moref == 1 && tmp2 != 'f'))
        return(-1);
    return(1);
}

void	ScalarConverter::convert_to_char(std::string &str)
{
	if (is_pseudo_literal(str))
	{
		std::cout << "Impossible" << std::endl;
		return ;
	}
    int num = std::atoi(str.c_str());
    char c = static_cast<char>(num);
    if (!isprint(c) || (std::stoi(str) > 125)){
        std::cout << "Non Displayable" << std::endl;
        return;
    }
	std::cout << c << std::endl; // chaining the output
}

void	ScalarConverter::convert_to_int(std::string &str)
{
	if (is_pseudo_literal(str))
	{
		std::cout << "Impossible" << std::endl;
		return;
	}
	std::cout << std::atoi(str.c_str()) << std::endl;
}

void	ScalarConverter::convert_to_float(std::string &str)
{
	float number = std::strtof(str.c_str(), nullptr); // second params is for error handling (first invalid char adress)
	if (number - static_cast<int>(number) == 0)
	{
		std::cout << number << ".0f" << std::endl;
		return ;
	}
	std::cout << number << "f" << std::endl;
}

bool	is_pseudo_literal(std::string &s)
{
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "inf"
		|| s == "-inf" || s == "+inff" || s == "inff" || s == "-inff");
}

void	ScalarConverter::convert_to_double(std::string &str)
{
	double number = std::strtod(str.c_str(), nullptr);
	if (number - static_cast<int>(number) == 0)
	{
		std::cout << number << ".0" << std::endl;
		return ;
	}
	std::cout << number << std::endl;
}

void	conversion_of_scalar_types(std::string str)
{
	std::cout	<< YEL << "Char   : ", ScalarConverter::convert_to_char(str);
	std::cout	<< YEL << "Int    : ", ScalarConverter::convert_to_int(str);
	std::cout	<< YEL << "Float  : ", ScalarConverter::convert_to_float(str);
	std::cout	<< YEL << "Double : ", ScalarConverter::convert_to_double(str);
}

bool	ScalarConverter::is_valid(std::string &str)
{
	size_t	i;
	char	c;

	if (is_pseudo_literal(str))
		return (true);
	if (str.length() == 1 && isascii(str[0]) && !isdigit(str[0])) {
		str = std::to_string(static_cast<int>(str[0]));
		return (true);
	}
	if(findtwo(str) != 1)
        return (false);
	for (i = 0; i < str.size(); i++)
	{
		c = str[i];
		if (!isdigit(c) && c != '-' && c != '+' && c != 'f'
			&& c != '.')
			return (false);
	}
	return (true);
}
