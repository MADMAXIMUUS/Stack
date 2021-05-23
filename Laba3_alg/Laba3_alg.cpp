#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

struct stack 
{
	int data = 0;
	stack* next = nullptr;
};

int Count=0;

void push(int data, stack *&next)
{
	Count++;
	stack* myStack = new stack;               
	myStack->data = data;                 
	myStack->next = next;                   
	next = myStack;          
}

int pop(stack *&next)
{
	if (next!=NULL) {
		Count--;
		int temp = next->data;
		stack* myStack = next;
		next = next->next;
		delete myStack;
		return temp;
	}
	else cout << "Стек пуст!!!" << endl;
}

void print(stack* myStack)
{
	ofstream f("output.txt");
	if (Count == 0) cout << endl << "Стек пуст!!!" << endl << endl;
	else {
		stack* temp = myStack;
		int i = Count-1;
		cout << "\nStack:\n";
		while (temp->next)
		{
			cout << i << " - " << temp->data << endl;
			f << i << " - " << temp->data << endl;
			temp = temp->next;
			i--;
		}
		cout<<endl<<"Стек в файле" << endl<<endl;
	}
}

void dellAll(stack *&myStack)
{
	while (myStack->next)
	{
		pop(myStack);
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian");
	stack* myStack = new stack;
	int n = -1, c;
	while (n != 0) {
		cout << "1: Создать список;" << endl
			 << "2: Вывести список;" << endl
			 << "3: Достать последний элемент;" << endl
			 << "4: Положить в стек;" << endl
			 << "5: Очистка списка;" << endl
			 << "0: Выход;" << endl
			 << "Введите номер операции: ";
		cin >> n;
		switch (n)
		{
		case 1:
			for (int i = 0; i < 19; i++)
				push(rand() % 1000, myStack);
			print(myStack);
			break;
		case 2:
			print(myStack);
			break;
		case 3:
			cout << endl << pop(myStack) << endl;
			print(myStack);
			break;
		case 4:
			cout << "Введите число, которое нужно добавить в стек: ";
			cin >> c;
			push(c, myStack);
			print(myStack);
			break;
		case 5:
			dellAll(myStack);
			print(myStack);
			break;
		case 0: break;
		default:
			cout << endl << "Вы ввели неверное значение" << endl << endl; break;
		}
	}
	system("pause");
	return 0;
}
