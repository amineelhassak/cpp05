# ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string &);
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm &operator =(const PresidentialPardonForm &);
        ~PresidentialPardonForm();
        void excute( Bureaucrat const & ) const;
};

#endif