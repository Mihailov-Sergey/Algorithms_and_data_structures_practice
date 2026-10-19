import std;

struct Node {
	int value = 0;
	Node* next;
	Node(int val, Node* nxt = nullptr) : value(val), next(nxt) {}
};

void print_positiv(Node* head) {
	Node* ptr = head;
	while (ptr) {
		if (ptr->value > 0) {
			std::cout << ptr->value << " ";
		}
		ptr = ptr->next;
	}
	std::cout << "\n";
}

int even_count(Node* head) {
	Node* ptr = head;
	int count = 0;
	while (ptr) {
		if (ptr->value % 2 == 0) {
			++count;
		}
		ptr = ptr->next;
	}
	return count;
}

bool ordered(Node* head) {
	Node* tmp = head;
	if (!tmp || !(tmp->next)) return true;
	while (tmp->next) {
		if (tmp->value > tmp->next->value) return false;
		tmp = tmp->next;
	}
	return true;
}

void add(Node* &head, int value) {
	Node* tmp = head;
	Node *last = new Node(value, nullptr);
	if (!head) {
		head = last;
		return;
	}
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = last;
}

void delete_back(Node*& head) {
	if (!head) return;
	if (!head->next) {
		delete head;
		head = nullptr;
		return;
	}
	Node* tmp = head;
	while (tmp->next->next) {
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
}

int count(Node* head, int num) {
	Node* ptr = head;
	int count = 0;
	while (ptr) {
		if (ptr->value == num) {
			++count;
		}
		ptr = ptr->next;
	}
	return count;
}

void insert_by_index(Node* &head, size_t index, int value) {
	if (index == 0) {
		head = new Node(value, head);
		return;
	}
	Node* tmp = head;
	size_t idx = 0;
	while (tmp && idx < index - 1) {
		tmp = tmp->next;
		++idx;
	}
	if (tmp) {
		Node* x = new Node(value, tmp->next);
		tmp->next = x;
	}
	else {
		std::println("Ошибка: Индекс {} вне диапазона списка!", index);
	}
}

void delete_by_index(Node*& head, size_t index) {
	if (!head) {
		std::println("Список пуст");
		return;
	}
	if (index == 0) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
		return;
	}
	Node* tmp = head;
	size_t idx = 0;
	while (tmp && idx < index - 1) {
		tmp = tmp->next;
		++idx;
	}
	if (tmp && tmp->next) {
		Node* to_delete = tmp->next;
		tmp->next = tmp->next->next;
		delete to_delete;
	}
	else {
		std::println("Ошибка: Индекс {} вне диапазона списка!", index);
	}
}


int main() {
	Node* head = new Node(1, new Node(2, new Node(3, new Node(10))));
	print_positiv(head);
	std::println("even_count: {}, ordered {}", even_count(head), ordered(head));

	add(head, 12);
	std::print("add(head, 12): ");
	print_positiv(head);

	delete_back(head);
	std::print("delete_back(head): ");
	print_positiv(head);

	insert_by_index(head, 2, 99);
	std::print("После вставки 99: ");
	print_positiv(head);

	delete_by_index(head, 2);
	std::print("После удаления idx=2: ");
	print_positiv(head);

	delete_by_index(head, 0);
	std::print("После удаления начала: ");
	print_positiv(head);

	while (head) {
		delete_by_index(head, 0);
	}
}

//добавить элемент в выбранную позицию
//удалить элемент через выбранную позицию