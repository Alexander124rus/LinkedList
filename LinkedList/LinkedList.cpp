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
	template <class ITEM>
	struct Node {
		ITEM data;
		Node<ITEM>* next;
		Node(ITEM data, Node<ITEM>* next = nullptr) : data(data), next(next) {}
	};
	Node<T>* first;
	//Node* last;

public:

	List() : first(nullptr)/*, last(nullptr)*/ {};
	~List() {
		RemoveAll();
	};

	//Определение внешнего итератора
	//friend class Iterator;

	//class Iterator {
	//protected:
	//	Node* m_Node;
	//	const List* m_List;
	//public:

	//	Iterator(Node<T>* pNode, const List<ITEM>* pList) : m_Node(pNode), m_List(pList) {}

	//	//Проверка есть ли ещё элемнты
	//	bool HasMore() {
	//		return m_Node != 0;
	//	}

	//	//Переход к следующиму узлу
	//	void next() {
	//		if (m_Node != nullptr)
	//		{
	//			m_Node = m_Node->next;
	//		}
	//	}

	//	//Получение значения текущего узла
	//	T* Get() {
	//		if (m_Node != nullptr)
	//		{
	//			return &(m_Node->data);
	//		}
	//	}
	//
	//};


	//Добавить в начало списка
	void AddRevers(const T data) {
		if (Node<T>* node = new Node<T>(data)) {
			node->next = first;// Новый узел привязывается к старому головному элементу
			first = node;// Новый узел сам становится головным элементом
		}
	};

	//Добавить в конец списка
	void Add(const T data)
	{
		Node<T>* node = new Node<T>(data);
		if (first == nullptr) {
			first = node;
		}
		else {
			Node<T>* current = first;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = node;
		}
	}

	//Удаление из начала списка
	void RemoveBegin() {
		Node<T>* current = first;
		first = first->next;
		delete current;
	}
	//Удаление из конца списка
	void RemoveEnd() {
		Node<T>* current = first;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	//Удаление всего списка
	void RemoveAll() {
		Node<T>* current = first;
		while (current != nullptr)
		{
			first = current->next;
			delete current;
			current = first;
		}
		first = nullptr;
	}

	//Печать списка
	void PrintList() {
		Node<T>* current = first;
		while (current != nullptr)
		{
			cout << current->data << endl; // вывод значения элемента
			current = current->next; // переход к следующему узлу
		}
	}
};


int main(int args, const char * argv[])
{
	setlocale(LC_ALL,"Russian");
	List<char> list;
	/*for (int i = 0; i < 10; i++)
	{
		list.Add(i);

	}*/
	char a[3];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';


	list.Add('a');
	list.Add('b');
	list.Add('c');
	cout << "Первый список" << endl;
	list.PrintList();
	
	return 0;
}