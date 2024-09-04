#pragma once
#include "User.h"
using namespace std;

User::User() {

}
User::User(string user_name, string email, string password) {
	this->user_name = user_name;
	this->password = password;
	this->email = email;
}
User::User(const string user_name, const string email, const string password, vector<News> favourites) {
	this->user_name = user_name;
	this->password = password;
	this->email = email;
	this->favourites = favourites;
}
void User::SetUserName(string user_name) {
	this->user_name = user_name;
}
void User::SetPassword(string password) {
	this->password = password;
}
void User::SetEmail(string email) {
	this->email = email;
}
void User::SetFavourites(vector<News>& favourites) {
	this->favourites = favourites;
}
string User::GetUserName() {
	return user_name;
}
string User::GetPassword() {
	return password;
}
string User::GetEmail() {
	return email;
}
vector<News> User::GetFavourites() {
	return favourites;
}
std::ostream& operator<<(std::ostream& os, User& user) {
	// Serialize user data to the output stream
	os << user.user_name << "|" << user.password << "|" << user.email << "|";
	for (auto& news : user.favourites) {
		os << news.GetTitle() << "|" << news.GetDescription() << "|" << news.GetDate() << "|"
			<< news.GetRate() << "|" << news.GetCategory() << "|";
	}
	return os;
}

std::istream& operator>>(std::istream& is, User& user) {
	// Deserialize user data from the input stream
	std::getline(is, user.user_name, '|');
	std::getline(is, user.password, '|');
	std::getline(is, user.email, '|');

	user.favourites.clear(); // Clear existing favorites

	// Read favorite news data
	std::string title, description, date, category;
	float rate;
	while (std::getline(is, title, '|')) {
		std::getline(is, description, '|');
		std::getline(is, date, '|');
		std::string rateStr;
		std::getline(is, rateStr, '|');
		rate = std::stof(rateStr);
		std::getline(is, category, '|');

		user.favourites.push_back(News(title, description, date, rate, category));
	}

	return is;
}





