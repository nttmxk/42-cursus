#include "Account.hpp"
#include <ctime>
#include <iostream>

using namespace std; ////////////NO

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
	cout << \
	"index:" << _accountIndex << \
	";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	cout << \
	"index:" << _accountIndex << \
	";amount:" << _amount << ";closed\n";
}

void Account::_displayTimestamp()
{
	time_t	t;
	char 	buf[16];

	time(&t);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&t));
	cout << '[' << buf << "] ";
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << \
	"index:" << _accountIndex << \
	";p_amount:" << _amount << \
	";deposit:" << deposit << \
	";amount:" << _amount + deposit << \
	";nb_deposits:" << _nbDeposits << '\n';
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount() const
{

}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << \
	"index:" << _accountIndex << \
	";amount:" << _amount << \
	";deposits:" << _nbDeposits << \
	";withdrawals:" << _nbWithdrawals << '\n';
}