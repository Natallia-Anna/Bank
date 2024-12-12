// ���������� ���������� ��� ������ � �������� �����-������
#include <iostream>
// ���������� ���������� ��� �������� ��������
#include <locale.h>
// ���������� ���������� ��� ������ �� ��������
#include <string>
// ���������� ���������� ��� ������ � �������
#include<fstream>
// ��������� ������������ ���� std ��� ��������
using namespace std;

// ��������� ����� ����
class Account {
private:
	// ��������� ��� ���� ���� string ��� �������� ����� � ������� �������
	string name;
	string surname;

	// ��������� ���� ���� ���� int ��� �������� ������ �����
	int number;

	// ��������� ���� ���� ���� double ��� �������� ������� �����
	double balance;


public:
	// ��������� ����������� � �����������, ������� �������������� ��� ���� ��������� ����������
	Account(string n, string s, int num, double b) {
		name = n;
		surname = s;
		number = num;
		balance = b;
	}

	// ��������� ����� deposit, ������� ��������� ����� ����� � ����������� ������ ����� �� ��� �����
	void deposit(double amount) {
		balance += amount;
	}

	// ��������� ����� withdraw, ������� ��������� ����� ����� � ��������� ������ ����� �� ��� �����, ���� ��� �������� (������ �� ����� ���� �������������)
	void withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
		}
		else {
			cout << "������������ ������� �� �����" << endl;
		}
	}

	// ��������� ����� getBalance, ������� ���������� ������� ������ �����
	double getBalance() {
		return balance;
	}

	// ����� ��� �������� � �������� ��������, ���� ������ ����� ����
	bool deleteAccount() {
		if (balance == 0) {
			cout << "������� ������" << endl;
			return true; // ���������� true, ���� ������� ������
		}
		else {
			cout << "������ �� ����� ����, ������� �� ����� ���� ������" << endl;
			return false; // ���������� false, ���� ������� �� ������
		}
	}

	// ��������� ����� print, ������� ������� ���������� � ����� �� �����
	void print(ofstream& file) {
		cout << "������: " << name << " " << surname << endl;
		cout << "����� �����: " << number << endl;
		cout << "������: " << balance << endl;
		if (bool (deleteAccount()) == true && balance == 0) {
			cout << "������� ������: " << balance << endl;
		}

		file << "������: " << name << " " << surname << endl;
		file << "����� �����: " << number << endl;
		file << "������: " << balance << endl;
		if (bool (deleteAccount()) == true && balance == 0) {
			cout << "������� ������: " << balance << endl;
		}
		file << "������� ������: " << balance << endl;
	}
};

// ������� ������� ���������
int main() {
	ofstream file("accounts.txt");
	setlocale(LC_ALL, "Russian");

	// ������� ��� ������� ������ ���� � ������� �������
	Account a1("����", "������", 123456, 10000); // ���� ����� ������� � ������� 123456 � �������� 10000
	Account a2("����", "������", 654321, 5000); // ���� ����� ������� � ������� 654321 � �������� 5000

	// ������� �� ����� ���������� � ������, ��������� ����� print
	cout << "���������� � ������ �����:" << endl;
	a1.print(file);
	cout << endl;

	cout << "���������� � ������ �����:" << endl;
	a2.print(file);
	cout << endl;
	

	// ���������������� ������ ������� deposit � withdraw
	cout << "�������� ������ ���� �� 2000:" << endl;
	a1.deposit(2000); // ��������� ������ ���� �� 2000
	a1.print(file); // ������� ���������� � ������ �����
	cout << endl;

	cout << "������ �� ������� ����� 3000:" << endl;
	a2.withdraw(3000); // ������� �� ������� ����� 3000
	a2.print(file); // ������� ���������� � ������ �����
	
	cout << "���������� ����� �� ������� ����� ��� 3000:" << endl;
	a2.withdraw(3000); // �������� ����� �� ������� ����� ��� 3000
	a2.print(file); // ������� ���������� � ������ �����
	cout << endl;

	// ������� ������ ���� ����� ����, ��� ������� � ���� �������
	cout << "������ � ������� ����� 12000 � ������� ���:" << endl;
	a1.withdraw(12000); // ������� �� ����� 12000
	a1.deleteAccount(); // ��������� ����
	a1.print(file); // ������� ���� � ������� � ����
	cout << endl;

	// ��������� ���� accounts.txt
	file.close();

	// ��������� ���������
	return 0;
}