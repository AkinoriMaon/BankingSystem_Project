// Visual Studio 2019에서 작성된 코드입니다.

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
	int accID;
	int balance;
	String cusName; // char* cusName;

public:
	Account(int ID, int money, String name);

	int GetAccID() const; // 계좌ID 반환
	virtual void Deposit(int money); // 입금
	int Withdraw(int money); // 출금
	void ShowAccInfo() const; // 고객 정보 출력
};

#endif