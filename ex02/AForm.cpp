#include "AForm.hpp"

AForm::AForm():name("_default"),isSigned(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "AForm : " << this->name << " default constractor is called " << std::endl;
}

AForm::AForm(const std::string name):name(name),isSigned(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "I) AForm : " <<  this->name << " parameterized constractor is called " << std::endl;
}


AForm::AForm(const int toSigne, const int toExcute) : name("_default"), isSigned(false),gradeToSign(toSigne), gradeToExecute(toExcute)
{
    std::cout << "II) AForm : " << this->name << " parameterized constractor is called " << std::endl;
    if (toSigne < 1 || toExcute < 1)
        throw GradeTooHighException();
    if (toSigne > 150 || toExcute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int toSigne, const int toExcute) : name(name),isSigned(false) ,gradeToSign(toSigne), gradeToExecute(toExcute)
{
    std::cout << "III) AForm : " << this->name << " parameterized constractor is called " << std::endl;
    if (toSigne < 1 || toExcute < 1)
        throw GradeTooHighException();
    if (toSigne > 150 || toExcute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "AForm : " << this->name << " Destractor is called " << std::endl;
}

AForm::AForm(const AForm &_Aform):name(_Aform.name),gradeToSign(_Aform.gradeToSign),gradeToExecute(_Aform.gradeToExecute)
{
    *this = _Aform;
    std::cout << "AForm : " << this->name <<"Copy Constructor is Called " << std::endl;
}

AForm &AForm::operator=(const AForm &Aform)
{
    std::cout << "AForm  : " << this->name << " Assignment Operator "<< std::endl;
    if (this != &Aform)
        this->isSigned = Aform.isSigned;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSignedBool() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign  	( void ) const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute	( void ) const
{
    return (this->gradeToExecute);
}

std::ostream &operator << (std::ostream &out,AForm &Aform)
{
    out << Aform.getName() << " SignedBool " << Aform.getSignedBool() << " GradeToSign : " << Aform.getGradeToSign() << " GradeToExecute : " << Aform.getGradeToExecute() << std::endl;
    return (out);
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
    std::cout << this->getName() << " AForm was signed by " << bureaucrat.getName() << std::endl;
}

const char * AForm::GradeTooLowException::wath() const throw()
{
    return ("AForm Too Low");
}

const char * AForm::GradeTooHighException::wath() const throw()
{
    return ("AForm Too Hight");
}