//
// Created by sunalong on 17/3/4 09:46.
// Email:466210864@qq.com
//

#ifndef CDEMO_MYWIDGET_H
#define CDEMO_MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
class MyWidget : public QWidget {
    Q_QBJECT
public:
    MyWidget(QWidget *parent = 0);

    ~MyWidget();

private:
    QPushButton *qPushButton;
    QHBoxLayout *qhBoxLayout1,*qhBoxLayout2;
    QVBoxLayout *qvBoxLayout;
    QGridLayout *qGridLayout;
    QLineEdit *qLineEdit1,*qLineEdit2,*qLineEdit3;
    QLabel *qLabel1,*qLabel2;
private slots:
    void on_clicked();
};

#endif //CDEMO_MYWIDGET_H
