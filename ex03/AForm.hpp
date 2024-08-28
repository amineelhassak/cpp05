#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
    	bool	isSigned;
    	const	int gradeToSign;
    	const	int gradeToExecute;
	public:
		AForm();
		AForm &operator=(const AForm &Aform);
		AForm(const AForm &Aform);
		virtual ~AForm();

		AForm(const std::string &name);
		AForm(const int toSigne, const int toExcute);
		AForm(const std::string &name, const int toSigne, const int toExcute);

		virtual void excute( Bureaucrat const & ) const  = 0;
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

std::ostream &operator<<(std::ostream &out, const AForm &Aform);
#endif