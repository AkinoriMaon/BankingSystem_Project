// Visual Studio 2019에서 작성된 코드입니다.

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr; // Account 저장을 위한 배열
	int accNum; // 저장된 Account 수

public:
	AccountHandler();

	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;

	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

#endif