/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:33:01 by minabe            #+#    #+#             */
/*   Updated: 2023/12/02 12:17:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << "\033[0;34m" << getNbAccounts() << "\033[0m" << ";"
			<< "total:" << "\033[0;34m" << getTotalAmount() << "\033[0m" << ";"
			<< "deposits:" << "\033[0;34m" << getNbDeposits() << "\033[0m" << ";"
			<< "withdrawals:" << "\033[0;34m" << getNbWithdrawals() << "\033[0m" << std::endl;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";"
			<< "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";"
			<< "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";"
			<< "p_amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "deposit:" << "\033[0;34m" << deposit << "\033[0m" << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "nb_deposits:" << "\033[0;34m" << _nbDeposits << "\033[0m" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";"
			<< "p_amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "\033[0;34m" << withdrawal << "\033[0m" << ";"
			<< "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "nb_withdrawals:" << "\033[0;34m" << _nbWithdrawals << "\033[0m" << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << "\033[0;34m" << _accountIndex << "\033[0m" << ";"
			<< "amount:" << "\033[0;34m" << _amount << "\033[0m" << ";"
			<< "deposits:" << "\033[0;34m" << _nbDeposits << "\033[0m" << ";"
			<< "withdrawals:" << "\033[0;34m" << _nbWithdrawals << "\033[0m" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		now;
	struct tm	*local;
	char		buf[20];

	std::time(&now);
	local = std::localtime(&now);
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", local);
	std::cout << buf << " ";
}
