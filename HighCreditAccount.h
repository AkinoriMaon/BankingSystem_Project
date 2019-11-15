// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
	int creditRate;

public:
	HighCreditAccount(int ID, int money, String name, int inter, int credit)
		: NormalAccount(ID, money, name, inter), creditRate(credit)
	{}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // ���ݰ� ���� �߰�
		Account::Deposit(money * (creditRate / 100.0)); // �߰� ���� �߰�
	}
};

#endif