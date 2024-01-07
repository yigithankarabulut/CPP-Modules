#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string	_name;
        int					_grade;

		Bureaucrat();

    public:
		Bureaucrat( std::string name , int grade );
		Bureaucrat( const Bureaucrat &ref );
		Bureaucrat& operator=( const Bureaucrat& ref );
		~Bureaucrat();


		std::string	getName() const;
		int			getGrade() const;


		void		gradePlus();
		void		gradeMinus();


		class GradeTooHighException : public std::exception 
		{
			public:
    			const char* what() const throw()
				{
        			return ("Grade Too High");
    			}
		};
		class GradeTooLowException : public std::exception 
		{
			public:
    			const char* what() const throw()
				{
        			return ("Grade Too Low");
    			}
		};
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif