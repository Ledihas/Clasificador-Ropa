#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>
#include <QBuffer>
#include <QHttpMultiPart>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_load_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir Imagen", "", "Images (*.png *.jpg *.bmp *.jpeg)");

    if (!fileName.isEmpty()) {
        image.load(fileName); // Cargar la imagen en un objeto QImage
        ui->label_2->setPixmap(QPixmap::fromImage(image));
        // Convertir a escala de grises y redimensionar a 32 x 32
        if (image.size() != QSize(32, 32)) {
            image = image.scaled(32, 32); // Redimensionar a 32 x 32 píxeles
        }

        // Convertir a escala de grises si es necesario (opcional)
        if (image.format() != QImage::Format_Grayscale8) {
            image = image.convertToFormat(QImage::Format_Grayscale8);
        }


        ui->label->setText("Image Cargada" + fileName);
    }
}


void MainWindow::on_send_button_clicked()
{
    if (image.isNull()) {
        qDebug() << "No hay imagen cargada.";
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request(QUrl("http://127.0.0.1:5000/predict"));

    // Preparar los datos de la imagen para enviarlos como multipart/form-data
    QByteArray byteArray;

    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);

    image.save(&buffer, "PNG"); // Guardar la imagen en el buffer como PNG

    // Enviar la solicitud POST con los datos de la imagen
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart imagePart;

    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"image.png\""));

    imagePart.setBody(byteArray);

    multiPart->append(imagePart);

    // Realizar la solicitud POST
    QNetworkReply *reply = manager->post(request, multiPart);

    connect(reply, &QNetworkReply::finished, [reply, multiPart, this]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();  // Aquí se llama a readAll() en el reply
            // Procesar JSON y mostrar resultado en resultLabel
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            if (jsonResponse.isObject()) {
                QJsonObject jsonObj = jsonResponse.object();
                int predictedClass = jsonObj["predicted_class"].toInt();
                QString clases[10] = {"camiseta", "pantalon", "pullover", "vestido", "capa",
                                    "sandalia", "camisa", "zapatilla deportiva", "bolsa", "botín"};


                QString resultText =  clases[predictedClass];    //QString("Predicción: Clase %1").arg(predictedClass);
                ui->label->setText(resultText);
            }
        } else {
            qDebug() << "Error:" << reply->errorString();
            ui->label->setText("Error en la prediccion el mio");
        }
        reply->deleteLater(); // Eliminar el objeto reply para evitar fugas de memoria
        multiPart->deleteLater(); // Eliminar el multipart después del envío
    });

}


void MainWindow::on_pushButton_clicked()
{
    close();
}

