#pragma once
#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<iterator>
#include<queue>
#include<stack>
#include <climits>
#include <QtWidgets/QMainWindow>
#include<QMovie>
#include<QThread>
#include "ui_newsmanagementsystem.h"
#include"User.h"
class newsmanagementsystem : public QMainWindow
{
    Q_OBJECT

public:
    newsmanagementsystem(QWidget* parent = nullptr);
    ~newsmanagementsystem();
private slots:
    void onLoginButtonClicked();
    void onSignupButtonClicked();
    void onSignupButton2Clicked();
    void onAddNewsClicked();
    void onHomePicClicked();
    void onAddPostClicked();
    void onRemovePostClicked();
    void searchToDelet();
    void onRemoveClicked();
    void onUpdatePostClicked();
    void searchToUpdate();
    void onUpdateClicked();
    void onAddCategoryClicked();
    void onCategoryClicked();
    void searchToAverage();
    void onAverageRateClicked();
    void onComboBoxIndexChanged();
    void onUserSearch();
    void onHomeUserPage();
    void onLatestNewsClicked();
    void onAddBookmarkClicked();
    void onFavouritesClicked();
    void onRemoveBookmarkClicked();
    void onTrendingClicked();
    void onComboBox_3IndexChanged();
    void ratePost();
    void onCommentsClicked();
    void onDisapperClicked();
    void addItemToListWidget();
    void ShowTheCurrentComment(QString username,QString comment);

private:
    unordered_map <int, News> m_index;
    string date;
    User CurrentUser;
    int CurrentUserIndex;
    int deletnews = -1;
    list<string> categories;
    unordered_map<string, unordered_map<string,int>>rating_map;
    unordered_map<string, vector<News>>news;
    vector<User >users;
    vector<pair<double, pair<string, string>>>trendings;
    unordered_map<string, vector<pair<string, string>>> comments;
    void setupUI();
    void connectSignals();
    int showRatingDialog();
    void updatePostRating(int rating);
    void setPixmapToWidget(QLabel* widget, const QString& filePath);
    void setIconToWidget(QPushButton* widget, const QString& filePath, const QSize& size);
public:
    Ui::newsmanagementsystemClass ui;
};
