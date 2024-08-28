#include "AForm.hpp"

AForm::AForm() : name("_default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "AForme : " << this->name << " constructeur par défaut appelé " << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForme : " << this->name << " destructeur appelé " << std::endl;
}

AForm::AForm(const AForm &_Aform) : name(_Aform.name), gradeToSign(_Aform.gradeToSign), gradeToExecute(_Aform.gradeToExecute)
{
    *this = _Aform;
    std::cout << "AForme : " << this->name << " constructeur de copie appelé " << std::endl;
}

AForm &AForm::operator=(const AForm &Aform)
{
    std::cout << "AForme : " << this->name << " opérateur d'assignation appelé " << std::endl;
    if (this != &Aform)
        this->isSigned = Aform.isSigned;
    return (*this);
}

AForm::AForm(const std::string &name) : name(name), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "I) AForme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
}

AForm::AForm(const int toSign, const int toExecute) : name("_default"), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute)
{
    std::cout << "II) AForme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
    if (toSign < 1 || toExecute < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string &name, const int toSign, const int toExecute) : name(name), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute)
{
    std::cout << "III) AForme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
    if (toSign < 1 || toExecute < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExecute > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSignedBool() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
    out << Aform.getName() << " Signé : " << Aform.getSignedBool() 
        << " Grade pour signer : " << Aform.getGradeToSign()
        << " Grade pour exécuter : " << Aform.getGradeToExecute() << std::endl;
    return (out);
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Le grade est trop bas pour signer le Aformulaire");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
    std::cout << this->getName() << " a été signé par " << bureaucrat.getName() << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Le grade est trop élevé pour signer le Aformulaire");
}