#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;
        Bureaucrat(void);
    public:
        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException(void);
                virtual ~GradeTooLowException(void) throw();
                GradeTooLowException(GradeTooLowException const & rhs);
                GradeTooLowException & operator=(GradeTooLowException const & rhs);
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                GradeTooHighException(void);
                ~GradeTooHighException(void) throw();
                GradeTooHighException(GradeTooHighException const & rhs);
                GradeTooHighException & operator=(GradeTooHighException const & rhs);
                virtual const char* what() const throw();
        };
        virtual ~Bureaucrat(void);
        Bureaucrat(std::string _name, int grade);
        Bureaucrat(Bureaucrat const & rhs);
        void signForm(AForm & src);
        std::string getName(void) const;
        int getGrade(void) const;
        void setGrade(int grade);
        void incrementGrade(void);
        void decrementGrade(void);
        void executeForm(AForm const & form);
        Bureaucrat & operator=(Bureaucrat const & rhs);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif