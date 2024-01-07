#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat james("James", 24);

		std::cout << "Before gradePlus(): " << james << std::endl;
		james.gradePlus();
		std::cout << "After gradePlus(): " << james << std::endl;

		Bureaucrat sam("Sam", 1);

		std::cout << "Before gradeMinus(): " << sam << std::endl;
		sam.gradePlus();
	} 
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}