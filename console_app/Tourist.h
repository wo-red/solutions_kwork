#pragma once
#ifndef TOURIST_H_
#define TOURIST_H_

#include <string>
#include <iostream>

#include "Room.h"

class Tourist {
private:
	std::string m_lastname;
	std::string m_firstname;
	int m_room_number; // повторяется
	std::string m_check_in_date;
	int m_number_of_nights;

public:
	Tourist();
	~Tourist();

	std::string get_lastname() const;
	std::string get_firstname() const;

	//1.Вывод на экран информации о туристах.
	friend std::ostream& operator<<(std::ostream& os, const Tourist& t);
	//3.Добавление информации о новом туристе.
	friend std::istream& operator>>(std::istream& is, Tourist& t);
};

#endif // !TOURIST_H_
