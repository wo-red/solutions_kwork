#include "Tourist.h"
//-------------------------------------------------------------------------------------------------
Tourist::Tourist() {
	m_lastname = "untitled";
	m_firstname = "untitled";
	m_room_number = 0;
	m_check_in_date = "untitled";
	m_number_of_nights = 0;
}
//-------------------------------------------------------------------------------------------------
Tourist::~Tourist() {

}
//-------------------------------------------------------------------------------------------------
std::string Tourist::get_lastname() const {
	return m_lastname;
}
//-------------------------------------------------------------------------------------------------
std::string Tourist::get_firstname() const {
	return m_firstname;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Tourist& t) {
	os << "lastname: " << t.m_lastname << std::endl;
	os << "firstname: " << t.m_firstname << std::endl;
	os << "room number: " << t.m_room_number << std::endl;
	os << "check-in date: " << t.m_check_in_date << std::endl;
	os << "number_of_nights: " << t.m_number_of_nights << std::endl;

	return os;
}
//-------------------------------------------------------------------------------------------------
std::istream& operator>>(std::istream& is, Tourist& t) {
	std::cout << "lastname: ";
	getline(is >> std::ws, t.m_lastname);

	std::cout << "firstname: ";
	getline(is >> std::ws, t.m_firstname);

	std::cout << "room_number: ";
	is >> t.m_room_number; // добавить проверку на то, существует ли комната

	std::cout << "check-in date: ";
	getline(is >> std::ws, t.m_check_in_date); // добавить проверку на то, существует ли дата

	std::cout << "number_of_nights: ";
	is >> t.m_number_of_nights;

	return is;
}
//-------------------------------------------------------------------------------------------------

