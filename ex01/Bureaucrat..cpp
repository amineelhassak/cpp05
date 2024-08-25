#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("_default"),grade(150)
{
    std::cout << "Bureaucrat : default constractor is called " << std::endl;
};

Bureaucrat::Bureaucrat(const std::string &name):name(name),grade(150)
{
    std::cout << "Bureaucrat : constructor #* parameterized  is called " << std::endl;
};


Bureaucrat::Bureaucrat(int grade):name("_default")
{
    std::cout << "Bureaucrat : constructor #* parameterized  is called " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
};


Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Bureaucrat : constructor ** parameterized  is called " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name)
{
    std::cout << "Bureaucrat : Copy Constractor is Called " << std::endl;
    *this = bur;
}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat & bur)
{
    std::cout << "Bureaucrat  : Assignment Operator "<< std::endl;
    if (this != &bur)
    {
        this->grade = bur.getGrade();
    }
    return (*this);
}

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
    std::cout << "Bureaucrat : increment grade" << std::endl;
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
};

void  Bureaucrat::decrement()
{
    std::cout << "Bureaucrat : decrement grade" << std::endl;
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
    return ("Bureaucrat  Grade Too High");
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade Too Low");
};

void Bureaucrat::signForm(Form &form)
{
    if (this->getGrade() > form.getGradeToSign()) //?????????????????????.
        std::cout << this->name << " couldn/’t sign " << form.getName() << "because " << std::endl;
    else
    {
        std::cout << this->name << " signed " << form.getName()<< std::endl;
        form.beSigned(*this);
    }
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat : destractor is called " << std::endl;
};