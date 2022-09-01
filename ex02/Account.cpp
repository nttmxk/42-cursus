#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << \
    "accounts:" << getNbAccounts() << \
    ";total:" << getTotalAmount() << \
    ";deposits:" << getNbDeposits() << \
    ";withdrawals:" << getNbWithdrawals() << '\n';
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << \
    "index:" << _accountIndex << \
    ";amount:" << checkAmount() << ";created\n";
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << \
    "index:" << _accountIndex << \
    ";amount:" << checkAmount() << ";closed\n";
}

void Account::_displayTimestamp()
{
	time_t t;
	char buf[16];

	time(&t);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&t));
	std::cout << '[' << buf << "] ";
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << \
    "index:" << _accountIndex << \
    ";p_amount:" << checkAmount() << \
    ";deposit:" << deposit << \
    ";amount:" << checkAmount() + deposit << \
    ";nb_deposits:" << _nbDeposits << '\n';
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (checkAmount() < withdrawal)
	{
		std::cout << \
    	"index:" << _accountIndex << \
    	";p_amount:" << checkAmount() << \
    	";withdrawal:refused\n";
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << \
    "index:" << _accountIndex << \
    ";p_amount:" << checkAmount() << \
    ";withdrawal:" << withdrawal << \
    ";amount:" << checkAmount() - withdrawal << \
    ";nb_withdrawals:" << _nbWithdrawals << '\n';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << \
    "index:" << _accountIndex << \
    ";amount:" << checkAmount() << \
    ";deposits:" << _nbDeposits << \
    ";withdrawals:" << _nbWithdrawals << '\n';
}