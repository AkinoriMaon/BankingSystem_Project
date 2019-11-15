// Visual Studio 2019에서 작성된 코드입니다.

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
		NormalAccount::Deposit(money); // 원금과 이자 추가
		Account::Deposit(money * (creditRate / 100.0)); // 추가 이율 추가
	}
};

#endif