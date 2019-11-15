// Visual Studio 2019에서 작성된 코드입니다.

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String name)
	: accID(ID), balance(money)
{
	cusName = name;
}

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money) // 출금액 반환, 부족 시 0 반환
{
	if (balance < money)
	{
		return 0;
	}

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	std::cout << "계좌 ID : " << accID << std::endl;
	std::cout << "이름 : " << cusName << std::endl;
	std::cout << "잔액 : " << balance << std::endl;
}