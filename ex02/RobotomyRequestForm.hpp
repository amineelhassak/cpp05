# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &);
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm &operator =(const RobotomyRequestForm &);
        void excute( Bureaucrat const & ) const;
        ~RobotomyRequestForm();
};

#endif

