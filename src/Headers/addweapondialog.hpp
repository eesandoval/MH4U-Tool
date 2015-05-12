#ifndef ADDWEAPONDIALOG_HPP
#define ADDWEAPONDIALOG_HPP

#include <QDialog>
#include <fstream>

namespace Ui {
class addweapondialog;
}

class addweapondialog : public QDialog
{
    Q_OBJECT

public:
    explicit addweapondialog(QWidget *parent = 0);
    ~addweapondialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addweapondialog *ui;
};

#endif // ADDWEAPONDIALOG_HPP
