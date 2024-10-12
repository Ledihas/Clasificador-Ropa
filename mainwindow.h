#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString returnResp();
    QString DefinitiveResp;
    void recived();




private slots:
    void on_load_button_clicked();

    void on_send_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage image; // Para almacenar la imagen cargada

};




#endif // MAINWINDOW_H
