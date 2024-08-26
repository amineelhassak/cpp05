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
		AForm(const AForm &Aform);
		AForm(const std::string name);
		AForm(const int toSigne, const int toExcute);
		AForm(const std::string name, const int toSigne, const int toExcute);
		virtual void excute( Bureaucrat const & ) const  = 0;
		AForm &operator=(const AForm &Aform);
		~AForm();
		std::string getName 	( void ) const;
		bool getSignedBool  	( void ) const;
		int  getGradeToSign  	( void ) const;
		int  getGradeToExecute	( void ) const;
		class GradeTooHighException:public std::exception
		{
			public:
				virtual const char *wath() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			public:
				virtual const char *wath() const throw();
		};
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator << (std::ostream &out, AForm &Aform);
#endif