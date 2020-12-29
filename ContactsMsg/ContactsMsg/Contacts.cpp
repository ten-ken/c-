#include <iostream>
#include "MenuCommand.h";

using namespace std;

const int MAX = 2000;//通讯录最多2千人

/// <summary>
/// 人员结构体
/// </summary>
struct Peopel
{
	string name;
	int sex;//性别
	int  age;
	string address;
	string telPhone;
};
/// <summary>
/// 通讯录结构体
/// </summary>
struct AddressBook
{
	//通讯录中的人员列表
	struct Peopel  peopels[MAX];

	//通讯录中的人员个数
	int peopelCount;
};


int main();

//必须定义在main方法前面  否则编译通过 运行报错
void addPeopel(struct AddressBook* addressBook);
void deletePeopel(struct AddressBook* addressBook);
void updatePeopel(struct AddressBook* addressBook);
void selectPeopel(struct AddressBook* addressBook);
void setDefaultAddressBook(struct AddressBook* addressBook);

int main(){
	AddressBook abs;
	int selectCount = 0;
	abs.peopelCount = 0;

	int num;
	showMenu();//菜单展示
	setDefaultAddressBook(&abs);//默认通讯录
	while (true) {
		cin >> num;
		switch (num)
		{
			//必须是地址传递
			case 1:
				addPeopel(&abs);//添加
				break;
			case 2:
				deletePeopel(&abs);//删除
				break;
			case 3:
				//updatePeopel(&abs);//修改
				break;
			case 4:
				selectPeopel(&abs);//查询
				break;
			case 5:
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				break;
			default:
				break;
		}

	}

	
	return 0;
}

/// <summary>
///  添加通讯录人员
/// </summary>
/// <param name="abs"></param>
void addPeopel(AddressBook* abs) {

	//通讯录满了
	if (abs->peopelCount == MAX) {
		cout << "通讯录满了" << endl;
		return;
	}
	else {
		string name, address, telPhone;
		int sex, age;
		cout << "请输入人员姓名" << endl;
		cin >> name;
		cout << "请输入人员性别[0:女 1.男]" << endl;
		cin >> sex;
		cout << "请输入人员年龄" << endl;
		cin >> age;
		cout << "请输入人员手机" << endl;
		cin >> telPhone;
		cout << "请输入人员地址" << endl;
		cin >> address;

		int ind = abs->peopelCount;
		(abs->peopels)[ind].name = name;
		(abs->peopels)[ind].age = age;
		(abs->peopels)[ind].address = address;
		(abs->peopels)[ind].telPhone = telPhone;
		(abs->peopels)[ind].sex = sex;
		abs->peopelCount++;//下标加一
		cout << "添加联系人成功" << endl;
	}

}

/// <summary>
///  删除人员信息
/// </summary>
/// <param name="abs"></param>
void deletePeopel(AddressBook* abs) {
	int len = abs->peopelCount;
		//sizeof(abs) / sizeof(abs[0]);

	string name;
	cout << "请输入需要删除的人员姓名" << endl;
	cin >> name;

	int csInd = 0;
	int exist[30];//最多重复30个
	for (int i = 0; i < len; i++)
	{
		if ((abs->peopels)[i].name == name) {
			if (csInd < 30) {
				exist[csInd] = i;
				csInd++;
			}
		}
	}

	if (csInd <= 0) {
		cout << "查无此人" << endl;
		return;
	}

	//sizeof(exist) / sizeof(exist[0]);
	for (int k = 0; k <csInd; k++)
	{
		for (int i = exist[k]; i < len; i++)
		{
			abs->peopels[i] = abs->peopels[i + 1];//数据前移
		}
		abs->peopelCount--;
	}
	cout << "已删除用户:"+ name +"，个数为:"<<csInd<< endl;

}

/// <summary>
/// 查询人员信息
/// </summary>
/// <param name="abs"></param>
void selectPeopel(AddressBook* abs) {
	int len = abs->peopelCount;
		//sizeof(abs) / sizeof(abs[0]);

	string name;
	cout << "请输入需要查询的人员姓名" << endl;
	cin >> name;

	int csInd = 0;

	for (int i = 0; i < len; i++)
	{
		if ((abs->peopels)[i].name == name) {
				csInd++;
				if (csInd == 0) {
					cout << "***查询结果如下:***\r\n" << endl;
				}
				cout << "姓名:" + abs->peopels[i].name<<"，性别:"<< abs->peopels[i].sex << endl;

				cout << "手机号:" << abs->peopels[i].telPhone << "，地址:"<< abs->peopels[i].address << endl;
		}
	}

	if (csInd <= 0) {
		cout << "查无此人" << endl;
		return;
	}

	cout << "查询结果个数为:"<<csInd<< endl;

}

/// <summary>
/// 设置初始化的通讯录信息
/// </summary>
/// <param name="abs"></param>
void setDefaultAddressBook(AddressBook* abs) {
	abs->peopels[0].name = "刘备";
	abs->peopels[0].sex = 1;
	abs->peopels[0].age = 39;
	abs->peopels[0].telPhone = 150150;
	abs->peopels[0].address = "徐州";

	abs->peopels[1].name = "关羽";
	abs->peopels[1].sex = 1;
	abs->peopels[1].age = 35;
	abs->peopels[1].telPhone = 169000;
	abs->peopels[1].address = "四川";

	abs->peopels[2].name = "张飞";
	abs->peopels[2].sex = 1;
	abs->peopels[2].age = 32;
	abs->peopels[2].telPhone = 158000;
	abs->peopels[2].address = "涡阳";

	abs->peopels[3].name = "孙尚香";
	abs->peopels[3].sex = 0;
	abs->peopels[3].age = 19;
	abs->peopels[3].telPhone = 180180;
	abs->peopels[3].address = "台北";
	abs->peopelCount = 4;
}