#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0};
    int count500{0};
    int count100{0};
    int count50{0};
    int count10{0};
    int total{0};
    void moneyCheck();
    void changeMoney(int n);
    void getChange();
    void varRest();


private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffe_clicked();

    void on_pbTea_clicked();

    void on_pbCoke_clicked();

    void on_pbReturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
