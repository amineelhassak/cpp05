#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const	std::string name;
    	bool	isSigned;
    	const	int gradeToSign;
    	const	int gradeToExecute;
	public:
		Form();
		Form &operator=(const Form &form);
		Form(const Form &form);
		~Form();

		Form(const std::string &name);
		Form(const int toSigne, const int toExcute);
		Form(const std::string &name, const int toSigne, const int toExcute);

		std::string	getName 	( void ) const;
		bool		getSignedBool  	( void ) const;
		int 		getGradeToSign  	( void ) const;
		int 		getGradeToExecute	( void ) const;

		class GradeTooHighException:public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);
#endif