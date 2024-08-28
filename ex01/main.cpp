#include "Bureaucrat.hpp"
#include <iostream>

// void leak()
// {
//     system("leaks Bureaucrat");
// }

int main() {
    // atexit(leak);
    {
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
    }
    {
        try {
            std::cout << "\n\n================================================================================\n" << std::endl;
            Form formA("Form A", 50, 75);
            std::cout << formA << std::endl;

            Bureaucrat alice("Alice", 42);
            std::cout << alice << std::endl;

            alice.signForm(formA);
            std::cout << formA << std::endl;

            Bureaucrat bob("Bob", 60);
            std::cout << bob << std::endl;
            bob.signForm(formA);
            std::cout << formA << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try
        {
            Form form(151,152);
        }
        catch(const Form::GradeTooLowException &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(const Form::GradeTooHighException &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            Form form("HIGHT",0,-1);
        }
        catch(const Form::GradeTooLowException &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(const Form::GradeTooHighException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}
