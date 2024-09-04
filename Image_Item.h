#ifndef IMAGE_ITEM_H
#define IMAGE_ITEM_H

#include <QObject>
#include <QWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include "newsmanagementsystem.h"
#include<QStackedWidget>

class Image_Item :public QListWidgetItem {
public:
    Image_Item(const QPixmap& image, const QString& Description, const QString& title, const QString& Date, const QString& Category, QListWidget* parent = nullptr);
};

#endif // IMAGE_ITEM_H
