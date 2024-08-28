#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// void leak()
// {
//     system("leaks Bureaucrat");
// }

int main() {
    // atexit(leak);
    try 
    {
        {
            std::cout << "\x1b[32m" << std::endl;
            Bureaucrat b2("Alice", 42);
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
            b2.increment();
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
            b2.decrement();
            std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
        }
        {
            Bureaucrat b1;
            std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
            b1.increment();
            std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
            b1.decrement();
            b1.decrement();
            std::cout << b1.getName() << "after exception" << ", bureaucrat grade " << b1.getGrade() << std::endl;
        }
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat b4("Charlie", 1);
        std::cout << b4.getName() << ", bureaucrat grade " << b4.getGrade() << std::endl;
        b4.increment();
        std::cout << b4;
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("amine",2);
        ShrubberyCreationForm sub;
        sub.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 24);
        PresidentialPardonForm pre;
        pre.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 24);
        RobotomyRequestForm Robo;
        Robo.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("amine",200);
        ShrubberyCreationForm sub;
        sub.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 300);
        PresidentialPardonForm pre;
        pre.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 300);
        RobotomyRequestForm Robo;
        Robo.excute(bur);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 78);
        PresidentialPardonForm pre;
        bur.executeForm(pre);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        Bureaucrat bur("_____Bureaucrat____", 20);
        PresidentialPardonForm pre;
        bur.executeForm(pre);
        bur.signForm(pre);
        Bureaucrat bur_c("_____Bureaucrat____", 26);
        bur_c.signForm(pre);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n\n================================================================================\n" << std::endl;
        PresidentialPardonForm pre;
        Bureaucrat bur_c("_____Bureaucrat____", 26);
        bur_c.signForm(pre);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
