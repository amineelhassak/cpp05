#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("_default"), grade(150)
{
    std::cout << "Bureaucrat : constructeur par défaut est appelé " << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : name(name), grade(150)
{
    std::cout << "Bureaucrat : " << this->name << " constructeur avec nom est appelé " << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("_default")
{
    std::cout << "Bureaucrat : " << this->name << " constructeur avec note est appelé " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Bureaucrat : " << this->name << " constructeur avec nom et note est appelé " << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name), grade(bur.grade)
{
    std::cout << "Bureaucrat : constructeur de copie est appelé pour " << this->name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bur)
{
    if (this != &bur)
    {
        this->grade = bur.grade;
    }
    return *this;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::increment()
{
    std::cout << "Bureaucrat : " << this->name << " augmente la note" << std::endl;
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement()
{
    std::cout << "Bureaucrat : " << this->name << " diminue la note" << std::endl;
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
 
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "La note du bureaucrate est trop élevée";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "La note du bureaucrate est trop basse";
}

void Bureaucrat::signForm(Form &form)
{
    if (!form.getSignedBool() && this->getGrade() > form.getGradeToSign())
        std::cout << this->name << " couldn/’t sign " << form.getName() << "because " << std::endl;
    else
    {
        std::cout << this->name << " signed " << form.getName()<< std::endl;
        form.beSigned(*this);
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat : " << this->name << " destructeur est appelé " << std::endl;
}