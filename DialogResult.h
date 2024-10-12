#ifndef DIALOGRESULT_H
#define DIALOGRESULT_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_accept_clicked();
    void showResp();


private:
    Ui::Dialog *ui;
    QTimer *timer;


};




#endif // DIALOGRESULT_H
