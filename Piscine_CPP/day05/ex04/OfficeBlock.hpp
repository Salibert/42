#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock {
    public:
        class SignerEmpty : public std::exception {
            public:
                SignerEmpty(void);
                virtual ~SignerEmpty(void) throw();
                SignerEmpty(SignerEmpty const & rhs);
                SignerEmpty & operator=(SignerEmpty const & rhs);
                virtual const char* what() const throw();
        };
        class ExecutorEmpty : public std::exception {
            public:
                ExecutorEmpty(void);
                virtual ~ExecutorEmpty(void) throw();
                ExecutorEmpty(ExecutorEmpty const & rhs);
                ExecutorEmpty & operator=(ExecutorEmpty const & rhs);
                virtual const char* what() const throw();
        };
        class InternEmpty : public std::exception {
            public:
                InternEmpty(void);
                virtual ~InternEmpty(void) throw();
                InternEmpty(InternEmpty const & rhs);
                InternEmpty & operator=(InternEmpty const & rhs);
                virtual const char* what() const throw();
        };
        OfficeBlock(void);
        OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor);
        virtual ~OfficeBlock(void);

        Intern* getIntern(void) const;
        Bureaucrat* getSigner(void) const;
        Bureaucrat* getExecutor(void) const;

        void setIntern(Intern & rhs);
        void setSigner(Bureaucrat & rhs);
        void setExecutor(Bureaucrat & rhs);

        void doBureaucracy(std::string const form, std::string const target);
    private:
        Intern * _intern;
        Bureaucrat * _signer;
        Bureaucrat * _executor;

        OfficeBlock & operator=(OfficeBlock const & rhs);
        OfficeBlock(OfficeBlock const & rhs);
};

#endif