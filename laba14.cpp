// Подключаем библиотеку для работы с потоками ввода-вывода
#include <iostream>
// Подключаем библиотеку для символов кирилицы
#include <locale.h>
// Подключаем библиотеку для работы со строками
#include <string>
// Подключаем библиотеку для работы с файлами
#include<fstream>
// Объявляем пространство имен std для удобства
using namespace std;

// Объявляем класс Счет
class Account {
private:
	// Объявляем два поля типа string для хранения имени и фамилии клиента
	string name;
	string surname;

	// Объявляем одно поле типа int для хранения номера счета
	int number;

	// Объявляем одно поле типа double для хранения баланса счета
	double balance;


public:
	// Объявляем конструктор с параметрами, который инициализирует все поля заданными значениями
	Account(string n, string s, int num, double b) {
		name = n;
		surname = s;
		number = num;
		balance = b;
	}

	// Объявляем метод deposit, который принимает сумму денег и увеличивает баланс счета на эту сумму
	void deposit(double amount) {
		balance += amount;
	}

	// Объявляем метод withdraw, который принимает сумму денег и уменьшает баланс счета на эту сумму, если это возможно (баланс не может быть отрицательным)
	void withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
		}
		else {
			cout << "Недостаточно средств на счете" << endl;
		}
	}

	// Объявляем метод getBalance, который возвращает текущий баланс счета
	double getBalance() {
		return balance;
	}

	// Метод для проверки и удаления аккаунта, если баланс равен нулю
	bool deleteAccount() {
		if (balance == 0) {
			cout << "Аккаунт удален" << endl;
			return true; // Возвращаем true, если аккаунт удален
		}
		else {
			cout << "Баланс не равен нулю, аккаунт не может быть удален" << endl;
			return false; // Возвращаем false, если аккаунт не удален
		}
	}

	// Объявляем метод print, который выводит информацию о счете на экран
	void print(ofstream& file) {
		cout << "Клиент: " << name << " " << surname << endl;
		cout << "Номер счета: " << number << endl;
		cout << "Баланс: " << balance << endl;
		if (bool (deleteAccount()) == true && balance == 0) {
			cout << "Аккаунт удален: " << balance << endl;
		}

		file << "Клиент: " << name << " " << surname << endl;
		file << "Номер счета: " << number << endl;
		file << "Баланс: " << balance << endl;
		if (bool (deleteAccount()) == true && balance == 0) {
			cout << "Аккаунт удален: " << balance << endl;
		}
		file << "Аккаунт удален: " << balance << endl;
	}
};

// Главная функция программы
int main() {
	ofstream file("accounts.txt");
	setlocale(LC_ALL, "Russian");

	// Создаем два объекта класса Счет с разными данными
	Account a1("Иван", "Иванов", 123456, 10000); // счет Ивана Иванова с номером 123456 и балансом 10000
	Account a2("Петр", "Петров", 654321, 5000); // счет Петра Петрова с номером 654321 и балансом 5000

	// Выводим на экран информацию о счетах, используя метод print
	cout << "Информация о первом счете:" << endl;
	a1.print(file);
	cout << endl;

	cout << "Информация о втором счете:" << endl;
	a2.print(file);
	cout << endl;
	

	// Продемонстрируем работу методов deposit и withdraw
	cout << "Пополним первый счет на 2000:" << endl;
	a1.deposit(2000); // пополняем первый счет на 2000
	a1.print(file); // выводим информацию о первом счете
	cout << endl;

	cout << "Снимем со второго счета 3000:" << endl;
	a2.withdraw(3000); // снимаем со второго счета 3000
	a2.print(file); // выводим информацию о втором счете
	
	cout << "Попытаемся снять со второго счета еще 3000:" << endl;
	a2.withdraw(3000); // пытаемся снять со второго счета еще 3000
	a2.print(file); // выводим информацию о втором счете
	cout << endl;

	// Закроем первый счёт после того, как снимаем с него остаток
	cout << "Снимем с первого счёта 12000 и закроем его:" << endl;
	a1.withdraw(12000); // снимаем со счёта 12000
	a1.deleteAccount(); // закрываем счёт
	a1.print(file); // выводим инфу в консоль и файл
	cout << endl;

	// Закрываем файл accounts.txt
	file.close();

	// Завершаем программу
	return 0;
}