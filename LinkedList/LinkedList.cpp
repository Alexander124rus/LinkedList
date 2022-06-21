#include <iostream>

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

public:
	List() : first(nullptr) {};
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

	}
	//Удаление из конца списка
	void RemoveEnd() {
		Node* current = first;
		while (current->next != nullptr) {
			current = current->next;
		}
		Node* temp = current->next;
		delete temp;
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
	list.PrintList();
	list.RemoveEnd();
	//cout << "Мы удалили элементы" << endl;
	list.PrintList();

	//cout << "Hello World!\n";
	return 0;
}