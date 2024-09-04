#include "News.h"
using namespace std;
News::News()
{

}

News::News(string Title, string Description, string Date, float Rate, string Category)
{
    this->Title = Title;
    this->Description = Description;
    this->Date = Date;
    this->Rate = Rate;
    this->Category = Category;
}

News::News(string Title, string Description, string Date, float Rate, string Category,int NumberOfPeople)
{
    this->Title = Title;
    this->Description = Description;
    this->Date = Date;
    this->Rate = Rate;
    this->Category = Category;
    this->NumberOfPeople = NumberOfPeople;
}

News::News(string Title, string Description, string Date, string Category)
{
    this->Title = Title;
    this->Description = Description;
    this->Date = Date;
    this->Category = Category;

}
void News::SetTitle(string title)
{
    this->Title = title;
}
string News::GetTitle() {
    return Title;
}
void News::SetDescription(string Description) {
    this->Description = Description;
}
string News::GetDescription() {
    return Description;
}
void News::SetDate(string Date) {
    this->Date = Date;
}
string News::GetDate() {
    return Date;
}
void News::SetRate(float Rate) {
    this->Rate = Rate;
}
float News::GetRate() {
    return Rate;
}
void News::SetCategory(string Category) {
    this->Category = Category;
}
string News::GetCategory() {
    return Category;
}
void News::SetNumOfRates(int NumberOfPeople) {
    this->NumberOfPeople = NumberOfPeople;
}
int News::GetNumOfRates() {
    return NumberOfPeople;
}
void News::PrintInfo(News news) {
    cout << "Title: " << news.GetTitle() << "\n";
    cout << "Description: " << news.GetDescription() << "\n";
    cout << "Date: " << news.GetDate() << "\n";
    cout << "Rate: " << news.GetRate() << "\n";
    cout << "Category: " << news.GetCategory() << "\n";
    cout << "***********\n";
}
ostream& operator<<(ostream& os, News& news) {
    os << news.GetTitle() << "|" << news.GetDescription() << "|" << news.GetDate() << "|" << news.GetRate() << "|" << news.GetCategory()<<"|"<<news.GetNumOfRates();
    return os;
}
istream& operator>>(istream& is, News& news) {
    string title, description, date, category;
    double rate;
    int numberofpeople;
    // Read the title, description, date, rate, category and numberofpeoples from the stream
    getline(is, title, '|');
    getline(is, description, '|');
    getline(is, date, '|');
    is >> rate;  // Assuming rate is followed by a shbak
    is.ignore(); // Ignore the comma after rate
    getline(is, category,'|'); // Read category until end of line
    is >> numberofpeople;

    // Set the values to the News object
    news.SetTitle(title);
    news.SetDescription(description);
    news.SetDate(date);
    news.SetRate(rate);
    news.SetCategory(category);
    news.SetNumOfRates(numberofpeople);
    return is;
}

