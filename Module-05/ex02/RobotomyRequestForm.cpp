#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( RobotomyRequestForm& rhs )
{
    ( void )rhs;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if ( executor.getGrade() > this->getGradeExec() )
        throw AForm::GradeTooLowException();
    else {
        static int  i;
        if ( i % 2 == 0 )
            std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
        i++;
    }
}