#pragma once
#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <iostream>

class Room {
private:
	//friend class Tourist; // Tourist имеет доступ к закрытой части Room

	int m_room_number; // повторяется
	double m_price_per_night;
	int m_number_of_beds;
	std::string m_type_room; // { "LUXURY", "COMFORT", "ECONOMY" };
public:
	Room();
	~Room();

	int get_room_number() const;
	double get_price() const;

	//2.Вывод на экран информации о комнатах.
	friend std::ostream& operator<<(std::ostream& os, const Room& r);
	//4.Добавление информации о новой комнате.
	friend std::istream& operator>>(std::istream& is, Room& r);
};

#endif // !ROOM_H_
