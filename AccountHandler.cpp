// Visual Studio 2019에서 작성된 코드입니다.

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "AccountException.h"

AccountHandler::AccountHandler()
	: accNum(0)
{}

void AccountHandler::ShowMenu() const
{
	std::cout << "----- Menu -----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void AccountHandler::MakeAccount()
{
	int accType;

	std::cout << "[계좌 종류 선택]" << std::endl;
	std::cout << "1. 보통예금계좌" << std::endl;
	std::cout << "2. 신용신뢰계좌" << std::endl;
	std::cin >> accType;
	std::cout << std::endl;

	if (accType == NORMAL)
	{
		MakeNormalAccount();
	}
	else
	{
		MakeCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	String name; // char* name[NAME_LEN];
	int money;
	int interRate;

	std::cout << "[보통예금계좌 개설]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> id;

	std::cout << "이름 : ";
	std::cin >> name;

	std::cout << "입금액 : ";
	std::cin >> money;

	std::cout << "이자율 : ";
	std::cin >> interRate;
	
	accArr[accNum++] = new NormalAccount(id, money, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id;
	int money;
	String name;
	int interRate;
	int creditRate;

	std::cout << "[신용신뢰계좌 개설]" << std::endl;
	std::cout << "계좌ID : ";
	std::cin >> id;

	std::cout << "이름 : ";
	std::cin >> name;

	std::cout << "입금액 : ";
	std::cin >> money;

	std::cout << "이자율 : ";
	std::cin >> interRate;

	std::cout << "신용등급(1 to A, 2 to B, 3 to C) : ";
	std::cin >> creditRate;

	switch (creditRate)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, money, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, money, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, money, name, interRate, LEVEL_C);
		break;
	default:
		std::cout << "Your input was wrong! There's no credit rate what you inputed." << std::endl;
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;

	std::cout << "[입금]" << std::endl;

	std::cout << "계좌ID : ";
	std::cin >> id;

	while (1)
	{
		std::cout << "입금액 : ";
		try
		{
			std::cin >> money;

			if (money < 0)
				throw DepositException(money);

			std::cout << std::endl;

			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					accArr[i]->Deposit(money);
					std::cout << "입금 완료" << std::endl << std::endl;
					return;
				}
			}

			std::cout << "유효하지 않은 ID입니다." << std::endl << std::endl;
			return;
		}
		catch (DepositException & ref)
		{
			ref.ShowDepositException();
		}
	}
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;

	std::cout << "[출금]" << std::endl;

	std::cout << "계좌ID : ";
	std::cin >> id;

	while (1)
	{
		std::cout << "출금액 : ";
		std::cin >> money;
		std::cout << std::endl;

		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					if (!(accArr[i]->Withdraw(money)))
					{
						throw WithdrawException(money);
					}

					std::cout << "출금 완료" << std::endl << std::endl;
					return;
				}
			}

			std::cout << "유효하지 않은 ID입니다." << std::endl << std::endl;
			return;
		}
		catch (WithdrawException & ref)
		{
			ref.ShowWithdrawException();
		}
	}
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		std::cout << std::endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}