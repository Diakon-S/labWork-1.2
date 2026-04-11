#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cstring>
#include <chrono>

using namespace std;

const int maxStudentsInArray = 100;
const int maxStudentCard = 100;
const char* studentsFile = "students.txt";
const char* studCardFile = "studCard.txt";
const int currentYear = 2026;


struct Student {
	char surname[50];
	char name[50];
	char sex[10];
	int group;
	int id;
	int grades[8];
};

struct StudentCard {
	char name[50];
	char surname[50];
	char faculty[100];
	int group;
	int idCard;
	int birthYear;
	char email[100];
};


void saveAllStudents(Student students[maxStudentsInArray], int num) {
	ofstream fout("students.txt");   
	if (!fout) {
		cout << "Ошибка открытия файла для сохранения!\n";
		return;
	}
	for (int i = 0; i < num; i++) {
		fout << students[i].name << " "
			<< students[i].surname << " "
			<< students[i].sex << " "
			<< students[i].group << " "
			<< students[i].id << " ";
		for (int j = 0; j < 8; j++) {
			fout << students[i].grades[j];
			if (j < 7) fout << " ";
		}
		fout << "\n";
	}
	fout.close();
}

void showStudent(Student* stud) {
	cout << "Имя: " << stud->name << "\n";
	cout << "Фамилия: " << stud->surname << "\n";
	cout << "Пол: " << stud->sex << "\n";
	cout << "Группа: " << stud->group << "\n";
	cout << "Номер: " << stud->id << "\n";
	cout << "Оценки: " << stud->grades[0] << " " << stud->grades[1] << " " << stud->grades[2] << " " << stud->grades[3] << " " << stud->grades[4] << " " << stud->grades[5] << " " << stud->grades[6] << " " << stud->grades[7] << "\n";
}

void showAll(Student students[maxStudentsInArray], int num) {
	for (int i = 0; i < num; i++) {
		showStudent(students + i);
		Sleep(50);
		cout << endl;
	}
}

void showGroup(Student students[maxStudentsInArray], int num) {
	int choiceGroup;
	cout << "Введите номер группы: ";
	cin >> choiceGroup;
	cout << endl;
	for (int i = 0; i < num; i++) {
		if (students[i].group == choiceGroup) {
			showStudent(students + i);
			Sleep(50);
			cout << endl;
		}
	}
	cout << endl;
}

void showGender(Student students[maxStudentsInArray], int num) {
	int m = 0, f = 0;
	for (int i = 0; i < num; i++) {
		if (strcmp(students[i].sex, "M") == 0) {
			m++;
		}
		else if (strcmp(students[i].sex, "F") == 0){
			f++;
		}
	}
	cout << "Количество студентов мужского пола: " << m << endl;
	cout << "Количество студентов женского пола: " << f << endl;
}

void showId(Student students[maxStudentsInArray], int num) {
	int choiceId;
	cout << "Введите номер студента в списке: ";
	cin >> choiceId;
	cout << endl;
	if (choiceId > num) {
		cout << "Студентов под таким номером нет.\n";
	}
	else {
		for (int i = 0; i < num; i++) {
			if (students[i].id == choiceId) {
				showStudent(students + i);
				Sleep(50);
				cout << endl;
			}
		}
	}
	cout << endl;
}

int sumOfGrades(Student students[maxStudentsInArray], int num) {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += students[num].grades[i];
	}
	return sum;
}

void leaders(Student students[maxStudentsInArray], int num) {
	int highestGPA = sumOfGrades(students, 0);

	for (int i = 0; i < num; i++) {
		if (sumOfGrades(students, i) >= highestGPA) {
			highestGPA = sumOfGrades(students, i);
		}
	}

	cout << "Студенты с наивысшим рейтингом:" << endl;
	for (int i = 0; i < num; i++) {
		if (sumOfGrades(students, i) == highestGPA) {
			showStudent(students + i);
			Sleep(50);
			cout << endl;
		}
	}
	cout << endl;
}

void statistico(Student students[maxStudentsInArray], int num) {
	int choice;
	cout << "1 - Студенты, которые не получают стипендию\n";
	cout << "2 - Студенты, которые учатся на «хорошо» и «отлично»\n";
	cout << "3 - Студенты, которые учатся только на «отлично»\n";
	cout << "Выберите, какую категорию студентов отобразить: ";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1: {
		for (int i = 0; i < num; i++) {
			if ((students[i].grades[0] == 3) || (students[i].grades[1] == 3) || (students[i].grades[2] == 3) || (students[i].grades[3] == 3) || (students[i].grades[4] == 3) || (students[i].grades[5] == 3) || (students[i].grades[6] == 3) || (students[i].grades[7] == 3)) {
				showStudent(students + i);
				Sleep(50);
				cout << endl;
			}
		}
		break;
		}
	case 2: {
		for (int i = 0; i < num; i++) {
			if ((students[i].grades[0] > 3) && (students[i].grades[1] > 3) && (students[i].grades[2] > 3) && (students[i].grades[3] > 3) && (students[i].grades[4] > 3) && (students[i].grades[5] > 3) && (students[i].grades[6] > 3) && (students[i].grades[7] > 3)) {
				showStudent(students + i);
				Sleep(50);
				cout << endl;
			}
		}
		break;
	}
	case 3: {
		for (int i = 0; i < num; i++) {
			if ((students[i].grades[0] == 5) && (students[i].grades[1] == 5) && (students[i].grades[2] == 5) && (students[i].grades[3] == 5) && (students[i].grades[4] == 5) && (students[i].grades[5] == 5) && (students[i].grades[6] == 5) && (students[i].grades[7] == 5)) {
				showStudent(students + i);
				Sleep(50);
				cout << endl;
			}
		}
		break;
	}
	default: {
		cout << "Error" << endl;
		break;
	}
	}


}

void makeStudent(Student students[maxStudentsInArray], int& num) {
	char newSurname[50];
	char newName[50];
	char newSex[10];
	int newGroup;
	int newId;
	int newGrades[8];

	int flag = 0;

	cout << "Введите Имя и Фамилию студента: ";
	cin >> newName >> newSurname;
	cin.ignore(1000, '\n');

	cout << "\nВведите пол студента (M/F): ";
	cin >> newSex;
	cin.ignore(1000, '\n');

	cout << "\nВведите группу студента (5372/5376): ";
	cin >> newGroup;
	cin.ignore(1000, '\n');

	cout << "\nВведите номер студента в списке: ";
	cin >> newId;
	cin.ignore(1000, '\n');
	
	for (int i = 0; i < num; i++) {
		if (students[i].id == newId) {
			flag += 1;
		}
	}

	int groupOne = 0, groupTwo = 0;
	for (int i = 0; i < num; i++) {
		if (students[i].group == 5372) {
			groupOne += 1;
		}
		else if (students[i].group == 5376) {
			groupTwo += 1;
		}
	}

	if (flag != 0) {
		if (newGroup == 5372) {
			newId = groupOne + 1;
		}
		else {
			newId = groupTwo + 1;
		}
	}

	cout << "\nВведите оценки студента (8): ";
	for (int i = 0; i < 8; i++) {
		cin >> newGrades[i];
	}

	bool hasTwo = false;
	for (int i = 0; i < 8; i++) {
		if (newGrades[i] == 2) {
			hasTwo = true;
			break;
		}
	}
	if (hasTwo) {
		cout << "Студент отчислен. Запись не добавлена.\n";
		return;
	}

	cin.ignore(1000, '\n');

	int lenCounter = 0;

	while (newSurname[lenCounter] != '\0' && lenCounter < 49) {
		students[num].surname[lenCounter] = newSurname[lenCounter];
		lenCounter++;
	}
	students[num].surname[lenCounter] = '\0';

	lenCounter = 0;

	while (newName[lenCounter] != '\0' && lenCounter < 49) {
		students[num].name[lenCounter] = newName[lenCounter];
		lenCounter++;
	}
	students[num].name[lenCounter] = '\0';

	lenCounter = 0;

	while (newSex[lenCounter] != '\0' && lenCounter < 9) {
		students[num].sex[lenCounter] = newSex[lenCounter];
		lenCounter++;
	}
	students[num].sex[lenCounter] = '\0';

	students[num].group = newGroup;
	students[num].id = newId;
	for (int i = 0; i < 8; i++) {
		students[num].grades[i] = newGrades[i];
	}

	num++;

	ofstream outFile("students.txt", ios::app);
	if (!outFile) {
		cout << "Ошибка открытия файла для записи.\n";
		return;
	}

	outFile << students[num - 1].name << " "
		<< students[num - 1].surname << " "
		<< students[num - 1].sex << " "
		<< students[num - 1].group << " "
		<< students[num - 1].id << " ";
	for (int i = 0; i < 8; i++) {
		outFile << students[num - 1].grades[i];
		if (i < 7) outFile << " ";
	}
	outFile << "\n";

	outFile.close();
	cout << "Студент успешно добавлен и сохранён в файл.\n";

}

void rewriteStudent(Student students[maxStudentsInArray], int& num) {
	int choiceGroup, choiceId;
	cout << "Введите группу и номер студента: ";
	cin >> choiceGroup >> choiceId;

	int reIndex = -1;
	for (int i = 0; i < num; i++) {
		if (students[i].group == choiceGroup && students[i].id == choiceId) {
			reIndex = i;
			break;
		}
	}

	if (reIndex == -1) {
		cout << "Такого студента нет." << endl;
		return;
	}

	int choice;
	cout << "1 - Имя\n2 - Фамилия\n3 - Пол\n4 - Группа\n5 - Номер в списке\n6 - Оценки\n0 - Ничего не менять\n";
	cout << "Выберите, что поменять: ";
	cin >> choice;
	cout << endl;

	switch (choice) {
	case 1: {
		char reName[50];
		cout << "Введите новое Имя: ";
		cin >> reName;
		int nameCounter = 0;
		while (reName[nameCounter] != '\0' && nameCounter < 49) {
			students[reIndex].name[nameCounter] = reName[nameCounter];
			nameCounter++;
		}
		students[reIndex].name[nameCounter] = '\0';
		break;
	}
	case 2: {
		char reSurname[50];
		cout << "Введите новую Фамилию: ";
		cin >> reSurname;
		int surnameCounter = 0;
		while (reSurname[surnameCounter] != '\0' && surnameCounter < 49) {
			students[reIndex].surname[surnameCounter] = reSurname[surnameCounter];
			surnameCounter++;
		}
		students[reIndex].surname[surnameCounter] = '\0';
		break;
	}
	case 3: {
		char reSex[10];
		cout << "Ну давай, подставь его(её) под статью: ";
		cin >> reSex;
		int sexCounter = 0;
		while (reSex[sexCounter] != '\0' && sexCounter < 9) {
			students[reIndex].sex[sexCounter] = reSex[sexCounter];
			sexCounter++;
		}
		students[reIndex].sex[sexCounter] = '\0';
		break;
	}
	case 4: {
		int reGroup;
		cout << "Введите новую группу: ";
		cin >> reGroup;
		students[reIndex].group = reGroup;
		break;
	}
	case 5: {
		int reId;
		cout << "Введите новый номер: ";
		cin >> reId;
		int reFlag = 0;
		for (int i = 0; i < num; i++) {
			if (students[i].id == reId) {
				reFlag++;
			}

		}
		if (reFlag == 0) {
			students[reIndex].id = reId;
		}
		else {
			cout << "Такой номер уже существует\n";
			break;
		}
		break;
	}
	case 6: {
		int reGrades[8];
		cout << "Введите новые оценки: ";
		for (int i = 0; i < 8; i++) {
			cin >> reGrades[i];
			students[reIndex].grades[i] = reGrades[i];
		}

		bool hasTwo = false;
		for (int i = 0; i < 8; i++) {
			if (reGrades[i] == 2) {
				hasTwo = true;
				break;
			}
		}

		if (hasTwo) {
			cout << "Студент отчислен и будет удалён из списка.\n";

			for (int i = reIndex; i < num - 1; i++) {
				students[i] = students[i + 1];
			}
			num--;

			saveAllStudents(students, num);
			return;
		}
		else {
			for (int i = 0; i < 8; i++) {
				students[reIndex].grades[i] = reGrades[i];
			}
		}
		break;
	}
	case 0: {
		cout << "Ну и ладно." << endl;
		return;
	}
	default: { cout << "Неверный выбор! Введите пункт от 0 до 6.\n" << endl; }
	}

	saveAllStudents(students, num);
}



void showCard(StudentCard* card) {
	cout << card->name << " " << card->surname << "\n";
	cout << card->faculty << "\n";
	cout << card->group << "\n";
	cout << card->idCard << "\n";
	cout << card->birthYear << "\n";
	cout << card->email << "\n";
}

void showAllCard(StudentCard card[maxStudentCard], int num) {
	for (int i = 0; i < num; i++) {
		showCard(card + i);
		Sleep(50);
		cout << endl;
	}
}

void showAge(StudentCard card[maxStudentCard], int num) {
	for (int i = 0; i < num; i++) {
		if (currentYear - card[i].birthYear < 20) {
			showCard(card + i);
			Sleep(50);
			cout << endl;
		}
	}
}

void showCardGroup(StudentCard card[maxStudentCard], int num) {
	int choiceGroup;
	cout << "Введите номер группы: ";
	cin >> choiceGroup;
	cout << endl;
	for (int i = 0; i < num; i++) {
		if (card[i].group == choiceGroup) {
			showCard(card + i);
			Sleep(50);
			cout << endl;
		}
	}
	cout << endl;
}

void mailingList(StudentCard* card) {
	cout << card->name << " " << card->surname << "\n";
	cout << card->email << "\n";
}

void mailingAll(StudentCard card[maxStudentCard], int num) {
	for (int i = 0; i < num; i++) {
		mailingList(card + i);
		Sleep(50);
		cout << endl;
	}
}


int main() {
	setlocale(0, "Rus");
	Student students[maxStudentsInArray];
	StudentCard card[maxStudentCard];
	int counter = 0;
	int counter1 = 0;
	int taskChoice;

	ifstream inFile(studentsFile);
	if (inFile.is_open()) {
		while (counter < maxStudentsInArray &&
			inFile >> students[counter].name >>
			students[counter].surname >>
			students[counter].sex >>
			students[counter].group >>
			students[counter].id >>
			students[counter].grades[0] >>
			students[counter].grades[1] >>
			students[counter].grades[2] >>
			students[counter].grades[3] >>
			students[counter].grades[4] >>
			students[counter].grades[5] >>
			students[counter].grades[6] >>
			students[counter].grades[7]) {
			counter++;
		}
		inFile.close();
	}

	ifstream inCardFile(studCardFile);
	if (inCardFile.is_open()) {
		while (counter1 < maxStudentCard &&
			inCardFile >> card[counter1].name >>
			card[counter1].surname >>
			card[counter1].faculty >>
			card[counter1].group >>
			card[counter1].idCard >>
			card[counter1].birthYear >>
			card[counter1].email) {
			counter1++;
		}
		inCardFile.close();
	}

	do {
		cout << "1 - Создание новой записи о студенте." << endl;
		cout << "2 - Внесение изменений в уже имеющуюся запись." << endl;
		cout << "3 - Вывод всех данных о студентах." << endl;
		cout << "4 - Вывод информации обо всех студентах группы N." << endl;
		cout << "5 - Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." << endl;
		cout << "6 - Вывод количества студентов мужского и женского пола." << endl;
		cout << "7 - Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»." << endl;
		cout << "8 - Вывод данных о студентах, имеющих номер в списке – k." << endl;
		cout << "9 - Структура «Студенческий билет»." << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "Выберите пункт: ";
		cin >> taskChoice;
		cout << endl;

		switch (taskChoice) {
		case 1: {
			system("cls");
			makeStudent(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			rewriteStudent(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			showAll(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			showGroup(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			leaders(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			showGender(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			system("cls");
			statistico(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			system("cls");
			showId(students, counter);
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			system("cls");
			int cardChoice;
			cout << "1 - Вывод всех студентов.\n";
			cout << "2 - Вывод студентов младше 20 лет.\n";
			cout << "3 - Вывод студентов группы N.\n";
			cout << "4 - Вывод студентов для рассылки.\n";
			cout << "Выберите пункт: ";
			cin >> cardChoice;
			cout << endl;

			switch (cardChoice) {
			case 1: {
				system("cls");
				showAllCard(card, counter1);
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				system("cls");
				showAge(card, counter1);
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				showCardGroup(card, counter1);
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				system("cls");
				mailingAll(card, counter1);
				system("pause");
				system("cls");
				break;
			}
			default: { 
				cout << "Неверный выбор! Введите пункт от 0 до 9.\n" << endl; 
				cin.ignore(1000, '\n');
			}
			}
			break;
		}
		case 0: {
			cout << "Выход из программы." << endl;
			break;
		}
		default: {
			cout << "Неверный выбор! Введите пункт от 0 до 9.\n" << endl;
			cin.ignore(1000, '\n');
		}
		}

	} while (taskChoice != 0);

	return 0;
}
