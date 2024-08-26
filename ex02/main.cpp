#include "Bureaucrat.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"

int main() {
    // try 
    // {
    //     {
    //         Bureaucrat b2("Alice", 42);
    //         std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
    //         b2.increment();
    //         std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
    //         b2.decrement();
    //         std::cout << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
    //     }
    //     {
    //         Bureaucrat b1;
    //         std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
    //         b1.increment();
    //         std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
    //         b1.decrement();
    //         b1.decrement();
    //         std::cout << b1.getName() << "after exception" << ", bureaucrat grade " << b1.getGrade() << std::endl;
    //     }
    // }
    // catch (const Bureaucrat::GradeTooHighException &e) {
    //     std::cerr << "Caught an exception: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException &e) {
    //     std::cerr << "Caught an exception: " << e.what() << std::endl;
    // }

    // try {
    //     std::cout << "\n\n================================================================================\n" << std::endl;
    //     Bureaucrat b4("Charlie", 1);
    //     std::cout << b4.getName() << ", bureaucrat grade " << b4.getGrade() << std::endl;
    //     b4.increment();
    //     std::cout << b4;
    // }
    // catch (const Bureaucrat::GradeTooHighException &e) {
    //     std::cerr << "Caught an exception: " << e.what() << std::endl;
    // }
    // catch (const Bureaucrat::GradeTooLowException &e) {
    //     std::cerr << "Caught an exception: " << e.what() << std::endl;
    // }
    Bureaucrat bur;
    ShrubberyCreationForm sub;
    sub.excute(bur);
    return (0);
}
