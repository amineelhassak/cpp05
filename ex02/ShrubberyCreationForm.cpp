#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("_default") // Initialize base class and target
{
    std::cout << "ShrubberyCreationForm : " << this->target << " constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm : " << this->target << " constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Robo)
    : AForm(Robo)
{
    std::cout << "ShrubberyCreationForm : " << this->target << " copy constructor is called" << std::endl;
    *this = Robo;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator =(const ShrubberyCreationForm &Robo)
{
    std::cout << "ShrubberyCreationForm : " << this->target << " Assignment Operator" << std::endl;
    if (this != &Robo)
    {
        *this = Robo;
        this->target = Robo.target;
    }
    return (*this);
}

void ShrubberyCreationForm::excute(Bureaucrat const &bure) const
{
    if (bure.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    std::ofstream newFile(this->target + "_shrubbery");
    if (newFile.is_open()) {
        newFile << TREE_ART;
        std::cout << TREE_ART;
        newFile.close();
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm : " << this->target << " Destructor is called" << std::endl;
}

