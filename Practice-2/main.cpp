import std;

class Map {
private:
	struct pair {
		std::string _key = "";
		double _value = 0.0;
	};
	pair* _arr = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
public:
	Map() {}
	Map(size_t size, size_t capacity) : _size(size), _capacity(capacity > size ? capacity : size) {
		if (_capacity > 0) {
			_arr = new pair[_capacity]();
		}
	}
	Map(const Map& other) : _size(other._size), _capacity(other._capacity) {
		if (_capacity > 0) {
			_arr = new pair[_capacity]();
			for (size_t i = 0; i < _size; ++i) {
				_arr[i] = other._arr[i];
			}
		}
	}
	~Map() {
		delete[] _arr;
	}
	Map& operator=(const Map& other) {
		if (this == &other) {
			return *this;
		}
		pair* new_arr = nullptr;
		if (other._capacity > 0) {
			new_arr = new pair[other._capacity]();
			for (size_t i = 0; i < other._size; ++i) {
				new_arr[i] = other._arr[i];
			}
		}
		delete[] _arr;
		_arr = new_arr;
		_size = other._size;
		_capacity = other._capacity;
		return *this;
	}
	double& operator[](const std::string& key) {
		for (size_t i = 0; i < _size; ++i) {
			if (_arr[i]._key == key) return _arr[i]._value;
		}
		throw std::out_of_range("NO Key");
	}
	Map& operator+=(const pair& p) {
		for (size_t i = 0; i < _size; ++i) {
			if (_arr[i]._key == p._key) return *this;
		}
		if (_size >= _capacity) {
			size_t new_capacity;
			if (_capacity == 0) {
				new_capacity = 4;
			}
			else {
				new_capacity = _capacity * 2;
			}
			pair* new_arr = new pair[new_capacity]();
			for (size_t i = 0; i < _size; ++i) {
				new_arr[i] = _arr[i];
			}
			delete[] _arr;
			_arr = new_arr;
			_capacity = new_capacity;
		}
		_arr[_size] = p;
		++_size;
		return *this;
	}
};

int main() {
	try {
		Map my_map;
		my_map += {"apple", 1.0};
		my_map += {"banana", 2.5};
		my_map += {"apple", 9.0};
		std::cout << "Apple price: " << my_map["apple"] << "\n";
		std::cout << "Banana price: " << my_map["banana"] << "\n";
		my_map["apple"] = 1.99;
		std::cout << "New apple price: " << my_map["apple"] << "\n";
		Map copy_map;
		copy_map = my_map;
		std::cout << "copy_map[\"banana\"]: " << copy_map["banana"] << "\n";
		std::cout << my_map["grape"] << "\n";
	}
	catch (const std::out_of_range& e) {
		std::cout << "\nException: " << e.what() << "\n";
	}
	return 0;
}

