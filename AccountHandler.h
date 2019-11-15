// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr; // Account ������ ���� �迭
	int accNum; // ����� Account ��

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