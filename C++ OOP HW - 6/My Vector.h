#pragma once


class Time
{
	ush _Hours;
	ush _Minutes;
	ush _Seconds;

public:

	Time();
	Time(ush second);
	Time(ush second, ush minute);
	Time(ush second, ush minute, ush hour);
	Time(const Time& other); // copy
	Time(Time&& other); // move

	void Set_Hour(ush hour);
	void Set_Minute(ush minute);
	void Set_Second(ush second);

	ush Get_Hours() { return _Hours; };
	ush Get_Minutes() { return _Minutes; };
	ush Get_Seconds() { return _Seconds; };

	friend ostream& operator<<(ostream& print, const Time& other);
	friend istream& operator>>(istream& input, Time& other);

	Time& operator=(const Time& other);
	Time& operator+=(const Time& other);
	Time& operator-=(const Time& other);

	Time& operator++();
	Time& operator++(int n);
	Time& operator--();
	Time& operator--(int n);

	bool operator>(const Time& right);
	bool operator<(const Time& right);
	bool operator>=(const Time& right);
	bool operator<=(const Time& right);

	bool operator==(const Time& right);
	bool operator!=(const Time& right);
	bool operator!();

	void operator()() { cout << _Hours << ":" << _Minutes << ":" << _Seconds << endl; }

};


//--------------------------------------



class Vector {
private:

	int* _Array = nullptr;
	size_t _Size = 0;
	size_t _Capacity = 15;

public:

	Vector() { _Array = new int[_Capacity] {}; }
	Vector(size_t capacity)
	{
		while (_Capacity < capacity) _Capacity += 15;
		_Array = new int[_Capacity] {};
	}
	Vector(const int* arr, size_t count) : Vector(count)
	{
		for (size_t n = 0; n < count; n++)
			_Array[n] = arr[n];
	}
	Vector(const Vector& other)
	{
		while (_Capacity < other._Capacity)_Capacity += 15;

		_Array = new int[_Capacity] {};

		for (size_t n = 0; n < other._Size; n++)
			_Array[_Size++] = other._Array[n];
	}
	Vector(Vector&& other)
	{
		this->_Array = other._Array;
		other._Array = nullptr;

		this->_Size = other._Size;
		other._Size = 0;

		this->_Capacity = other._Capacity;
		other._Capacity = 0;
	}

	Vector& operator+(const Vector& other)
	{

	}
	bool operator==(const Vector& other)
	{

	}
	bool operator!=(const Vector& other)
	{

	}
	Vector& operator++()
	{

	}
	Vector& operator--()
	{

	}
	Vector& operator++(int n)
	{

	}
	Vector& operator--(int n)
	{

	}
	Vector& operator[](size_t Index)
	{

	}
	Vector& operator()()
	{

	}
	friend istream& operator>>(istream& input,Vector& other) {}
	friend ostream& operator<<(ostream& print, Vector& other) {}



	int* getData() const { return _Array; }
	size_t size() const { return _Size; }
	size_t capacity() const { return _Capacity; }

	void print() const
	{
		cout << endl << "_Capacity : " << _Capacity << endl;
		cout << "_Size : " << _Size << endl;
		cout << "int Array : ";

		for (size_t i = 0; i < _Size; i++)
			cout << ' ' << _Array[i];
	}

	int& operator[](size_t index)
	{
		if (_Size != 0)
			if (index >= 0 && index < _Size)
				return _Array[index];
		assert(!"index Out of range");
	}
	int& operator()(size_t index)
	{
		if (_Size != 0)
			if (index >= 0 && index < _Size)
				return _Array[_Size - index];
		assert(!"index Out of range");
	}

	Vector& push_back(const int value)
	{
		if (_Size < _Capacity) _Array[_Size++] = value;
		else
		{
			_Capacity += 15;
			int* newArray = new int[_Capacity] {};

			for (size_t t = 0; t < _Size; t++)
				newArray[t] = _Array[t];

			newArray[_Size++] = value;

			delete[] _Array;
			_Array = newArray;
		}
		return (*this);
	}
	Vector& push_front(const int value)
	{
		if (_Size < _Capacity)
		{
			for (size_t i = 0; i < _Size; i++)
				_Array[_Size - i] = _Array[_Size - i - 1];

			_Array[0] = value;
			_Size++;
		}
		else
		{
			_Capacity += 15;
			int* newArray = new int[_Capacity] {};

			for (size_t t = 1; t <= _Size; t++)
				newArray[t] = _Array[t - 1];

			newArray[0] = value;

			delete[] _Array;
			_Array = newArray;
			_Size++;
		}
		return (*this);
	}
	Vector& pop_back()
	{
		int* newArr = new int[_Capacity] {};

		for (size_t i = 0; i < _Size - 1; i++)
			newArr[i] = _Array[i];

		delete[] _Array;
		_Array = newArr;
		_Size--;

		return (*this);
	}
	Vector& pop_front()
	{
		int* newArr = new int[_Capacity] {};

		for (size_t i = 1; i < _Size; i++)
			newArr[i - 1] = _Array[i];

		delete[] _Array;
		_Array = newArr;
		_Size--;

		return (*this);
	}

	void delete_by_index(const size_t index)
	{
		if (index > _Size) assert(!"Index Out Of Range !!!");

		int* newArr = new int[_Capacity] {};

		size_t f_index = 0;

		for (size_t a = 0; a < index; a++)
			newArr[f_index++] = _Array[a];

		for (size_t b = index + 1; b < _Size; b++)
			newArr[f_index++] = _Array[b];

		_Size = f_index;
	}
	void insert_by_index(const size_t index, const int element)
	{
		if (index > _Size)
		{
			push_back(element); return;
		}

		if (_Size < _Capacity)
		{
			int* newArray = new int[_Capacity] {};

			int f_index = 0;

			for (size_t t = 0; t < index; t++)
				newArray[f_index++] = _Array[t];

			newArray[f_index++] = element;

			for (size_t t = index; t < _Size; t++)
				newArray[f_index++] = _Array[t];

			delete[] _Array;
			_Array = newArray;
			_Size++;
		}
		else
		{
			_Capacity += 15;
			int* newArray = new int[_Capacity] {};

			int f_index = 0;

			for (size_t t = 0; t < index; t++)
				newArray[f_index++] = _Array[t];

			newArray[f_index++] = element;

			for (size_t t = index; t < _Size; t++)
				newArray[f_index++] = _Array[t];

			delete[] _Array;
			_Array = newArray;
			_Size++;
		}

	}

	size_t find(const int element)
	{
		for (size_t x = 0; x < _Size; x++)
			if (_Array[x] == element)
				return x;

		return -1;
	}
	size_t rfind(const int element)
	{
		for (size_t x = _Size - 1; x >= 0; x++)
			if (_Array[x] == element)
				return x;

		return -1;
	}

	void sort(bool reverse = false)
	{
		size_t key, j;

		if (!reverse)
		{
			for (size_t i = 1; i < _Size; i++)
			{
				key = _Array[i];
				j = i - 1;

				while (j >= 0 && _Array[j] > key)
				{
					_Array[j + 1] = _Array[j];
					j = j - 1;
				}
				_Array[j + 1] = key;
			}
		}
		else
		{
			for (size_t i = _Size - 1; i >= 1; i++)
			{
				key = _Array[i];
				j = i - 1;

				while (j >= 0 && _Array[j] > key)
				{
					_Array[j + 1] = _Array[j];
					j = j - 1;
				}
				_Array[j + 1] = key;
			}
		}
	}

	~Vector()
	{
		if (_Array != nullptr)
		{
			delete[] _Array;
			_Array = nullptr;
		}
	}

};
