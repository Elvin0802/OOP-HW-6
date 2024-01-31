#pragma once

Time::Time()
{
	_Hours = 0;
	_Minutes = 0;
	_Seconds = 0;
}
Time::Time(ush second) : Time()
{
	Set_Second(second);
}
Time::Time(ush second, ush minute) : Time(second)
{
	Set_Minute(minute);
}
Time::Time(ush second, ush minute, ush hour) : Time(second, minute)
{
	Set_Hour(hour);
}
Time::Time(const Time& other)
{
	this->Set_Second(other._Seconds);
	this->Set_Minute(other._Minutes);
	this->Set_Hour(other._Hours);
}
Time::Time(Time&& other)
{
	this->_Seconds = other._Seconds;
	other._Seconds = 0;

	this->_Minutes = other._Minutes;
	other._Minutes = 0;

	this->_Hours = other._Hours;
	other._Hours = 0;
}

void Time::Set_Hour(ush hour)
{
	_Hours = hour;
}
void Time::Set_Minute(ush minute)
{
	if (minute < 60)_Minutes = minute;
	else assert(!"Deqiqe 60 -dan Kichik Olmalidir !!!");
}
void Time::Set_Second(ush second)
{
	if (second < 60) _Seconds = second;
	else assert(!"Saniye 60 -dan Kichik Olmalidir !!!");
}

ostream& operator<<(ostream& print, const Time& other)
{
	print << other._Hours << ":" << other._Minutes << ":" << other._Seconds << endl;
	return print;
}
istream& operator>>(istream& input, Time& other)
{
	input >> other._Hours >> other._Minutes >> other._Seconds;
	return input;
}

Time& Time::operator=(const Time& other)
{
	this->Set_Second(other._Seconds);
	this->Set_Minute(other._Minutes);
	this->Set_Hour(other._Hours);

	return (*this);
}
Time& Time::operator+=(const Time& other)
{
	if (_Seconds + other._Seconds < 60)
		this->Set_Second(_Seconds + other._Seconds);
	if (_Minutes + other._Minutes < 60)
		this->Set_Minute(_Minutes + other._Minutes);

	this->Set_Hour(_Hours + other._Hours);

	return (*this);
}
Time& Time::operator-=(const Time& other)
{
	if (_Seconds - other._Seconds > 0)
		this->Set_Second(_Seconds - other._Seconds);
	if (_Minutes - other._Minutes > 0)
		this->Set_Minute(_Minutes + other._Minutes);
	if (_Hours - other._Hours > 0)
		this->Set_Hour(_Hours - other._Hours);

	return (*this);
}

Time& Time::operator++() {
	this->_Seconds++; return (*this);
}
Time& Time::operator++(int n) {
	Time newTime = (*this);
	this->_Seconds++; return newTime;
}
Time& Time::operator--() {
	this->_Seconds--; return (*this);
}
Time& Time::operator--(int n) {
	Time newTime = (*this);
	this->_Seconds--; return newTime;
}

bool Time::operator>(const Time& right)
{
	if (_Hours > right._Hours) return true;
	else return false;
}
bool Time::operator<(const Time& right)
{
	if (_Hours < right._Hours) return true;
	else return false;
}
bool Time::operator>=(const Time& right)
{
	if (_Hours >= right._Hours) return true;
	else return false;
}
bool Time::operator<=(const Time& right)
{
	if (_Hours <= right._Hours) return true;
	else return false;
}

bool Time::operator==(const Time& right)
{
	if (_Hours == right._Hours && _Minutes == right._Minutes && _Seconds == right._Seconds)
		return true;
	else return false;
}
bool Time::operator!=(const Time& right)
{
	if (_Hours == right._Hours && _Minutes == right._Minutes && _Seconds == right._Seconds)
		return false;
	else return true;
}
bool Time::operator!()
{
	if (_Hours == 0 && _Minutes == 0 && _Seconds == 0)
		return true;
	else return false;
}


// ------------------------------------------------------------------------------------------------