#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QPen>

#include "acerca.h"

#define VERSION "0.2"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:

    void on_actionGuardar_triggered();
    void on_inNota1_valueChanged(int arg1);
    void on_inNota2_valueChanged(int arg1);
    void on_inNota3_valueChanged(int arg1);

    void on_actionAcerca_de_triggered();

protected:

    void paintEvent(QPaintEvent *event) override;

private:

    Ui::Principal *ui;
    // Objeto que permite realizar gráficos >> lienzo donde vaos a dibujar
    QPixmap lienzo;

    void dibujar();
    int getAlto(int valor);
    int incrementoY(int alto);

};
#endif // PRINCIPAL_H
