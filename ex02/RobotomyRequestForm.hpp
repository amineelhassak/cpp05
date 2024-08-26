# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string &);
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm &operator =(const RobotomyRequestForm &);
        ~RobotomyRequestForm();
        void excute( Bureaucrat const & ) const;
};

#endif