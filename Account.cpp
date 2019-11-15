// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

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

int Account::Withdraw(int money) // ��ݾ� ��ȯ, ���� �� 0 ��ȯ
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
	std::cout << "���� ID : " << accID << std::endl;
	std::cout << "�̸� : " << cusName << std::endl;
	std::cout << "�ܾ� : " << balance << std::endl;
}