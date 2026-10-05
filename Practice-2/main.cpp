import std;

class Map {
private:
	struct pair {
		std::string _key = '\0';
		double _value = 0.0;
	};
	pair* _arr;
	size_t _size = 0;
	size_t _capacity = 0;
public:
	Map() {}
	Map(size_t size, size_t capacity) : _size(size), _capacity(capacity) {
		_arr = new pair[_size]();
	}
	Map(const Map& other) : _size(other._size), _capacity(other._capacity) {
		_arr = new pair[_size]();
		for (size_t i = 0; i < _size; ++i) {
			_arr[i] = other._arr[i];
		}
	}
	~Map() {
		delete[] _arr;
	}
	Map& operator=(const Map& other) {
		if (this != &other) {
			return *this;
		}
		size_t max_size = std::max(_size, other._size);

		pair* new_arr = new pair[max_size];
		for (size_t i = 0; i < max_size; ++i) {
			_arr[i] = other._arr[i];
		}
	}
	double operator[](const std::string& key) {
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
			pair* new_arr = new pair[_size * 2];
			for (size_t i = 0; i < _size; ++i) {
				new_arr[i] = _arr[i];
			}
			delete[] _arr;
			_arr = new_arr;
			_capacity = _size * 2;
			_size = _size + 1;
		}
		_arr[_size] = p;
		return *this;
	}
};