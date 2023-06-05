#include "Room.h"
//-------------------------------------------------------------------------------------------------
Room::Room() {
	m_room_number = 0;
	m_price_per_night = 0.0;
	m_number_of_beds = 0;
	m_type_room = "untitled";
}
//-------------------------------------------------------------------------------------------------
Room::~Room() {

}
//-------------------------------------------------------------------------------------------------
int Room::get_room_number() const {
	return m_room_number;
}
//-------------------------------------------------------------------------------------------------
double Room::get_price() const {
	return m_price_per_night;
}
//-------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Room& r) {
	os << "type room: " << r.m_type_room << std::endl;
	os << "room number: " << r.m_room_number << std::endl;
	os << "price per night: " << r.m_price_per_night << std::endl;
	os << "number of beds: " << r.m_number_of_beds << std::endl;

	return os;
}
//-------------------------------------------------------------------------------------------------
std::istream& operator>>(std::istream& is, Room& r) {
	std::cout << "type room: ";
	getline(is >> std::ws, r.m_type_room);

	std::cout << "room number: ";
	is >> r.m_room_number;

	std::cout << "price per night: ";
	is >> r.m_price_per_night;

	std::cout << "number of beds: ";
	is >> r.m_number_of_beds;

	return is;
}
//-------------------------------------------------------------------------------------------------
