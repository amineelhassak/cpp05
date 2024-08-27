#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), target("_default")
{
    std::cout << "RobotomyRequestForm : constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) 
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm : " << this->target << " constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Robo) 
    : AForm(Robo), target(Robo.target)
{
    std::cout << "RobotomyRequestForm : " << this->target << " copy constructor is called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Robo)
{
    std::cout << "RobotomyRequestForm : " << this->target << " Assignment Operator is called" << std::endl;
    if (this != &Robo)
    {
        *this = Robo;
        this->target = Robo.target;
    }
    return (*this);
}

void RobotomyRequestForm::excute( Bureaucrat const & bure) const
{
    int success;
    if (bure.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    std::srand(std::time(NULL));
    success = std::rand() % 2;
    if (success)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy on " << this->target << " has failed!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm : " << this->target << " Destructor is called" << std::endl;
}
