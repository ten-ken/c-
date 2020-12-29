#include <iostream>
#include "MenuCommand.h";

using namespace std;

const int MAX = 2000;//ͨѶ¼���2ǧ��

/// <summary>
/// ��Ա�ṹ��
/// </summary>
struct Peopel
{
	string name;
	int sex;//�Ա�
	int  age;
	string address;
	string telPhone;
};
/// <summary>
/// ͨѶ¼�ṹ��
/// </summary>
struct AddressBook
{
	//ͨѶ¼�е���Ա�б�
	struct Peopel  peopels[MAX];

	//ͨѶ¼�е���Ա����
	int peopelCount;
};


int main();

//���붨����main����ǰ��  �������ͨ�� ���б���
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
	showMenu();//�˵�չʾ
	setDefaultAddressBook(&abs);//Ĭ��ͨѶ¼
	while (true) {
		cin >> num;
		switch (num)
		{
			//�����ǵ�ַ����
			case 1:
				addPeopel(&abs);//���
				break;
			case 2:
				deletePeopel(&abs);//ɾ��
				break;
			case 3:
				//updatePeopel(&abs);//�޸�
				break;
			case 4:
				selectPeopel(&abs);//��ѯ
				break;
			case 5:
				break;
			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				break;
			default:
				break;
		}

	}

	
	return 0;
}

/// <summary>
///  ���ͨѶ¼��Ա
/// </summary>
/// <param name="abs"></param>
void addPeopel(AddressBook* abs) {

	//ͨѶ¼����
	if (abs->peopelCount == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string name, address, telPhone;
		int sex, age;
		cout << "��������Ա����" << endl;
		cin >> name;
		cout << "��������Ա�Ա�[0:Ů 1.��]" << endl;
		cin >> sex;
		cout << "��������Ա����" << endl;
		cin >> age;
		cout << "��������Ա�ֻ�" << endl;
		cin >> telPhone;
		cout << "��������Ա��ַ" << endl;
		cin >> address;

		int ind = abs->peopelCount;
		(abs->peopels)[ind].name = name;
		(abs->peopels)[ind].age = age;
		(abs->peopels)[ind].address = address;
		(abs->peopels)[ind].telPhone = telPhone;
		(abs->peopels)[ind].sex = sex;
		abs->peopelCount++;//�±��һ
		cout << "�����ϵ�˳ɹ�" << endl;
	}

}

/// <summary>
///  ɾ����Ա��Ϣ
/// </summary>
/// <param name="abs"></param>
void deletePeopel(AddressBook* abs) {
	int len = abs->peopelCount;
		//sizeof(abs) / sizeof(abs[0]);

	string name;
	cout << "��������Ҫɾ������Ա����" << endl;
	cin >> name;

	int csInd = 0;
	int exist[30];//����ظ�30��
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
		cout << "���޴���" << endl;
		return;
	}

	//sizeof(exist) / sizeof(exist[0]);
	for (int k = 0; k <csInd; k++)
	{
		for (int i = exist[k]; i < len; i++)
		{
			abs->peopels[i] = abs->peopels[i + 1];//����ǰ��
		}
		abs->peopelCount--;
	}
	cout << "��ɾ���û�:"+ name +"������Ϊ:"<<csInd<< endl;

}

/// <summary>
/// ��ѯ��Ա��Ϣ
/// </summary>
/// <param name="abs"></param>
void selectPeopel(AddressBook* abs) {
	int len = abs->peopelCount;
		//sizeof(abs) / sizeof(abs[0]);

	string name;
	cout << "��������Ҫ��ѯ����Ա����" << endl;
	cin >> name;

	int csInd = 0;

	for (int i = 0; i < len; i++)
	{
		if ((abs->peopels)[i].name == name) {
				csInd++;
				if (csInd == 0) {
					cout << "***��ѯ�������:***\r\n" << endl;
				}
				cout << "����:" + abs->peopels[i].name<<"���Ա�:"<< abs->peopels[i].sex << endl;

				cout << "�ֻ���:" << abs->peopels[i].telPhone << "����ַ:"<< abs->peopels[i].address << endl;
		}
	}

	if (csInd <= 0) {
		cout << "���޴���" << endl;
		return;
	}

	cout << "��ѯ�������Ϊ:"<<csInd<< endl;

}

/// <summary>
/// ���ó�ʼ����ͨѶ¼��Ϣ
/// </summary>
/// <param name="abs"></param>
void setDefaultAddressBook(AddressBook* abs) {
	abs->peopels[0].name = "����";
	abs->peopels[0].sex = 1;
	abs->peopels[0].age = 39;
	abs->peopels[0].telPhone = 150150;
	abs->peopels[0].address = "����";

	abs->peopels[1].name = "����";
	abs->peopels[1].sex = 1;
	abs->peopels[1].age = 35;
	abs->peopels[1].telPhone = 169000;
	abs->peopels[1].address = "�Ĵ�";

	abs->peopels[2].name = "�ŷ�";
	abs->peopels[2].sex = 1;
	abs->peopels[2].age = 32;
	abs->peopels[2].telPhone = 158000;
	abs->peopels[2].address = "����";

	abs->peopels[3].name = "������";
	abs->peopels[3].sex = 0;
	abs->peopels[3].age = 19;
	abs->peopels[3].telPhone = 180180;
	abs->peopels[3].address = "̨��";
	abs->peopelCount = 4;
}