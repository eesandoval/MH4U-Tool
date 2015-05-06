#ifndef DEFENSECALCULATORWINDOW_HPP
#define DEFENSECALCULATORWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class defensecalculatorwindow;
}

class defensecalculatorwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit defensecalculatorwindow(QWidget *parent = 0);
    ~defensecalculatorwindow();

private:
    Ui::defensecalculatorwindow *ui;
};

#endif // DEFENSECALCULATORWINDOW_HPP
