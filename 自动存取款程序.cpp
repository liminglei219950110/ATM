#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"time.h"
#include"cstdio"
#include"windows.h"
#include"conio.h"


//函数声明
void main1();//初始主页
void SignUp();//注册
void SignIn();//登录
void Menu();//主菜单
void SaveMoney();//存钱业务
void SaveMoney1();//存钱选项
void WithdrawMoney();//取钱业务
void WithdrawMoney1();//取钱选项
void TransferMoney();//转账业务
void TransferMoney1();//转账选项
void Inquire();//查询业务
void InquireBalance();//查询余额
void InqInformation();//查询个人信息
void InqRecord();//查询流水记录
void ChangeInformation();//修改信息选项页
void ChangeUserName();//修改用户名称
void ChangePhone();//修改联系电话
void ChangePassword();//修改密码
void getPassword(char a[], int b);  //星号密码
void SysTime();//系统时间
void SaveUserData();//保存用户数据
void SaveTransactionData();//保存交易数据
void IniUser_Data();//初始化用户数据
void InitTraData();//初始化交易数据
void SetPassword();//设置密码
void SetPhoneNum();//设置电话号码
void SaveTransaction();//存款记录
void WithdrawTransaction();//取款记录
void TransferTransaction();//转账记录
void HandTransaction();//手续费记录
void PrintTransaction();//打印交易记录
float HandMoney;              //手续费
int QK = 0, CK = 0, ZZ = 0;


struct Account
{
	char name[100];
	char AccountNum[50];
	char PhoneNum[12];
	char password[10];
	float balance;

	struct Account* next;
};

struct Trade
{
	char TAccountNum[50];
	char Time[100];
	char Operation[100];
	float Money;

	struct Trade* Tnext;
};

typedef struct Account Account;
typedef struct Trade Trade;
Account* Pset = (Account*)malloc(sizeof(Account));
Account* head = NULL;
Account* tail = NULL;
Account* curAccount;
Account* curAccountO;
Account ZX;

Trade* THead = NULL;
Trade* TTail = NULL;
Trade* TCurAccount;
Trade TA;


int FindACC(Account IV1)//登录时查找当前账户
{
	Account* curP = head;
	Trade* TcurP = THead;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindPassword(Account IV1)//登录时查找当前账户密码
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV1.AccountNum) == 0 && strcmp(curP->password, IV1.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC2(Account IV)//查找是否被已有账户
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->AccountNum, IV.AccountNum) == 0)
		{
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

int FindACC3(Account TT)//查找转账账户
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curAccount->AccountNum, TT.AccountNum) == 0)
		{
			int a, b = 0;
			printf("\n不能给自己转账！！！\n");
			printf("\nYou can't transfer money to yourself! ! !\n");
			while (b < 3)
			{
				printf("\n\n\n\t\t1.重新输入对方账户号码/Re-enter the account number of the other party");
				printf("\n\n\n\t\t2.返回主菜单/Back to main menu/Return to the homepage");
				printf("\n\n\n\t\t0.退出系统/Exit system/Exit the system\n\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					TransferMoney();//转账业务
					b = 3;
					break;
				case 2:
					system("cls");
					Menu();//主菜单
					b = 3;
					break;
				case 0:
					b = 3;
					SaveUserData();//保存用户数据
					exit(0);
				default:
					b++;
					break;
				}
			}
		}
		else if (strcmp(curP->AccountNum, TT.AccountNum) == 0)
		{
			curAccountO = curP;//当前转账对象账户
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


int main()
{
	SysTime();//系统时间
	IniUser_Data();//初始化用户数据
	InitTraData();
	main1();
	SaveUserData();//保存用户数据
	SaveTransactionData();//保持交易数据
	return 0;
}

void main1()//初始主页
{
	printf("\n\t\t\t\t欢迎使用自动存取款机/Welcome");
	printf("\n\t\t\t\t****************************\n\n");
	printf("\n提示/tips：\n\n");
	printf("\t键入对应选项数字，按回车键确认。/Enter the option number and press Enter to confirm the option.\n\t\n");
	int a, b = 0;
	while (b != 1)
	{
		printf("\n\n\t\t\t1.用户登录/Sign in\n");
		printf("\n\n\t\t\t2.用户注册/Sign up\n");
		printf("\n\n\t\t\t0.退出/Exit\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			SignIn();//登录
			break;
		case 2:
			SignUp();//注册
			break;
		case 0:
			exit(0);
		default:
			b = 1;
			system("cls");
			printf("\n\n\t\t输入有误，请按照提示再次输入!\t\t");
			printf("Error,please follow the prompts to enter again!\n\n");
			break;
		}
	}
}

void SignIn()//登录
{
	system("cls");
	int m = 0, n = 0;
	while (m < 3)//3次输入错账号将退出系统/Exit system
	{
		Account IV1;//账户中间变量1
		printf("\n\n\n\t请输入账号/please enter account：\n");
		printf("\n\n\t\t\t_____\b\b\b\b\b");
		scanf("%s", IV1.AccountNum);
		system("cls");
		if (FindACC(IV1))
		{
			while (n < 3)//3次输入错密码将退出系统/Exit system
			{
				printf("\n\n\n\t请输入密码/Please enter password/Please enter password：\n");
				char storePassword[10] = { '\0' };    //存储用户输入的密码
				printf("\n\n\t\t\t______\b\b\b\b\b\b");
				getPassword(storePassword, 10);
				strcpy(IV1.password, storePassword);
				system("cls");
				if (FindPassword(IV1))
				{
					m = 3;
					n = 3;
					Menu();//主菜单
					break;
				}
				else
				{
					m++;
					n++;
					if (n == 3)
					{
						printf("\n\n\t该账号已经被冻结/The account has been frozen\n");
						strcpy(curAccount->password, "abc");;
						break;
					}
					else
					{
						printf("\n\n\t密码错误/Wrong password\n");
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\n\t没有查找到该用户!请重新输入/The user was not found! Please re-enter：\n");
			if (m == 3)
			{
				printf("\n\n\t错误，已退出系统/Exit system\n");
				SaveUserData();//保存用户数据
				exit(0);
			}
		}
	}
}

void Menu()//主菜单
{
	int a, b = 1;
	while (b)
	{
		b = 0;
		printf("\n\n\t\t1.存款/Deposit\n");
		printf("\n\n\t\t2.取款/Withdrawal\n");
		printf("\n\n\t\t3.转帐/Transfer\n");
		printf("\n\n\t\t4.查询/Query\n");
		printf("\n\n\t\t5.修改资料/Modify data\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			SaveMoney();//存钱业务
			break;
		case 2:
			system("cls");
			WithdrawMoney();//取钱业务
			break;
		case 3:
			system("cls");
			TransferMoney();//转账业务
			break;
		case 4:
			system("cls");
			Inquire();//查询业务
			break;
		case 5:
			system("cls");
			ChangeInformation();//修改信息选项页
			break;
		case 0:
			system("cls");
			SaveUserData();//保存用户数据
			exit(0);
			break;
		default:
			system("cls");
			printf("\n\n\t\t输入错误！/Input error!\n");
			b = 1;
			break;
		}
	}
}

void SaveTransaction()//存款记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "存款/Deposit");
		TP->Money = TA.Money;

		SaveTransactionData();//保持交易数据
	}
}

void WithdrawTransaction()//取款记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "取款/Withdraw");
		TP->Money = TA.Money;
		SaveTransactionData();//保持交易数据
	}
}

void TransferTransaction()//转账记录
{
	Trade* TP = (Trade*)malloc(sizeof(Trade));
	TP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TP;
		TTail = TP;
	}
	else
	{
		TTail->Tnext = TP;
		TTail = TP;
		strcpy(TP->TAccountNum, curAccount->AccountNum);
		strcpy(TP->Time, TA.Time);
		strcpy(TP->Operation, "转账/Transfer");
		TP->Money = TA.Money;
		SaveTransactionData();//保持交易数据
	}
	Trade* TPi = (Trade*)malloc(sizeof(Trade));
	TPi->Tnext = NULL;
	if (THead == NULL)
	{
		THead = TPi;
		TTail = TPi;
	}
	else
	{
		TTail->Tnext = TPi;
		TTail = TPi;
		strcpy(TPi->TAccountNum, curAccountO->AccountNum);
		strcpy(TPi->Time, TA.Time);
		strcpy(TPi->Operation, "收到转账/Transfer");
		TPi->Money = -TA.Money;
		SaveTransactionData();//保持交易数据
	}
}

void HandTransaction()//手续费记录
{
	Trade* HP = (Trade*)malloc(sizeof(Trade));
	HP->Tnext = NULL;
	if (THead == NULL)
	{
		THead = HP;
		TTail = HP;
	}
	else
	{
		TTail->Tnext = HP;
		TTail = HP;
		strcpy(HP->TAccountNum, curAccount->AccountNum);
		strcpy(HP->Time, TA.Time);
		strcpy(HP->Operation, "手续费/Handling fee");
		HP->Money = -HandMoney;
		SaveTransactionData();//保持交易数据
	}
}

void PrintTransaction()//打印流水
{
	int a = 0;
	Trade* HcurP = THead;
	while (HcurP != NULL)//交易记录
	{
		if (strcmp(curAccount->AccountNum, HcurP->TAccountNum) == 0)
		{
			a++;
			TCurAccount = HcurP;
			printf("\n<序号/Num:%d>\t时间/Time：%s\t交易类型/Type：%s\t金额/Quantity：%.2f\n", a, TCurAccount->Time, TCurAccount->Operation, TCurAccount->Money);
		}
		HcurP = HcurP->Tnext;
	}
	if (a == 0)
	{
		printf("\n\t暂=无=交=易=记=录\n\t\t\n\n");
		printf("\n\tNo transaction record now.\n\t\t\n\n");
	}
}

void SaveMoney()//存款
{
	int a;
	QK = 0;
	printf("\t温馨提示：单笔存款不得超过20000。\n\n");
	printf("\tHint：A single save cannot exceed 20,000.\n\n");
	printf("\n\n\n\t请输入你要存入的金额/Enter amount：\n");
	printf("\n\n\t\t\t______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a > 20000)
	{
		system("cls");
		printf("\n\t单笔存款不得超过20000。\n\tA single save cannot exceed 20,000.\n\n");
		SaveMoney1();//存钱选项
	}
	else
	{
		SysTime();//系统时间
		TA.Money = a * 1.00;
		curAccount->balance = curAccount->balance + TA.Money;
		system("cls");
		SaveUserData();//保存用户数据
		SaveTransaction();//存款记录
		printf("\n\t您本次已成功存入%.2f!!!!\n", TA.Money);
		printf("\n\tYou have successfully deposited %.2f this time!!!!\n", TA.Money);
		CK = 1;
		SaveMoney1();//存钱选项
	}
}

void SaveMoney1()//存款选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (CK)
			printf("\n\n\t\t1.再存一笔/Save another\n");
		else
			printf("\n\n\t\t1.重新输入金额/Re-enter amount\n");
		printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			SaveMoney();//存钱业务
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void WithdrawMoney()//取款
{
	int a;
	CK = 0;
	printf("\t温馨提示：单笔取款不得超过20000。\n\n");
	printf("\tHint：A single withdraw cannot exceed 20,000.\n\n");
	printf("\n\n\n\t\t请输入你要取出的金额/Enter amount：______\b\b\b\b\b\b");
	scanf("%d", &a);
	if (a > 20000)
	{
		system("cls");
		printf("\n\t单笔取款不得超过20000。\n\n");
		printf("\n\tA single withdrawal cannot exceed 20,000.\n\n");
		WithdrawMoney1();//取钱选项
	}
	else
	{
		SysTime();//系统时间
		TA.Money = a * -1.00;
		if (curAccount->balance + TA.Money < 0)
		{
			system("cls");
			printf("\n\t余额不足!!!!\n\tInsufficient balance!!!\n");
		}
		else
		{
			curAccount->balance = curAccount->balance + TA.Money;
			system("cls");
			SaveUserData();//保存用户数据
			WithdrawTransaction();//取款记录
			printf("\n\t取款成功!!!!\n\n\tWithdrawal succeeded!!!\n");
			QK = 1;
		}
		WithdrawMoney1();//取钱选项
	}
}

void WithdrawMoney1()//取款选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (QK)
			printf("\n\n\n\t\t1.再次取款/Withdraw again");
		else
			printf("\n\n\n\t\t1.重新输入金额/Re-enter amount");
		printf("\n\n\n\t\t2.返回主菜单/Back to main menu");
		printf("\n\n\n\t\t0.退出系统/Exit system");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			WithdrawMoney();//取钱业务
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void TransferMoney()//转账业务
{
	int a;
	ZZ = 0;
	printf("\t温馨提示：1.单笔取款不得超过20000。\n\n");
	printf("\t        2.转账将收取2%%的手续费。\n\t\n");
	printf("\tHint：1.A single withdraw cannot exceed 20,000.\n\n");
	printf("\t      2.Transfers will be subject to a 2% handling fee.\n\t\n");
	printf("\n\n\n\n\t\t请输入你要转出到的账户/Account：_____\b\b\b\b\b");
	Account TT;
	scanf("%s", &TT.AccountNum);
	if (FindACC3(TT))
	{
		system("cls");
		printf("\n\n\t\t请输入你要转出的金额/Money：______\b\b\b\b\b\b");
		scanf("%d", &a);
		if (a > 20000)
		{
			printf("\n\t单笔转账不得超过20000。\n\tTransfers will be subject to a 2% handling fee.\n\n");
			TransferMoney1();//转账选项
		}
		else
		{
			SysTime();//系统时间
			TA.Money = a * -1.00;
			HandMoney = 0.02 * a;
			if (curAccount->balance + TA.Money - HandMoney < 0)
			{
				system("cls");
				printf("\n\t余额不足!!!!\n\tInsufficient balance!!!\n");
			}
			else
			{
				system("cls");
				curAccount->balance = curAccount->balance + TA.Money - HandMoney;
				curAccountO->balance = curAccountO->balance - TA.Money;
				TransferTransaction();//转账记录
				HandTransaction();//手续费记录
				SaveUserData();//保存用户数据
				printf("\n\t转账成功!!!!\n\n\tSucceeded!!!\n");
				ZZ = 1;
			}
			TransferMoney1();//转账选项
		}
	}
	else
	{
		system("cls");
		printf("\n\t对方账户不存在！！！！\n\tThe account of the other party does not exist! ! ! !");
		TransferMoney1();//转账选项
	}

}

void TransferMoney1()//转账选项
{
	int k = 0, b;
	while (k < 3)
	{
		if (ZZ)
			printf("\n\n\n\t\t1.再次转账/Transfer again");
		else
			printf("\n\n\n\t\t1.重新转账/Retransfer");
		printf("\n\n\n\t\t2.返回主菜单/Back to main menu");
		printf("\n\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &b);
		switch (b)
		{
		case 1:
			system("cls");
			TransferMoney();//转账业务
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void Inquire()//查询业务
{

	int a, b = 0;
	while (b < 3)
	{
		printf("\n\n\t\t1.查询余额/Check balances\n");
		printf("\n\n\t\t2.查询交易记录/Query transaction records\n");
		printf("\n\n\t\t3.查询个人信息/Inquire about personal information\n");
		printf("\n\n\t\t4.返回主菜单/Back to main menu\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			InquireBalance();//查询余额
			b = 3;
			break;
		case 2:
			system("cls");
			InqInformation();//查询个人信息
			b = 3;
			break;
		case 3:
			system("cls");
			InqRecord();//查询流水记录
			b = 3;
			break;
		case 4:
			system("cls");
			Menu();//主菜单
			b = 3;
			break;
		case 0:
			system("cls");
			b = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InquireBalance()//查询余额
{
	SysTime();//系统时间
	printf("\n\t您的余额为/Your balance is：\n\t\t%.2f\n", curAccount->balance);
	int a, b = 0;
	while (b < 3)
	{
		printf("\n\n\t\t1.返回上一页/Go back to the last page\n");
		printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();//查询业务
			b = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			b = 3;
			break;
		case 0:
			b = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			b++;
			break;
		}
	}
}

void InqInformation()//查询个人信息
{
	printf("\n\t姓名/Name：\n\t\t%s\n", curAccount->name);
	printf("\n\t账号/Account number：\n\t\t%s\n", curAccount->AccountNum);
	printf("\n\t预留手机号/phone number：\n\t\t%s\n\n", curAccount->PhoneNum);
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t\t1.返回上一页/Go back to the last page\n");
		printf("\n\n\t\t\t2.返回主菜单/Back to main menu\n");
		printf("\n\n\t\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();//查询业务
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void InqRecord()//查询交易记录
{
	PrintTransaction();//打印交易记录
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\n\t\t1.返回上一页/Go back to the last page\n");
		printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			Inquire();//查询业务
			k = 3;
			break;
		case 2:
			system("cls");
			Menu();//主菜单
			k = 3;
			break;
		case 0:
			k = 3;
			SaveUserData();//保存用户数据
			exit(0);
		default:
			k++;
			break;
		}
	}
}

void ChangeInformation()//修改信息选项页
{
	system("cls");
	int a, b = 1;
	while (b)
	{
		printf("\n\n\t\t1.修改用户/Modify user\n");
		printf("\n\n\t\t2.修改电话/Modify the phone\n");
		printf("\n\n\t\t3.修改密码/Change password\n");
		printf("\n\n\t\t4.返回上一页/Go back to the last page\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ChangeUserName();//修改用户名称
			b = 0;
			break;
		case 2:
			ChangePhone();//修改联系电话
			b = 0;
			break;
		case 3:
			ChangePassword();//修改密码
			b = 0;
			break;
		case 4:
			Menu();//主菜单
			b = 0;
			break;
		case 0:
			SaveUserData();//保存用户数据
			exit(0);
		default:
			system("cls");
			printf("输入错误！\t请按照提示重新输入/Input error! \tPlease re-enter as prompted：\n");
			break;
		}
	}
}

void ChangeUserName()//修改用户名称
{
	int a, b = 0, c = 0;
	while (b < 3)
	{
		system("cls");
		printf("\n\n\t请输入新用户名称:___\b\b\b");
		scanf("%s", curAccount->name);
		system("cls");
		printf("\n\n\t用户名称修改成功！\n");
		SaveUserData();//保存用户数据
		b = 3;
		while (c < 3)
		{
			printf("\n\n\t\t1.返回上一页/Go back to the last page\n");
			printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
			printf("\n\n\t\t0.退出系统/Exit system\n");
			printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();//修改信息选项页
				b = 3;
				break;
			case 2:
				system("cls");
				Menu();//主菜单
				b = 3;
				break;
			case 0:
				b = 3;
				SaveUserData();//保存用户数据
				exit(0);
			default:
				b++;
				break;
			}
		}
	}
}

void ChangePhone()//修改联系电话
{
	system("cls");
	int a, b = 0, c = 0;
	while (b < 3)
	{
		printf("\n\n\t请输入新联系电话号码/Please enter a new contact phone number:______\b\b\b\b\b\b");
		scanf("%s", curAccount->PhoneNum);
		system("cls");
		printf("\n\n\t联系电话修改成功！/Successfully modified!\n");
		SaveUserData();//保存用户数据
		b = 3;
		while (c < 3)
		{
			printf("\n\n\t\t1.返回上一页/Go back to the last page\n");
			printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
			printf("\n\n\t\t0.退出系统/Exit system\n");
			printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				system("cls");
				ChangeInformation();//修改信息选项页
				c = 3;
				break;
			case 2:
				system("cls");
				Menu();//主菜单
				c = 3;
				break;
			case 0:
				c = 3;
				SaveUserData();//保存用户数据
				exit(0);
			default:
				c++;
				break;
			}
		}
	}
}

void ChangePassword()//修改密码
{
	system("cls");
	int a, b = 0, c = 0;
	char Password[100];
	while (b < 3)
	{
		printf("\n\n\n\t请输入原始密码/Please enter password：______\b\b\b\b\b\b");
		char storePassword[10] = { '\0' };
		getPassword(storePassword, 10);
		strcpy(Password, storePassword);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("\n\n\t请输入新密码/Please enter new password:______\b\b\b\b\b\b");
			getPassword(storePassword, 10);
			strcpy(curAccount->password, storePassword);
			system("cls");
			printf("\n\n\t用户密码修改成功！/Successfully modified!\n");
			SaveUserData();//保存用户数据
			b = 3;
			while (c < 3)
			{
				printf("\n\n\t\t1.返回上一页/Go back to the last page\n");
				printf("\n\n\t\t2.返回主菜单/Back to main menu\n");
				printf("\n\n\t\t0.退出系统/Exit system\n");
				printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					system("cls");
					ChangeInformation();//修改信息选项页
					c = 3;
					break;
				case 2:
					system("cls");
					Menu();//主菜单
					c = 3;
					break;
				case 0:
					c = 3;
					SaveUserData();//保存用户数据
					exit(0);
				default:
					c++;
					break;
				}
			}
		}
		else
		{
			b++;
			system("cls");
			printf("\n\n\t密码输入错误!/wrong password!\n");
		}
	}
}

void getPassword(char* storePw, int maxPwLen)//密码输入
{
	char c = '\0';
	char* pc = storePw;
	int pwlen = 0;

	while (1)
	{
		c = getch();
		if (c == '\r')
			break;
		if (pwlen >= 0 && pwlen < maxPwLen - 1 && c)
		{
			*pc = c;
			pc++;
			pwlen++;
			putchar('*');
		}
	}
}

void SysTime()//系统时间
{
	time_t t = time(0);
	char tmp[20];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d/%X", localtime(&t));
	strcpy(TA.Time, tmp);
}

void SaveUserData()//保存用户数据
{
	FILE* fp = fopen("D:/用户信息.txt", "w");//保存用户数据
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%f\n", curP->AccountNum, curP->name, curP->PhoneNum, curP->password, curP->balance);
			curP = curP->next;
		}
		fclose(fp);
	}
}

void SaveTransactionData()//保存交易数据
{
	FILE* Tfp = fopen("D:/交易信息.txt", "at+");//保存交易数据
	if (Tfp != NULL)
	{
		Trade* TcurP = THead;
		while (TcurP != NULL)
		{
			if (TcurP->Tnext == NULL)
			{
				fprintf(Tfp, "%s\t%s\t%s\t%f\n", TcurP->TAccountNum, TcurP->Time, TcurP->Operation, TcurP->Money);
			}
			TcurP = TcurP->Tnext;
		}
		fclose(Tfp);
	}
}

void IniUser_Data()////初始化用户数据
{
	FILE* fp = fopen("D:/用户信息.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\t%f\n", newNodeP->AccountNum, newNodeP->name, newNodeP->PhoneNum, newNodeP->password, &newNodeP->balance);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

void InitTraData()//初始化交易信息
{
	FILE* Tfp = fopen("D:/交易信息.txt", "r");
	if (Tfp != NULL)
	{
		while (!feof(Tfp))
		{
			Trade* TnewNodeP = (Trade*)malloc(sizeof(Trade));
			fscanf(Tfp, "%s\t%s\t%s\t%f\n", TnewNodeP->TAccountNum, TnewNodeP->Time, TnewNodeP->Operation, &TnewNodeP->Money);
			TnewNodeP->Tnext = NULL;

			if (THead == NULL)
			{
				THead = TnewNodeP;
				TTail = TnewNodeP;
			}
			else
			{
				TTail->Tnext = TnewNodeP;
				TTail = TnewNodeP;
			}
		}
		fclose(Tfp);
	}
}

void SignUp()//注册
{
	int a, k = 0;
	system("cls");
	Pset->next = NULL;//Account* Pset = (Account*)malloc(sizeof(Account));//已定义
	if (head == NULL)
	{
		head = Pset;
		tail = Pset;//如果这是第一个创建的结点，则将头 尾指针指向这个结点
	}
	else
		tail->next = Pset; //如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
	printf("\n\t请输入你的姓名/Please enter your name：\n");
	scanf("%s", ZX.name);
	strcpy(Pset->name, ZX.name);
	int ACCountNum = 10000;
	itoa(ACCountNum, ZX.AccountNum, 10);
	while (FindACC2(ZX))
	{
		ACCountNum++;
		itoa(ACCountNum, ZX.AccountNum, 10);
		break;
	}
	strcpy(Pset->AccountNum, ZX.AccountNum);
	SetPhoneNum();//设置电话号码
	SetPassword();//设置密码
	Pset->balance = 0;
	SaveUserData();//保存用户数据
	while (k < 3)
	{
		system("cls");
		printf("\n\t\t注=册=成=功/Success!\n");
		printf("\n\t你的账户号码为 %s\n", Pset->AccountNum);
		printf("\n\tUser number %s\n", Pset->AccountNum);
		printf("\n\n\t\t1.返回登录/Back to login\n");
		printf("\n\n\t\t0.退出系统/Exit system\n");
		printf("\n\n\t\t\t请输入/Your choice：___\b\b\b");
		scanf("%d", &a);
		if (a == 1)
		{
			system("cls");
			SignIn();//登录
			break;
		}
		else if (a == 0)
		{
			exit(0);
		}
		else
		{
			k++;
			printf("\n密码输入错误!/Incorrect password! \n");
		}
	}
}

void SetPassword()//设置密码
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("\n\t请设置你的账户密码【6位】/Please set your account password [6 digits]：\n");
		char storePassword[10] = { '\0' };    //存储用户输入的密码
		printf("\n\n\t\t\t______\b\b\b\b\b\b");
		getPassword(storePassword, 10);
		strcpy(ZX.password, storePassword);
		if (strlen(ZX.password) == 6)
		{
			strcpy(Pset->password, ZX.password);
			break;
		}
		else
		{
			printf("\n\t\t密码为六位，你的密码设置有误！/The password is six digits, your password is set incorrectly！\n\n\t请重新设置/Please reset it：\n");
		}
	}
}

void SetPhoneNum()//设置电话号码
{
	int a = 0;
	while (a < 3)
	{
		a++;
		printf("\n\t请输入你的电话号码【11位】/Please enter your phone number [11 digits]：\n");
		scanf("%s", ZX.PhoneNum);
		if (strlen(ZX.PhoneNum) == 11)
		{
			strcpy(Pset->PhoneNum, ZX.PhoneNum);
			break;
		}
		else
		{
			system("cls");
			printf("\n\t\t你的预留号码设置有误！/Your reserved number is set incorrectly!\n\n\t请重新输入/Please reset it：\n");
		}
	}
}
