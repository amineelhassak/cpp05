#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("_default"),grade(150)
{
    std::cout << "Bureaucrat : default constractor is called " << std::endl;
};

Bureaucrat::Bureaucrat(const std::string &name):name(name),grade(150)
{
    std::cout << "Bureaucrat : " << this->name << " constructor #* parameterized  is called " << std::endl;
};

Bureaucrat::Bureaucrat(int grade):name("_default")
{
    std::cout << "Bureaucrat : " << this->name << " constructor #* parameterized  is called " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Bureaucrat : " << this->name << " constructor ** parameterized  is called " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
};

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
    std::cout << "Bureaucrat : " <<  this->name << " increment grade" << std::endl;
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
};

void  Bureaucrat::decrement()
{
    std::cout << "Bureaucrat : " << this->name << " decrement grade" << std::endl;
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
};

std::ostream& operator<< (std::ostream& out, const  Bureaucrat &bureaucrat ) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade Too High");
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade Too Low");
};

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat : " << this->name << " destractor is called " << std::endl;
};