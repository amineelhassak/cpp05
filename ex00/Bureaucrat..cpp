#include "Bureaucrat.hpp"

int Bureaucrat::getGrade() const
{
    return (this->grade);
};

const std::string &Bureaucrat::getName() const
{
    return (this->name);
};

void Bureaucrat::increment()
{
    if (this->grade - 1 <= 0)
        throw GradeTooLowException();
    this->grade--;
};

void  Bureaucrat::decrement()
{
    if (this->grade + 1 > 150)
        throw GradeTooHighException();
    this->grade++;
};