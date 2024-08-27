#include "Form.hpp"

Form::Form() 
    : name("_default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Forme : " << this->name << " constructeur par défaut appelé " << std::endl;
}

Form::Form(const std::string &name)
    : name(name), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "I) Forme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
}

Form::Form(const int toSign, const int toExecute) 
    : name("_default"), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute)
{
    std::cout << "II) Forme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
    if (toSign < 1 || toExecute < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string &name, const int toSign, const int toExecute) 
    : name(name), isSigned(false), gradeToSign(toSign), gradeToExecute(toExecute)
{
    std::cout << "III) Forme : " << this->name << " constructeur avec paramètre appelé " << std::endl;
    if (toSign < 1 || toExecute < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &_form) 
    : name(_form.name), gradeToSign(_form.gradeToSign), gradeToExecute(_form.gradeToExecute)
{
    *this = _form;
    std::cout << "Forme : " << this->name << " constructeur de copie appelé " << std::endl;
}

Form &Form::operator=(const Form &form)
{
    std::cout << "Forme : " << this->name << " opérateur d'assignation appelé " << std::endl;
    if (this != &form)
        this->isSigned = form.isSigned;
    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSignedBool() const
{
    return (this->isSigned);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " Signé : " << form.getSignedBool() 
        << " Grade pour signer : " << form.getGradeToSign()
        << " Grade pour exécuter : " << form.getGradeToExecute() << std::endl;
    return (out);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
    std::cout << this->getName() << " a été signé par " << bureaucrat.getName() << std::endl;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Le grade est trop bas pour signer le formulaire");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Le grade est trop élevé pour signer le formulaire");
}

Form::~Form()
{
    std::cout << "Forme : " << this->name << " destructeur appelé " << std::endl;
}
