#ifndef TEOSTRATIMERWINDOW_HPP
#define TEOSTRATIMERWINDOW_HPP

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class teostratimerwindow;
}

class teostratimerwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teostratimerwindow(QWidget *parent = 0);
    ~teostratimerwindow();

private slots:
    void on_start_timer_clicked();

public slots:
    void timer_handler();

private:
    Ui::teostratimerwindow *ui;
    QTimer *timer;
    bool counting;
    int counter;
};

#endif // TEOSTRATIMERWINDOW_HPP
