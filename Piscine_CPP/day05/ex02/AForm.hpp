#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
    private:
        std::string const _name;
        int const _gradeExe;
        int const _gradeSigned;
        bool _isSigned;
    protected:
        AForm(void);
    public:
        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException(void);
                ~GradeTooLowException(void) throw();
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
        class NotSignedException : public std::exception {
            public:
                NotSignedException(void);
                virtual ~NotSignedException(void) throw();
                NotSignedException(NotSignedException const & rhs);
                NotSignedException & operator=(NotSignedException const & rhs);
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
        virtual ~AForm(void);
        AForm(std::string name, int gradeExec, int gradeSigned);
        AForm(AForm const & rhs);
        void beSigned(Bureaucrat const & src) const;
        std::string getName(void) const;
        int getGradeExe(void) const;
        int getGradeSigned(void) const;
        bool getIsSigned(void) const;
        void signedForm(void);
        void setIsSigned(bool isSigned);
        virtual void execute(Bureaucrat const & src) const = 0;
        AForm & operator=(AForm const & rhs);

};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif