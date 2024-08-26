#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45),target("_default")
{
    std::cout << "RobotomyRequestForm : constractor is callled" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target):AForm("ShrubberyCreationForm", 72, 45),target(target)
{
    std::cout << "RobotomyRequestForm : " << this->target << " constractor is callled" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Robo):AForm(Robo)
{
    std::cout << "RobotomyRequestForm : " << this->target <<" parametrized constractor is called" << std::endl;
    *this = Robo;
}

RobotomyRequestForm &RobotomyRequestForm::operator =(const RobotomyRequestForm &Robo)
{
    std::cout << "RobotomyRequestForm : " << this->target << " Assignment Operator "<< std::endl;
    if (this != &Robo)
    {
        this->target = Robo.target;
    }
    return (*this);
}

void RobotomyRequestForm::excute( Bureaucrat const & ) const
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm : " << this->target << " Destractor is callled" << std::endl;
}
