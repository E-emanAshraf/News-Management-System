#include "Image_Item.h"
#include <QHBoxLayout>
#include <QLabel>
#include<QTextBrowser>
#include<QPushbutton>


Image_Item::Image_Item(const QPixmap& image, const QString& Description,const QString& title, const QString& Date, const QString& Category, QListWidget* parent)
    : QListWidgetItem(parent) {
    QHBoxLayout* layout = new QHBoxLayout();

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    layout->addWidget(imageLabel);

    QFont font1;
    font1.setPointSize(14);

    QTextBrowser* titleBrowser = new QTextBrowser(imageLabel);
    titleBrowser->setText(title);
    titleBrowser->setAlignment(Qt::AlignCenter);
    titleBrowser->setGeometry(0, 350, 281, 251); // Adjust the geometry as needed
    titleBrowser->setAttribute(Qt::WA_TranslucentBackground); // Enable transparent background
    titleBrowser->setStyleSheet("border: none; background-color: rgba(255, 255, 255, 150); color:  black;");


    QTextBrowser* descriptionBrowser = new QTextBrowser(imageLabel);
    titleBrowser->setFont(font1);
    descriptionBrowser->setText(Description);
    descriptionBrowser->setAlignment(Qt::AlignCenter);
    descriptionBrowser->setGeometry(300, 350, 291, 190); // Adjust the geometry as needed
    descriptionBrowser->setAttribute(Qt::WA_TranslucentBackground); // Enable transparent background
    descriptionBrowser->setStyleSheet("border: none;background-color: rgba(255, 255, 255, 150); color:  black;");


    QFont font2;
    font2.setPointSize(9);
    QLabel* DateLabel = new QLabel(Date, imageLabel); // Setting the imageLabel as the parent
    DateLabel->setFont(font2);
    DateLabel->setAlignment(Qt::AlignCenter);
    DateLabel->setStyleSheet("color:  black; background-color: white;"); // Set font color to black and background to white
    DateLabel->setGeometry(160, 30, 121, 31); // Adjust the geometry as needed
    DateLabel->setAttribute(Qt::WA_TranslucentBackground); // Enable transparent background


    QLabel* CategoryLabel = new QLabel(Category, imageLabel); // Setting the imageLabel as the parent
    CategoryLabel->setFont(font2);
    CategoryLabel->setAlignment(Qt::AlignCenter);
    CategoryLabel->setStyleSheet("color: black; background-color: white;"); // Set font color to black and background to white
    CategoryLabel->setGeometry(10, 290, 200, 60); // Adjust the geometry as needed
    CategoryLabel->setAttribute(Qt::WA_TranslucentBackground); // Enable transparent background



    QWidget* widget = new QWidget();
    widget->setLayout(layout);
    setSizeHint(widget->sizeHint());
    parent->setItemWidget(this, widget);
}

