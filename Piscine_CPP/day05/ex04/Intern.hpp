#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
    public:
        class NotExitRequest : public std::exception {
            public:
                NotExitRequest(void);
                virtual ~NotExitRequest(void) throw();
                NotExitRequest(NotExitRequest const & rhs);
                NotExitRequest & operator=(NotExitRequest const & rhs);
                virtual const char* what() const throw();
        };
        Intern(void);
        virtual ~Intern(void);
        Intern(Intern const & rhs);
        AForm * makeForm(std::string const & request, std::string const & target);
        Intern & operator=(Intern const & rhs);
};

#endif