#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern :  constractor is callled" << std::endl;
}

Intern::Intern(const Intern &Robo)
{
    std::cout << "Intern : parametrized constractor is called" << std::endl;
    *this = Robo;
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target)
{
        std::string formNames[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
        };
        
        AForm* (*formCreators[])(std::string const &) = {
            &createShrubberyForm,
            &createRobotomyForm,
            &createPresidentialForm
        };
        
        for (int i = 0; i < 3; i++) {
            if (formName == formNames[i]) {
                std::cout << "Intern creates " << formName << std::endl;
                return formCreators[i](target);
            }
        }
        std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
        return (NULL);
}

AForm* Intern::createShrubberyForm(std::string const & target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string const & target)
{
            return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string const & target)
{
    return new PresidentialPardonForm(target);
}

Intern &Intern::operator = (const Intern &Robo)
{
    std::cout << "Intern :  Assignment Operator "<< std::endl;
    (void)(Robo);
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern :  Destractor is callled" << std::endl;
}