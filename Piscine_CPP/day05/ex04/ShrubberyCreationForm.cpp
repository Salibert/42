#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(NULL, NULL, 0, 0) { return; }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { return; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int gradeExec, int gradeSigned) :
    AForm("shrubbery request", name, gradeExec, gradeSigned) { return ;}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) :
    AForm("shrubbery request", name, 137, 145) { return ;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) {
    *this = rhs;
    return;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExe())
        throw AForm::GradeTooLowException();
    std::ofstream ofs(this->getName() + "_Shrubbery");
    ofs <<
    "             _{\\ _{\\{\\/}/}/}__" << std::endl <<
    "            {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl <<
    "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl <<
    "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl <<
    "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl <<
    "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl <<
    "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl <<
    "     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl <<
    "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl <<
    "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl <<
    "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl <<
    "     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl <<
    "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl <<
    "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl <<
    "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl <<
    "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl <<
    "            {/{\\{\\{\\/}/}{\\{\\ \\}/}" << std::endl <<
    "             {){/ {\\/}{\\/} \\}\\}" << std::endl <<
    "              (_) \\.-'.-/" << std::endl <<
    "          __...---|'-.-'| --...__" << std::endl <<
    "   _...--\"   .-' |'-.-'|  ' -.  \"\"--..__" << std::endl <<
    "-\"    ' .  . '   |.'-._| '  . .  '   seb" << std::endl <<
    ".  '-  '    .--'  | '-.'|    .  '  . '" << std::endl <<
    "         ' ..     |'-_.-|" << std::endl <<
    " .  '  .       _.-|-._ -|-._  .  '  ." << std::endl <<
    "             .'   |'- .-|   '." << std::endl <<
    " ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl <<
    "  .-' '        '-._______.-'     '  ." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
    if (this != &rhs) {
        this->setIsSigned(rhs.getIsSigned());
    }
    return *this;
}