#pragma once
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        static AForm* createShrubberyForm(std::string const & target) {
            return new ShrubberyCreationForm(target);
        }

        static AForm* createRobotomyForm(std::string const & target) {
            return new RobotomyRequestForm(target);
        }

        static AForm* createPresidentialForm(std::string const & target) {
            return new PresidentialPardonForm(target);
        }
    public:
        Intern();
        Intern(const Intern &);
        Intern &operator =(const Intern &);
        AForm *makeForm(std::string const & formName, std::string const & target);
        ~Intern();
};