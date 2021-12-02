#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int MAX = 26;



struct AcountBank
{
	int Key;
	char Nameofperson[80];
	char lastname[80];
	int balance;
	int saveingmis;
	int savemoney;
	struct AcountBank *pNext;
};


struct AcountBank* add(struct AcountBank* pNext, int key, char *name, char *lastname)
{
	struct AcountBank* pNewNode = (struct AcountBank*)malloc(sizeof(struct AcountBank));
	int month, day, year, hour, min;
	FILE *f = fopen("Actions.txt", "a+");
	if (pNewNode)
	{
		pNewNode->Key = key;
		pNewNode->saveingmis = 0;
		pNewNode->savemoney = 0;
		pNewNode->balance = 0;
		strcpy(pNewNode->Nameofperson, name);
		strcpy(pNewNode->lastname, lastname);
		pNewNode->pNext = pNext;
	}
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;
	fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	fprintf(f, "New Acount Key: %d - Name of Person: %s - Last Name of Person: %s  - The amount of money: %d ILS\n", pNewNode->Key, pNewNode->Nameofperson, pNewNode->lastname, pNewNode->balance);
	fclose(f);

	printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	printf("New Acount Key: %d - Name of Person: %s - Last Name of Person: %s  - The amount of money: %d ILS\n", pNewNode->Key, pNewNode->Nameofperson, pNewNode->lastname, pNewNode->balance);

	return pNewNode;
}

struct AcountBank* Remove(struct AcountBank* pHead, int key)
{
	FILE *f = fopen("Actions.txt", "a+");
	struct AcountBank* premove = pHead;
	struct AcountBank* ptemp = NULL;

	int month, day, year, hour, min;
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;

	if (premove == pHead && premove->Key == key)
	{
		pHead = premove->pNext;
		fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		fprintf(f, "remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s  - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
		printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		printf("remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s  - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
		free(premove);
		return pHead;
	}

	while (premove != NULL)
	{
		if (premove->Key == key)
		{
			ptemp->pNext = premove->pNext;
			fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
			fprintf(f, "remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s  - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
			printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
			printf("remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
			free(premove);
			return pHead;
		}
		ptemp = premove;
		premove = premove->pNext;
	}

	if (premove == NULL)
	{
		ptemp->pNext = NULL;
		fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		fprintf(f, "remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
		printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		printf("remove Acount Key: %d - Name of Person: %s - Last Name of Person: %s - The amount of money: %d ILS\n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance);
		free(premove);

		return pHead;
	}
	return pHead;
}

struct AcountBank* find(struct AcountBank* pHead, int key)
{
	while (pHead != NULL)
	{
		if (pHead->Key == key)
		{
			return pHead;
		}
		pHead = pHead->pNext;
	}

	return 0;
}

void show(struct AcountBank* pHead)
{
	while (pHead != NULL)
	{
		printf("%d : %s : %s : %d ILS : %d : %d-> \n", pHead->Key, pHead->Nameofperson, pHead->lastname, pHead->balance, pHead->saveingmis, pHead->savemoney);
		pHead = pHead->pNext;
	}
}

void addMoneytoAcount(struct AcountBank* pHead, int money)
{
	int month, day, year, hour, min;
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;
	FILE *f = fopen("Actions.txt", "a+");
	pHead->balance += money;
	fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	fprintf(f, "This account number has deposited money :%d - The amount of money: %d ILS - your balance:%d ILS\n", pHead->Key, money, pHead->balance);
	printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	printf("This account number has deposited money :%d - The amount of money: %d ILS - your balance:%d ILS\n", pHead->Key, money, pHead->balance);
	fclose(f);
}

void withrawal(struct AcountBank* pHead, int money)
{
	int month, day, year, hour, min;
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;
	FILE *f = fopen("Actions.txt", "a+");
	pHead->balance -= money;
	fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	fprintf(f, "This acount withrawal money :%d - The amount of money: %d ILS - your balance:%d ILS\n", pHead->Key, money, pHead->balance);
	printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	printf("This account number has deposited money :%d - The amount of money: %d ILS - your balance:%d ILS\n", pHead->Key, money, pHead->balance);
	fclose(f);
}

void transfer(struct AcountBank* pHead, int money, struct AcountBank* pHeadtomove)
{
	int month, day, year, hour, min;
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;
	FILE *f = fopen("Actions.txt", "a+");
	pHead->balance -= money;
	pHeadtomove->balance += money;
	fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	fprintf(f, "This acount:%d move money to this acount:%d - the amount is: %d ILS\n", pHead->Key, pHeadtomove->Key, money);
	printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
	printf("This acount:%d move money to this acount:%d - the amount is: %d ILS\n", pHead->Key, pHeadtomove->Key, money);
	fclose(f);
}

void BankSavings(struct AcountBank* pHead, int money)
{
	int month, day, year, hour, min;
	day = (rand() % (31 - 1 + 1)) + 1;
	month = (rand() % (12 - 1 + 1)) + 1;
	year = (rand() % (2020 - 2000 + 1)) + 2000;
	hour = (rand() % (24 - 1 + 1)) + 1;
	min = (rand() % (60 - 1 + 1)) + 1;
	FILE *f = fopen("Actions.txt", "a+");
	int saving;
	printf("Select a savings plan:1-A saving that gives you 200 shekels a gift and closes for a year 2-A savings that brings you 400 shekels gift and closes for two years:\n");
	scanf("%d", &saving);
	if (saving == 1)
	{
		pHead->saveingmis = 1;
		pHead->savemoney = money + 200;
		pHead->balance -= money;
		fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		fprintf(f, "This account has selected a savings plan :%d - Program number: %d - The amount of money:%d ILS", pHead->Key, pHead->saveingmis, pHead->savemoney);
		fclose(f);
		printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		printf("This account has selected a savings plan :%d - Program number: %d - The amount of money:%d ILS", pHead->Key, pHead->saveingmis, pHead->savemoney);
	}

	else if (saving == 2)
	{
		pHead->saveingmis = 2;
		pHead->savemoney = money + 400;
		pHead->balance -= money;
		fprintf(f, "%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		fprintf(f, "This account has selected a savings plan :%d - Program number: %d - The amount of money:%d ILS", pHead->Key, pHead->saveingmis, pHead->savemoney);
		fclose(f);
		printf("%d/%d/%d %02d:%02d\n", day, month, year, hour, min);
		printf("This account has selected a savings plan :%d - Program number: %d - The amount of money:%d ILS", pHead->Key, pHead->saveingmis, pHead->savemoney);
	}


}


void Actions()
{
	FILE *f = fopen("Actions.txt", "r");

}


char *lastname(char *lastname)
{
	char namofcust[10][10] = {
					 "Hirihito",
					 "Williams",
					 "Robertson",
					 "Davenport",
					 "Gonzalez",
					 "Lavi",
					 "Cohen",
					 "Israel",
					 "Levinson",
					 "Shlev",
	};
	int i, j = 0, t = 0;
	i = rand() % 10;
	while (namofcust[i][j] != '\0')
	{
		lastname[t] = namofcust[i][j];
		j++;
		t++;
	}
	lastname[t++] = '\0';



	return lastname;
}


char *name(char *name)
{
	char namofcust[10][10] = {
					 "Dora",
					 "Tom",
					 "Jerry",
					 "David",
					 "Ben",
					 "Liad",
					 "Stav",
					 "Liraz",
					 "Din",
					 "Lior",
	};
	int i, j = 0, t = 0;
	i = rand() % 10;
	while (namofcust[i][j] != '\0')
	{
		name[t] = namofcust[i][j];
		j++;
		t++;
	}
	name[t++] = '\0';



	return name;
}

int main()
{
	int key = 12435;
	struct AcountBank* pHead = NULL;
	struct AcountBank* pHeadmnoney = NULL;
	struct AcountBank* pHeadmovemnoney = NULL;
	int choice = 0, i;
	int keyAcount;
	int money, yourkey, yourfriendkey;
	char name1[10] = "";
	char lastname1[10] = "";

	while (choice != 8)
	{
		system("color 70");
		printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t1.Create new account\n\t\t2.Removing existing account\n\t\t3.Deposit money\n\t\t4.Withdraw money\n\t\t5.Transfer funds from account to account\n\t\t6.View customer's list\n\t\t7.Savings plan\n\t\t8.exit\n\n\n\n\n\t\t Enter your choice:");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			for (i = 0; i < 1000; i++)
			{
				pHead = add(pHead, rand(key), name(name1), lastname(lastname1));
			}
			break;
		case 2:
			printf("Enter your Key Acount:");
			scanf("%d", &keyAcount);
			Remove(pHead, keyAcount);
			break;
		case 3:
			printf("Write the Acount KEY you want to add money:");
			scanf("%d", &yourkey);
			pHeadmnoney = find(pHead, yourkey);
			money = (rand() % (10000 - 1 + 1)) + 1;
			addMoneytoAcount(pHeadmnoney, money);
			break;
		case 4:
			printf("Write the Acount KEY you want to add money:");
			scanf("%d", &yourkey);
			money = (rand() % (10000 - 1 + 1)) + 1;
			pHeadmnoney = find(pHead, yourkey);
			withrawal(pHeadmnoney, money);
			break;
		case 5:
			printf("Write the bank account from which you want to transfer funds:");
			scanf("%d", &yourkey);
			pHeadmnoney = find(pHead, yourkey);
			printf("Write the account to which you want to transfer the funds:");
			scanf("%d", &yourfriendkey);
			pHeadmovemnoney = find(pHead, yourfriendkey);
			printf("Write down the amount you want to transfer:");
			scanf("%d", &money);
			transfer(pHeadmnoney, money, pHeadmovemnoney);
			break;
		case 6:
			show(pHead);
			Actions();
			break;
		case 7:
			printf("Write the account number to which you want to add savings:");
			scanf("%d", &yourkey);
			pHeadmnoney = find(pHead, yourkey);
			printf("Write down the amount you want to deposit for savings:");
			scanf("%d", &money);
			BankSavings(pHeadmnoney, money);
			break;
		case 8:
			choice = 8;
			break;

		}

	}



	return 0;


}
