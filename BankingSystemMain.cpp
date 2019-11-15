// Visual Studio 2019���� �ۼ��� �ڵ��Դϴ�.

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main()
{
	AccountHandler manager;
	int choice;
	
	while (1)
	{
		manager.ShowMenu();
		std::cout << "���� : ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			std::cout << "<Program End>" << std::endl;
			return 0;
		default:
			std::cout << "Illegal selection..." << std::endl;
			break;
		}

		while (getchar() != '\n');

		std::cout << "Press Enter to next...";
		getchar();
		system("cls");
	}

	return 1;
}