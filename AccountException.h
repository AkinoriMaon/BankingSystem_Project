// Visual Studio 2019에서 작성된 코드입니다.

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <iostream>

class WithdrawException
{
private:
	int reqMoney;

public:
	WithdrawException(int money);
	void ShowWithdrawException() const;
};

WithdrawException::WithdrawException(int money)
	: reqMoney(money)
{}

void WithdrawException::ShowWithdrawException() const
{
	std::cout << "You can't withdraw the money much than you have it." << std::endl;
	std::cout << "Please input again." << std::endl << std::endl;
}

class DepositException
{
private:
	int reqMoney;

public:
	DepositException(int money);
	void ShowDepositException() const;
};

DepositException::DepositException(int money)
	: reqMoney(money)
{}

void DepositException::ShowDepositException() const
{
	std::cout << "You can't deposit the money that lower than 0 Won." << std::endl;
	std::cout << "Please input again." << std::endl << std::endl;
}

#endif