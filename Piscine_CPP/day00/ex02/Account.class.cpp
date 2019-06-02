#include "Account.class.hpp"
#include <iostream>
#include <cstdio>
#include <ctime>

Account::Account() {
    return ;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    Account::_displayTimestamp();
    this->_accountIndex = getNbAccounts();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    return ;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
    return ;
}

void Account::_displayTimestamp(void) {
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    std::cout << "[" << buffer << "] ";
}

int	Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}
int	Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:"<< Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:"<< this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";
    if (this->_amount < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";";
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:"<< this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

void Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:"<< this->_nbWithdrawals << std::endl;
}

int             Account::_nbAccounts = 0;
int             Account::_totalAmount = 0;
int             Account::_totalNbDeposits = 0;
int             Account::_totalNbWithdrawals = 0;