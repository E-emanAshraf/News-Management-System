#pragma once
#include"News.h"
#include <string>
#include<iostream>
#include<fstream>
#include<unordered_map>
using namespace std;
class User
{
private:
	string user_name, password, email;
public:
	User();
	User(string user_name, string email, string password);
	User(const string user_name, const string email, const string password, vector<News> favourites);
	friend ostream& operator<<(ostream& os, User& users);
	friend istream& operator>>(istream& is, User& users);


	//setters
	void SetUserName(string user_name);
	void SetPassword(string password);
	void SetEmail(string email);
	void SetFavourites(vector<News>& favourites);

	//getters
	string GetUserName();
	string GetPassword();
	string GetEmail();
	vector<News> GetFavourites();
	

	vector<News>favourites;
};

