#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    int money = 0;
    ~Widget();
    void change(int mon);
    void changeimpos();

private slots:
    void on_pb10_clicked();

    void on_pbC_clicked();

    void on_pbreset_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbt_clicked();

    void on_pbm_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
