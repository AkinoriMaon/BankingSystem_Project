// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

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
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �Ա�" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void AccountHandler::MakeAccount()
{
	int accType;

	std::cout << "[���� ���� ����]" << std::endl;
	std::cout << "1. ���뿹�ݰ���" << std::endl;
	std::cout << "2. �ſ�ŷڰ���" << std::endl;
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

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> id;

	std::cout << "�̸� : ";
	std::cin >> name;

	std::cout << "�Աݾ� : ";
	std::cin >> money;

	std::cout << "������ : ";
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

	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
	std::cout << "����ID : ";
	std::cin >> id;

	std::cout << "�̸� : ";
	std::cin >> name;

	std::cout << "�Աݾ� : ";
	std::cin >> money;

	std::cout << "������ : ";
	std::cin >> interRate;

	std::cout << "�ſ���(1 to A, 2 to B, 3 to C) : ";
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

	std::cout << "[�Ա�]" << std::endl;

	std::cout << "����ID : ";
	std::cin >> id;

	while (1)
	{
		std::cout << "�Աݾ� : ";
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
					std::cout << "�Ա� �Ϸ�" << std::endl << std::endl;
					return;
				}
			}

			std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
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

	std::cout << "[���]" << std::endl;

	std::cout << "����ID : ";
	std::cin >> id;

	while (1)
	{
		std::cout << "��ݾ� : ";
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

					std::cout << "��� �Ϸ�" << std::endl << std::endl;
					return;
				}
			}

			std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
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