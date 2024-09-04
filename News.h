#pragma once
#include <string>
#include<iostream>
#include<ctime>
using namespace std;
class News
{
private:
    string Title, Description, Category;
    string Date;
    double Rate;
    int NumberOfPeople=1;
public:

    News();
    News(string Title, string Description, string Date, float Rate, string Category, int NumberOfPeople);
    News(string Title, string Description, string Date, float Rate, string Category);
    News(string Title, string Description, string Date, string Category);
    friend ostream& operator<<(ostream& os, News& news);
    friend istream& operator>>(istream& is, News& news);


    // Setters
    void SetTitle(string Title);
    void SetDescription(string Description);
    void SetDate(string Date);
    void SetRate(float Rate);
    void SetCategory(string Category);
    void SetNumOfRates(int NumberOfPeople);

    // Getters
    string GetTitle();
    string GetDescription();
    string GetDate();
    string GetCategory();
    float GetRate();
    int GetNumOfRates();

    //print info
    void PrintInfo(News news);

};



