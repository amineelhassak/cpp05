#include "Form.hpp"

Form::Form():name("_default"),isSigned(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "Form : " << this->name << " default constractor is called " << std::endl;
}

Form::Form(const std::string name):name(name),isSigned(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "I) Form : " <<  this->name << " parameterized constractor is called " << std::endl;
}


Form::Form(const int toSigne, const int toExcute) : name("_default"), isSigned(false),gradeToSign(toSigne), gradeToExecute(toExcute)
{
    std::cout << "II) Form : " << this->name << " parameterized constractor is called " << std::endl;
    if (toSigne < 1 || toExcute < 1)
        throw GradeTooHighException();
    if (toSigne > 150 || toExcute > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string name, const int toSigne, const int toExcute) : name(name),isSigned(false) ,gradeToSign(toSigne), gradeToExecute(toExcute)
{
    std::cout << "III) Form : " << this->name << " parameterized constractor is called " << std::endl;
    if (toSigne < 1 || toExcute < 1)
        throw GradeTooHighException();
    if (toSigne > 150 || toExcute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form : " << this->name << " Destractor is called " << std::endl;
}

Form::Form(const Form &_form):name(_form.name),gradeToSign(_form.gradeToSign),gradeToExecute(_form.gradeToExecute)
{
    *this = _form;
    std::cout << "Form : " << this->name <<"Copy Constructor is Called " << std::endl;
}

Form &Form::operator=(const Form &form)
{
    std::cout << "Form  : " << this->name << " Assignment Operator "<< std::endl;
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

int Form::getGradeToSign  	( void ) const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute	( void ) const
{
    return (this->gradeToExecute);
}

std::ostream &operator << (std::ostream &out,Form &form)
{
    out << form.getName() << " SignedBool " << form.getSignedBool() << " GradeToSign : " << form.getGradeToSign() << " GradeToExecute : " << form.getGradeToExecute() << std::endl;
    return (out);
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
    std::cout << this->getName() << " Form was signed by " << bureaucrat.getName() << std::endl;
}

const char * Form::GradeTooLowException::wath() const throw()
{
    return ("Form Too Low");
}

const char * Form::GradeTooHighException::wath() const throw()
{
    return ("Form Too Hight");
}