#include "newsmanagementsystem.h"
#include "User.h"
#include "Image_Item.h"
#include "FileHelper.h"
#include <QMessageBox>
#include <QRegularExpression>
#include<QToolTip>
#include<QHBoxLayout>
#include<QInputDialog>
newsmanagementsystem::newsmanagementsystem(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.listWidget_2->setVisible(false);

    ui.lineEdit->setPlaceholderText("Search with title to remove a post");
    ui.lineEdit_2->setPlaceholderText("Search with title to update a post");
    ui.search_average->setPlaceholderText("Search with title to view average rate for a post");
    ui.lineEdit_5->setPlaceholderText("Search......");


    news = FileHelper::readNewsFromFile("news.txt");
    FileHelper::clearFiles("news.txt");
    categories = FileHelper::readCategories("categories.txt");
    FileHelper::clearFiles("categories.txt");
    users = FileHelper::readUsersFromFile("users.txt");
    FileHelper::clearFiles("users.txt");
    rating_map = FileHelper::ReadRatesFromFile("rates.txt");
    FileHelper::clearFiles("rates.txt");
    comments = FileHelper::ReadCommentsFromFile("comments.txt");
    FileHelper::clearFiles("comments.txt");
    setupUI();
    connectSignals();
    int ind = 0;
    QPixmap pix("D:/photos/piic (3).png");
    //pix.scaled(200, 400, Qt::KeepAspectRatio);
    for (auto i : news) {
        for (auto j : i.second) {
           
            ui.listWidget->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription())

                , QString::fromStdString(j.GetTitle()),
                QString::fromStdString(j.GetDate()),
                QString::fromStdString(j.GetCategory())
             , ui.listWidget));
            m_index[ind] = j;
            ind++;
        }
    }

    //latest_news
    int count = 0;
    auto it = news.end(); // Start at the end
    while (it != news.begin() && count < 3) {
        --it; // Move to the previous element
        date = it->first;
        for (auto j : it->second) {
            QPixmap pix1("D:/photos/piic (3).png");
                ui.listWidget_3->addItem(new Image_Item(pix1, QString::fromStdString(j.GetDescription()),
                QString::fromStdString(j.GetTitle()),
                QString::fromStdString(j.GetDate()),
                QString::fromStdString(j.GetCategory()),
                ui.listWidget_3));
        }
        ++count; // Increment the count
    }

}

void newsmanagementsystem::setupUI()
{
    // Set background images
    setPixmapToWidget(ui.background1, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.background2, "D:/photos/Picture3.png");
    setPixmapToWidget(ui.background1_2, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_14, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_19, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.background2_2, "D:/photos/Picture3.png");
    setPixmapToWidget(ui.admin, "D:/photos/userr.png");
    setPixmapToWidget(ui.label_11, "D:/photos/Picture3.png");
    setPixmapToWidget(ui.label_25, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_31, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_43, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_46, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_52, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_59, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_66, "D:/photos/Futuristic technology background.png");
    setPixmapToWidget(ui.label_38, "D:/photos/Picture3.png");
    setPixmapToWidget(ui.label_73, "D:/photos/userr.png");
    // Set icons
    setIconToWidget(ui.home_pic, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.home_pic_2, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.home_pic_3, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_2, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_3, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_4, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_5, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_6, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_7, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_8, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage_9, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.homepage, "D:/photos/home.png", QSize(30, 30));
    setIconToWidget(ui.search, "D:/photos/search-icon.png", QSize(40, 40));
    setIconToWidget(ui.search_3, "D:/photos/search-icon.png", QSize(40, 40));
    setIconToWidget(ui.user_search_2, "D:/photos/search-icon.png", QSize(40, 40));
    setIconToWidget(ui.search_4, "D:/photos/search-icon.png", QSize(40, 40));
    setIconToWidget(ui.pushButton, "C:/Users/EMAN/OneDrive/Pictures/perpi.png", QSize(40, 40));
    setIconToWidget(ui.pushButton_3, "C:/Users/EMAN/OneDrive/Pictures/perpi.png", QSize(30, 30));
    setIconToWidget(ui.pushButton_4,"D:/photos/home.png" , QSize(40, 40));
    setIconToWidget(ui.pushButton_5, "C:/Users/EMAN/OneDrive/Pictures/coom.png", QSize(30, 30));
    // Populate category dropdown
    ui.comboBox->addItem("");
    ui.comboBox->addItem("All");
    for (auto& c : categories) {
        ui.category_2->addItem(QString::fromStdString(c));
        ui.category->addItem(QString::fromStdString(c));
        ui.comboBox->addItem(QString::fromStdString(c));
    }
}

void newsmanagementsystem::connectSignals()
{
    // Connect signals
    connect(ui.login, &QPushButton::pressed, this, &newsmanagementsystem::onLoginButtonClicked);
    connect(ui.sign_up, &QPushButton::pressed, this, &newsmanagementsystem::onSignupButtonClicked);
    connect(ui.sign_up_2, &QPushButton::pressed, this, &newsmanagementsystem::onSignupButton2Clicked);
    connect(ui.add, &QPushButton::pressed, this, &newsmanagementsystem::onAddNewsClicked);
    connect(ui.home_pic, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.home_pic_2, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.home_pic_3, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.homepage_2, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.homepage_3, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.homepage_5, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.homepage_4, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.homepage_6, &QPushButton::pressed, this, &newsmanagementsystem::onHomeUserPage);
    connect(ui.homepage_7, &QPushButton::pressed, this, &newsmanagementsystem::onHomeUserPage);
    connect(ui.homepage_8, &QPushButton::pressed, this, &newsmanagementsystem::onHomeUserPage);
    connect(ui.homepage_9, &QPushButton::pressed, this, &newsmanagementsystem::onHomeUserPage);
    connect(ui.homepage, &QPushButton::pressed, this, &newsmanagementsystem::onHomePicClicked);
    connect(ui.add_post, &QPushButton::pressed, this, &newsmanagementsystem::onAddPostClicked);
    connect(ui.pushButton_4, &QPushButton::pressed, this, &newsmanagementsystem::onHomeUserPage);
    connect(ui.remove_post, &QPushButton::pressed, this, &newsmanagementsystem::onRemovePostClicked);
    connect(ui.latest_news, &QPushButton::pressed, this, &newsmanagementsystem::onLatestNewsClicked);
    connect(ui.favourites, &QPushButton::pressed, this, &newsmanagementsystem::onFavouritesClicked);
    connect(ui.search, &QPushButton::pressed, this, &newsmanagementsystem::searchToDelet);
    connect(ui.search_3, &QPushButton::pressed, this, &newsmanagementsystem::searchToUpdate);
    connect(ui.search_4, &QPushButton::pressed, this, &newsmanagementsystem::searchToAverage);
    connect(ui.user_search_2, &QPushButton::pressed, this, &newsmanagementsystem::onUserSearch);
    connect(ui.remove, &QPushButton::pressed, this, &newsmanagementsystem::onRemoveClicked);
    connect(ui.update_post, &QPushButton::pressed, this, &newsmanagementsystem::onUpdatePostClicked);
    connect(ui.update, &QPushButton::pressed, this, &newsmanagementsystem::onUpdateClicked);
    connect(ui.pushButton_2, &QPushButton::pressed, this, &newsmanagementsystem::onAddCategoryClicked);
    connect(ui.addcategory, &QPushButton::pressed, this, &newsmanagementsystem::onCategoryClicked);
    connect(ui.averagerate, &QPushButton::pressed, this, &newsmanagementsystem::onAverageRateClicked);
    connect(ui.pushButton, &QPushButton::pressed, this, &newsmanagementsystem::onAddBookmarkClicked);
    connect(ui.pushButton_3, &QPushButton::pressed, this, &newsmanagementsystem::onRemoveBookmarkClicked);
    connect(ui.pushButton_5, &QPushButton::pressed, this, &newsmanagementsystem::onCommentsClicked);
    connect(ui.trending, &QPushButton::pressed, this, &newsmanagementsystem::onTrendingClicked);
    connect(ui.ratebutton, &QPushButton::clicked, this, &newsmanagementsystem::ratePost);
    connect(ui.comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &newsmanagementsystem::onComboBoxIndexChanged);
    connect(ui.comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &newsmanagementsystem::onComboBox_3IndexChanged);
}

void newsmanagementsystem::setPixmapToWidget(QLabel* widget, const QString& filePath)
{
    QPixmap pixmap(filePath);
    if (!pixmap.isNull())
        widget->setPixmap(pixmap);
}

void newsmanagementsystem::setIconToWidget(QPushButton* widget, const QString& filePath, const QSize& size)
{
    QIcon icon(filePath);
    if (!icon.isNull()) {
        widget->setIcon(icon);
        widget->setIconSize(size);
    }
}

void newsmanagementsystem::onLoginButtonClicked()
{
    QString user_name = ui.email->text();
    QString password = ui.password->text();
    bool found = false;
    bool admin = false;
    if (user_name.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Login Failed", "Please enter User_Name and password.");
        return;
    }
    else if (user_name == "admin" && password == "123")
    {
        admin = true;
        ui.stackedWidget->setCurrentIndex(0);
    }


    else  // user 
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].GetUserName() == user_name.toStdString() && users[i].GetPassword() == password.toStdString())
            {
                found = true;
                CurrentUserIndex = i;
                CurrentUser = users[i];
                break;
            }
        }

        if (found)
        {
            ui.stackedWidget->setCurrentIndex(14);
        }

    }
    if (!found && !admin)
    {
        QMessageBox::warning(this, "Login Failed", "Invalid User_Name or password.");
    }
}

void newsmanagementsystem::onSignupButtonClicked()
{
    ui.stackedWidget->setCurrentIndex(3);
}

void newsmanagementsystem::onSignupButton2Clicked()
{
    QString username = ui.username->text();
    QString email = ui.email_2->text();
    QString password = ui.password_2->text();
    bool flag = false;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].GetEmail() == email.toStdString()) {
            flag = true;
            break;
        }
    }
    // Regular expression to validate email format
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}$)");

    // Regular expression to enforce password strength (at least 8 characters, with at least one uppercase letter, one lowercase letter, one number, and one special character)
    QRegularExpression passwordRegex(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[^\da-zA-Z]).{8,}$)");

    // Validate username, email, and password
    if (username.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Sign up Failed", "Please enter username, email, and password.");
    }
    else if (!email.contains(emailRegex)) {
        QMessageBox::warning(this, "Sign up Failed", "Please enter a valid email address.");
        ui.email_2->clear();
        ui.password_2->clear();
    }
    else if (!password.contains(passwordRegex)) {
        QMessageBox::warning(this, "Sign up Failed", "Please enter a strong password (at least 8 characters long, with at least one uppercase letter, one lowercase letter, one number, and one special character).");
        ui.password_2->clear();
    }
    else if (flag) {
        QMessageBox::warning(this, "Sign up Failed", "Account already exists.");
        ui.stackedWidget->setCurrentIndex(2);
    }
    else {
        users.push_back(User(username.toStdString(), email.toStdString(), password.toStdString()));
        ui.stackedWidget->setCurrentIndex(2);
    }
}

void newsmanagementsystem::onAddNewsClicked()
{
    QString title = ui.title->toPlainText();
    QString description = ui.description->toPlainText();
    QString category = ui.category->currentText();
    QString date = ui.date->date().toString("MM/dd/yyyy");
    if (title.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Failed to Add New Post", "Please enter Title and Description.");
    }
    else {
        for (auto i : news) {
            for (auto j : i.second) {
                if (j.GetTitle() == title.toStdString()) {
                    QMessageBox::warning(this, "Failed to Add New Post", "This Title Already Exist.");
                    return;
                }
            }
        }
        QMessageBox::information(this, "Successful Addition", "News Was Added Successfully.");
        news[date.toStdString()].push_back(News(title.toStdString(), description.toStdString(), date.toStdString(),0, category.toStdString(),0));
        ui.title->clear();
        ui.description->clear();
    }
}

void newsmanagementsystem::onHomePicClicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void newsmanagementsystem::onAddPostClicked()
{
    ui.stackedWidget->setCurrentIndex(4);
}

void newsmanagementsystem::onRemovePostClicked() {
    ui.stackedWidget->setCurrentIndex(1);
}

void newsmanagementsystem::searchToDelet() {
    QString search = ui.lineEdit->text();
    if (search.isEmpty()) {
        QMessageBox::warning(this, "Search Failed", "Please enter Title.");
    }
    else {
        for (auto i : news) {
            date = i.first;
            for (auto j : i.second) {
                deletnews++;
                if (j.GetTitle() == search.toStdString()) {
                    ui.stackedWidget->setCurrentIndex(5);
                    QString description = QString::fromStdString(j.GetDescription());
                    ui.textBrowser_2->setPlainText(description);
                    return;
                }
            }
            deletnews = -1;
        }
        QMessageBox::warning(this, "Failed Search", "This Title Not Founded.");
    }
}

void newsmanagementsystem::onRemoveClicked() {
    if (deletnews == -1) {
        QMessageBox::warning(this, "Deletion Failed", "Please Search With Title Firstly.");
    }
    else {
        news[date].erase(news[date].begin() + deletnews);
        QMessageBox::information(this, "Successful Deletion", "News Was Removed Successfully.");
        ui.textBrowser_2->clear();
        ui.lineEdit->clear();
        deletnews = -1;
    }
}

void newsmanagementsystem::onUpdatePostClicked() {
    ui.stackedWidget->setCurrentIndex(7);

}

void newsmanagementsystem::searchToUpdate() {
    QString search = ui.lineEdit_2->text();
    if (search.isEmpty()) {
        QMessageBox::warning(this, "Search Failed", "Please enter Title.");
    }
    else {
        for (auto i : news) {
            date = i.first;
            for (auto j : i.second) {
                deletnews++;
                if (j.GetTitle() == search.toStdString()) {
                    ui.stackedWidget->setCurrentIndex(6);
                    QString description = QString::fromStdString(j.GetDescription());
                    QString title = QString::fromStdString(j.GetTitle());
                    QString date = QString::fromStdString(j.GetDate());
                    QString category = QString::fromStdString(j.GetCategory());
                    ui.description_2->setPlainText(description);
                    ui.title_2->setPlainText(title);
                    ui.category_2->setCurrentText(category);
                    ui.label_51->setText(date);
                    return;
                }
            }
            deletnews = -1;
        }
        QMessageBox::warning(this, "Failed Search", "This Title Not Founded.");
    }
}

void newsmanagementsystem::onUpdateClicked() {
    QString title = ui.title_2->toPlainText();
    QString description = ui.description_2->toPlainText();
    QString category = ui.category_2->currentText();
    news[date][deletnews].SetTitle(title.toStdString());
    news[date][deletnews].SetDescription(description.toStdString());
    news[date][deletnews].SetCategory(category.toStdString());
    QMessageBox::information(this, "Successful Update", "News Was Updeted Successfully.");
}

void newsmanagementsystem::onAddCategoryClicked() {
    ui.stackedWidget->setCurrentIndex(8);
}

void newsmanagementsystem::onCategoryClicked() {
    QString new_category = ui.lineEdit_3->text();
    bool found = false;
    for (const string category : categories) {
        if (new_category== QString::fromStdString(category)) {
            found = true;
            break;
        }
    }
    if (new_category.isEmpty()) {
        QMessageBox::warning(this, "Failed to Add New Category", "Please enter Category Name.");
    }
    else if (found) {
        QMessageBox::warning(this, "Category Already Exist!", "Please enter NEW Category .");
    }
    else {
        QMessageBox::information(this, "Successful Addition", "Category Added Successfully.");
        categories.push_back(new_category.toStdString());
        ui.category->addItem(new_category);
        ui.category_2->addItem(new_category);
        ui.comboBox->addItem(new_category);
        ui.lineEdit_3->clear();
    }
}

void newsmanagementsystem::searchToAverage() {
    QString search = ui.search_average->text();
    if (search.isEmpty()) {
        QMessageBox::warning(this, "Search Failed", "Please enter Title.");
    }
    else {
        for (auto i : news) {
            for (auto j : i.second) {
                if (j.GetTitle() == search.toStdString()) {
                    double average = (j.GetRate() / j.GetNumOfRates());
                    string avr = to_string(average);
                    ui.ave_label->setText(QString::fromStdString(avr));
                    return;

                }
            }
        }
        QMessageBox::warning(this, "Failed Search", "This Title Not Founded.");
    }
}

void newsmanagementsystem::onAverageRateClicked() {
    ui.stackedWidget->setCurrentIndex(9);
}

void newsmanagementsystem::onComboBoxIndexChanged() {
    if (ui.comboBox->currentText() != "") {
        ui.listWidget->clear();
        ui.stackedWidget->setCurrentIndex(10);
        for (auto& i : news) {
            date = i.first;
            QPixmap pix("D:/photos/piic (3).png");
            if (ui.comboBox->currentText() == "All") {
                for (auto j : i.second) {
                    ui.listWidget->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription()),
                        QString::fromStdString(j.GetTitle()),
                        QString::fromStdString(j.GetDate()),
                        QString::fromStdString(j.GetCategory()),
                        ui.listWidget));

                }
            }

            else {
                for (auto j : i.second) {
                    if (ui.comboBox->currentText() == QString::fromStdString(j.GetCategory())) {
                        ui.listWidget->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription()),
                            QString::fromStdString(j.GetTitle()),
                            QString::fromStdString(j.GetDate()),
                            QString::fromStdString(j.GetCategory()),
                            ui.listWidget));
                    }
                }
            }
        }
    }
}

void newsmanagementsystem::onHomeUserPage() {
    ui.stackedWidget->setCurrentIndex(14);
}

void newsmanagementsystem::onComboBox_3IndexChanged() {
    if (ui.comboBox_3->currentText() != "") {
        ui.stackedWidget->setCurrentIndex(15);
        QPixmap pix("D:/photos/piic (3).png");
        for (auto i : news) {
            for (auto j : i.second) {

                ui.listWidget_6->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription())

                    , QString::fromStdString(j.GetTitle()),
                    QString::fromStdString(j.GetDate()),
                    QString::fromStdString(j.GetCategory())
                    , ui.listWidget_6));
            }
        }

    }
}

void newsmanagementsystem::onUserSearch() {
    int found = 0;
    if (!ui.lineEdit_5->text().isEmpty()) {
        ui.listWidget_6->clear();
        for (auto& i : news) {
            date = i.first;
            QPixmap pix("D:/photos/piic (3).png");
            if (ui.comboBox_3->currentText() == "Search With Title") {
                for (auto j : i.second) {
                    if (j.GetTitle() == ui.lineEdit_5->text().toStdString()) {
                        ui.listWidget_6->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription()),
                            QString::fromStdString(j.GetTitle()),
                            QString::fromStdString(j.GetDate()),
                            QString::fromStdString(j.GetCategory()),
                            ui.listWidget_6));
                        found = 1;
                    }
                }
            }
            else  if (ui.comboBox_3->currentText() == "Search With Date") {
                if (!news[ui.lineEdit_5->text().toStdString()].empty()) {
                    for (auto j : news[ui.lineEdit_5->text().toStdString()]) {

                        ui.listWidget_6->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription()),
                            QString::fromStdString(j.GetTitle()),
                            QString::fromStdString(j.GetDate()),
                            QString::fromStdString(j.GetCategory()),
                            ui.listWidget_6));
                        found = 1;
                    }
                }
                break;
            }
            else {
                for (auto j : i.second) {
                    string description = j.GetDescription();
                    int result = description.find(ui.lineEdit_5->text().toStdString());
                    if (result != -1) {
                        found = 1;
                        ui.listWidget_6->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription()),
                            QString::fromStdString(j.GetTitle()),
                            QString::fromStdString(j.GetDate()),
                            QString::fromStdString(j.GetCategory()),
                            ui.listWidget_6));
                    }
                }
            }
        }
    }
    else if(ui.lineEdit_5->text().isEmpty()){
        QMessageBox::warning(this, "Search Failed", "Enter a text firstly.");
        found = -1;
    }
    if (!found) {
        QPixmap pix("D:/photos/piic (3).png");
        for (auto i : news) {
            for (auto j : i.second) {

                ui.listWidget_6->addItem(new Image_Item(pix, QString::fromStdString(j.GetDescription())

                    , QString::fromStdString(j.GetTitle()),
                    QString::fromStdString(j.GetDate()),
                    QString::fromStdString(j.GetCategory())
                    , ui.listWidget_6));
            }
        }
        QMessageBox::warning(this, "Search Failed", "This Post Does not Exist.");
    }
}

void newsmanagementsystem::onLatestNewsClicked() {
    ui.stackedWidget->setCurrentIndex(11);
}

void newsmanagementsystem::onAddBookmarkClicked() {
    for (int i = 0;i < users[CurrentUserIndex].favourites.size();i++) {
        if (users[CurrentUserIndex].favourites[i].GetTitle() == m_index[ui.listWidget->currentRow()].GetTitle()) {
            QMessageBox::information(this, "Favourites", "This Post Already Was Marked.");
            return;
        }
    }
    users[CurrentUserIndex].favourites.push_back(m_index[ui.listWidget->currentRow()]);
}

void newsmanagementsystem::onRemoveBookmarkClicked() {

users[CurrentUserIndex].favourites.erase(users[CurrentUserIndex].favourites.begin() + ui.listWidget_4->currentRow());
onFavouritesClicked();

}

void newsmanagementsystem::onFavouritesClicked() {
    ui.listWidget_4->clear();
    ui.stackedWidget->setCurrentIndex(12);
    QPixmap pix1("D:/photos/piic (3).png");
    for (int i = 0;i < users[CurrentUserIndex].favourites.size();i++) {
        ui.listWidget_4->addItem(new Image_Item(pix1, QString::fromStdString(users[CurrentUserIndex].favourites[i].GetDescription())
            , QString::fromStdString(users[CurrentUserIndex].favourites[i].GetTitle()),
            QString::fromStdString(users[CurrentUserIndex].favourites[i].GetDate()),
            QString::fromStdString(users[CurrentUserIndex].favourites[i].GetCategory())
            , ui.listWidget_4));
    }
}

void newsmanagementsystem::onTrendingClicked() {
    QPixmap pix1("D:/photos/piic (3).png");
    ui.listWidget_5->clear();
    ui.stackedWidget->setCurrentIndex(13);
    for (auto i : news) {
        date = i.first;
        for (auto j : i.second) {
            double avrrate = (j.GetRate() / j.GetNumOfRates());
            string title = j.GetTitle();
            trendings.push_back({ avrrate,{date,title} });
        }
    }
    sort(trendings.begin(), trendings.end(), greater<pair<double, pair<string, string>>>());
    for (int i = 0;i < 10;i++) {
        for (auto j : news[trendings[i].second.first]) {
            if (trendings[i].second.second == j.GetTitle()) {
                ui.listWidget_5->addItem(new Image_Item(pix1, QString::fromStdString(j.GetDescription())
                    , QString::fromStdString(j.GetTitle()),
                    QString::fromStdString(j.GetDate()),
                    QString::fromStdString(j.GetCategory())
                    , ui.listWidget_5));
            }
        }
    }
}

void newsmanagementsystem::ratePost() {
    if (!rating_map[users[CurrentUserIndex].GetUserName()][m_index[ui.listWidget->currentRow()].GetTitle()]) {
        // Display a dialog or widget for rating the post
        int rating = showRatingDialog(); // Assume this function returns the user's rating (e.g., 1 to 5 stars)

        // Update the post's rating (this is just a placeholder, you'll need your own logic)
        updatePostRating(rating);

        // Provide feedback to the user (optional)
        QMessageBox::information(this, "Rating", "Thank you for rating the post!");
    }
    else
        QMessageBox::information(this, "Rated", "You have rated this post before");

}

int newsmanagementsystem::showRatingDialog() {
    // Display a dialog or widget for rating the post
    // For simplicity, let's assume the user selects a rating from 1 to 5 stars
    // You can use QInputDialog, QSlider, or custom widgets for rating
    return QInputDialog::getInt(this, "Rate Post", "Please rate the post (1-5 stars):", 1, 1, 5);
}

void newsmanagementsystem::updatePostRating(int rating) {
    // Update the post's rating based on the user's input
    int postRating = rating;
    for (auto i : news) {
        int index = 0;
        for (auto j : i.second) {
            date = m_index[ui.listWidget->currentRow()].GetDate();
            if (j.GetTitle() == m_index[ui.listWidget->currentRow()].GetTitle()) {
                news[date][index].SetNumOfRates(j.GetNumOfRates()+1);
                news[date][index].SetRate(j.GetRate() + postRating);
            }
            index++;
        }
    }
    
    rating_map[users[CurrentUserIndex].GetUserName()][m_index[ui.listWidget->currentRow()].GetTitle()] = postRating;

    // You may also update the UI to reflect the new rating

}

void newsmanagementsystem::onCommentsClicked() {
    // Create a new QListWidgetItem
    QListWidgetItem* itemm = new QListWidgetItem(ui.listWidget_2);
    QWidget* widgett = new QWidget();
    // Create a layout for the widget
    QHBoxLayout* layoutt = new QHBoxLayout(widgett);
    QFont font1;
    font1.setPointSize(18);
    QLabel* label = new QLabel("Comments");
    label->setFont(font1);
    QPushButton* back = new QPushButton();
    setIconToWidget(back, "C:/Users/EMAN/OneDrive/Pictures/bacc.png",  QSize(30, 30));
    // Add the button directly to the list widget
    back->setStyleSheet("background:rgb(179, 60, 179)");
    back->setFixedSize(41, 31);
    layoutt->addWidget(label);
    layoutt->addWidget(back);
    // Set the layout for the widget
    widgett->setLayout(layoutt);
    // Set the widget as the item widget for the QListWidgetItem
    ui.listWidget_2->setItemWidget(itemm, widgett);
    // Set a fixed size for the item
    itemm->setSizeHint(QSize(200, 50));
    QListWidgetItem* item = new QListWidgetItem(ui.listWidget_2);
   // Create a widget to hold the line edit and the button
    QWidget* widget = new QWidget();
    // Create a layout for the widget
    QHBoxLayout* layout = new QHBoxLayout(widget);
    // Create a QLineEdit
    QLineEdit* lineEdit = new QLineEdit();
    lineEdit->setPlaceholderText("Enter text here...");
    lineEdit->setStyleSheet("background:white;color:black");
    // Create a QPushButton
    QPushButton* add = new QPushButton("Add");
    add->setStyleSheet("background:rgb(179, 60, 179)");
    // Add the line edit and the button to the layout
    layout->addWidget(lineEdit);
    layout->addWidget(add);
    // Set the layout for the widget
    widget->setLayout(layout);
    // Set the widget as the item widget for the QListWidgetItem
    ui.listWidget_2->setItemWidget(item, widget);
    // Set a fixed size for the item
    item->setSizeHint(QSize(200, 50)); // Adjust the size as needed

    connect(add, &QPushButton::pressed, this, &newsmanagementsystem::addItemToListWidget);

    for (int i = 0; i < comments[m_index[ui.listWidget->currentRow()].GetTitle()].size();i++) {
        QListWidgetItem* item2 = new QListWidgetItem(ui.listWidget_2);

        // Create a widget to hold the line edit and the button
        QWidget* widget2 = new QWidget();

        // Create a layout for the widget
        QHBoxLayout* layout2 = new QHBoxLayout(widget2);

        QLabel* lable = new QLabel();
        lable->setText(QString::fromStdString(comments[m_index[ui.listWidget->currentRow()].GetTitle()][i].first));
        lable->setStyleSheet("color:rgb(179, 60, 179)");
        QLabel* lable2 = new QLabel();
        lable2->setText(QString::fromStdString(comments[m_index[ui.listWidget->currentRow()].GetTitle()][i].second));

        layout2->addWidget(lable);
        layout2->addWidget(lable2);

        // Set the layout for the widget
        widget2->setLayout(layout2);

        // Set the widget as the item widget for the QListWidgetItem
        ui.listWidget_2->setItemWidget(item2, widget2);

        // Set a fixed size for the item

        item2->setSizeHint(QSize(200, 50));
    }
    connect(back, &QPushButton::pressed, this, &newsmanagementsystem::onDisapperClicked);

    ui.listWidget_2->setVisible(true);
}

void newsmanagementsystem::ShowTheCurrentComment(QString username,QString comment) {
    QListWidgetItem* item2 = new QListWidgetItem(ui.listWidget_2);

    // Create a widget to hold the line edit and the button
    QWidget* widget2 = new QWidget();

    // Create a layout for the widget
    QHBoxLayout* layout2 = new QHBoxLayout(widget2);

    QLabel* lable = new QLabel();
    lable->setText(username);
    lable->setStyleSheet("color:rgb(179, 60, 179)");
    QLabel* lable2 = new QLabel();
    lable2->setText(comment);

    layout2->addWidget(lable);
    layout2->addWidget(lable2);

    // Set the layout for the widget
    widget2->setLayout(layout2);

    // Set the widget as the item widget for the QListWidgetItem
    ui.listWidget_2->setItemWidget(item2, widget2);

    // Set a fixed size for the item

    item2->setSizeHint(QSize(200, 50));
}

void newsmanagementsystem::onDisapperClicked() {
    ui.listWidget_2->clear();
    ui.listWidget_2->setVisible(false);
}

void newsmanagementsystem::addItemToListWidget()
{
    // Check if the sender is a QPushButton
    QPushButton* addButton = qobject_cast<QPushButton*>(sender());
    if (!addButton) {
        // Handle error: Unexpected sender type
        return;
    }

    // Get the parent widget of the button
    QWidget* widget = addButton->parentWidget();
    if (!widget) {
        // Handle error: No parent widget found
        return;
    }

    // Find the line edit within the parent widget
    QLineEdit* lineEdit = widget->findChild<QLineEdit*>();
    if (!lineEdit) {
        // Handle error: Line edit not found
        return;
    }

    // Get the text from the line edit
    QString userName = QString::fromStdString(CurrentUser.GetUserName());
    QString comment = lineEdit->text();

    // Check if the comment is empty
    if (comment.isEmpty()) {
        QMessageBox::warning(this, "Comments", "Please Enter Your Comment Firstly");
        return; // Stop further execution if comment is empty
    }

    // Add the comment to your data structure
    comments[m_index[ui.listWidget->currentRow()].GetTitle()].push_back({ userName.toStdString(), comment.toStdString() });

    // Show the newly added comment in the UI
    ShowTheCurrentComment(userName, comment);

    // Clear the text in the line edit
    lineEdit->clear();
}


newsmanagementsystem::~newsmanagementsystem() {
    FileHelper::writeNewsToFile("news.txt", news);
    FileHelper::writeCategories("categories.txt", categories);
    FileHelper::writeUsersToFile("users.txt", users);
    FileHelper::WriteRatesToFile("rates.txt", rating_map);
    FileHelper::WriteCommentsToFile("comments.txt", comments);
}



