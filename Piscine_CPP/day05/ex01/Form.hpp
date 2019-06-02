#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
        std::string const _name;
        int const _gradeExe;
        int const _gradeSigned;
        bool _isSigned;
        Form(void);
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
                virtual ~GradeTooHighException(void) throw();
                GradeTooHighException(GradeTooHighException const & rhs);
                GradeTooHighException & operator=(GradeTooHighException const & rhs);
                virtual const char* what() const throw();
        };
        class AlreadySigned : public std::exception {
            public:
                AlreadySigned(void);
                virtual ~AlreadySigned(void) throw();
                AlreadySigned(AlreadySigned const & rhs);
                AlreadySigned & operator=(AlreadySigned const & rhs);
                virtual const char* what() const throw();
        };
        virtual ~Form(void);
        Form(std::string name, int gradeExec, int gradeSigned);
        Form(Form const & rhs);
        void beSigned(Bureaucrat const & src) const;
        std::string getName(void) const;
        int getGradeExe(void) const;
        int getGradeSigned(void) const;
        bool getIsSigned(void) const;
        void signedForm(void);
        Form & operator=(Form const & rhs);

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif