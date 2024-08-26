#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
        
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const std::string &name);
        Bureaucrat(const std::string &name, int grade);

        const std::string &getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        class GradeTooHighException : public std::exception
        {   
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        ~Bureaucrat();
};

std::ostream& operator<< (std::ostream& out, const  Bureaucrat &bureaucrat );

#endif