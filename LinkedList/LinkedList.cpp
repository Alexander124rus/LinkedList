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
		Node(T data, Node* next = nullptr) : data(data), next(next) {}
	};
	Node* first;
	//Node* last;

public:
	class RemoveItemException {};
	class InsertItemException {};
	List() : first(nullptr)/*, last(nullptr)*/ {};
	~List() {
		RemoveAll();
	};

	//Определение внешнего итератора
	friend class Iterator;

	//class Iterator {
	//protected:
	//	Node* m_Node;
	//	const List* m_List;
	//public:

	//	Iterator(Node* pNode, const List* pList) : m_Node(pNode), m_List(pList) {}

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

	/*class Iterator
	{
		Node* currentIt;
		Node** ptrToCurrentIt;
	public:
		Iterator(List<T>* pList)
		{
			ptrToCurrentIt = &(pList->first);
			currentIt = *ptrToCurrentIt;
		}
		bool hasMore()
		{
			return currentIt != 0;
		}
		void next()
		{
			if (currentIt == 0) throw BadIteratorException();
			ptrToCurrentIt = &(currentIt->next);
			currentIt = *ptrToCurrentIt;
		}

		T* get()
		{
			if (currentIt == 0) throw BadIteratorException();
			return &(currentIt->data);
		}
		Iterator* iterator()
		{
			return new Iterator(this);
		}
	private:
		Node* first;
	};*/

	//Добавить в начало списка
	void AddRevers(T data) {
		if (Node* node = new Node(data)) {
			node->next = first;// Новый узел привязывается к старому головному элементу
			first = node;// Новый узел сам становится головным элементом
		}
	};

	//Добавить в конец списка
	void Add(T data)
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
	void PrintList() {
		Node* current = first;
		while (current != nullptr)
		{
			cout << current->data << endl; // вывод значения элемента
			current = current->next; // переход к следующему узлу
		}
	}
};


//template <class T>
//bool HasItem(List<T>&list, const T & checkData)
//{
//	List<T>::Iterator* iterator = list.iterator();
//	bool found = false;
//	while (iterator->HasMore())
//	{
//		T* ptrItem = iterator->Get();
//		if (*ptrItem == checkData)
//		{
//			found = true;
//			break;
//		}
//		iterator->next();
//	}
//	delete iterator;
//	return found;
//}

//template <class T>
//void List<T>::PrintList();

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