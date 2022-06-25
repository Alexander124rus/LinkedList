#include <iostream>
/*
* В этой версиии я не определяю указатель на последний узел списка.
* Через шаблонный класс определяю класс List вкладываю структуру узла Node.
* Метод AddRevers добовляет узел в начало списка.
* Метод Add добовляет в конец списка.
* 
* 
*/
using namespace std;

template <typename T>
class List {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T data, Node* next = nullptr) : data(data), next(next) {}
	};
	Node* first;
	//Node* last;

public:
	List() : first(nullptr)/*, last(nullptr)*/ {};
	~List() {
		RemoveAll();
	};

	//Добавить в начало списка
	void AddRevers(const T& data) {
		if (Node* node = new Node(data)) {
			node->next = first;// Новый узел привязывается к старому головному элементу
			first = node;// Новый узел сам становится головным элементом
		}
	};

	//Добавить в конец списка
	void Add(const T& data)
	{
		Node* node = new Node(data);
		if (first == nullptr) {
			first = node;
		}
		else {
			Node* current = first;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = node;
		}
	}

	//Удаление из начала списка
	void RemoveBegin() {
		Node* current = first;
		first = first->next;
		delete current;
	}
	//Удаление из конца списка
	void RemoveEnd() {
		Node* current = first;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	//Удаление всего списка
	void RemoveAll() {
		Node* current = first;
		while (current != nullptr)
		{
			first = current->next;
			delete current;
			current = first;
		}
		first = nullptr;
	}

	//Печать списка
	void PrintList()
	{
		Node* current = first;
		while (current != nullptr)
		{
			cout << current->data << endl; // вывод значения элемента
			current = current->next; // переход к следующему узлу
		}
	}

};

int main()
{
	setlocale(LC_ALL,"Russian");
	List<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.Add(i);

	}
	cout << "Первый список" << endl;
	list.PrintList();

	cout << "Удалить первый элемент списка" << endl;
	list.RemoveBegin();
	list.PrintList();
	return 0;
}