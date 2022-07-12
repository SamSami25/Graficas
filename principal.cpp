#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    // Le seteo el setPixmap en el lienzo
    ui->outCuadro->setPixmap(lienzo);
    //Aceptar el Evento
    event;
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Crear un objeto color para el relleno
    QColor colorRelleno1(196,247,245);

    // Crear otro objeto color para el borde
    QColor colorBorde1(0,255,249);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde1);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno1);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Obtener Datos para la Primera Nota
    int nota1 = ui->inNota1->value();
    int altoNota1 = this->getAlto(nota1);
    int increYN1 = this->incrementoY(altoNota1);
    // Dibujar la Primera Barra
    painter.drawRect(x+50, y+50+increYN1,100,altoNota1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(191,129,158);

    // Crear otro objeto color para el borde
    QColor colorBorde(161,70,126);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Obtener Datos para la Segunda Nota
    int nota2 = ui->inNota2->value();
    int altoNota2 = this->getAlto(nota2);
    int increYN2 = this->incrementoY(altoNota2);
    // Dibujar Segunda Barra
    painter.drawRect(x+170, y+50+increYN2,100,altoNota2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(142, 134, 174);
    QColor cBordeBarra3(91, 39, 125);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Obtener Datos para la Tercera Nota
    int nota3 = ui->inNota3->value();
    int altoNota3 = this->getAlto(nota3);
    int increYN3 = this->incrementoY(altoNota3);
    // Dibujar la Tercera Barra
    painter.drawRect(x+290,y+50+increYN3,100,altoNota3);

    // Obtener datos del Promedio de las Notas
    QColor linea(91, 39, 125);
    pincel.setWidth(105);
    pincel.setColor(linea);
    pincel.setWidth(105);
    pincel.setWidthF(5);
    painter.setPen(pincel);

    float promedioNotas = (nota1 + nota2 + nota3) / 3;
    int promedio = this->getAlto(promedioNotas);

    painter.drawLine(x+50,y+450-promedio,393,y+450-promedio);

    // Ejes de "x" y "y"
    QColor ejes(91, 39, 125);
    pincel.setColor(ejes);
    painter.setPen(ejes);

    painter.drawLine(50,480,50,30);
    painter.drawLine(10,450,455,450);

    // Texto de letras "x" y "y"
    painter.setPen(Qt::black);
    painter.setFont(QFont("BubbleGum",13));
    painter.drawText(460,455,"x");
    painter.drawText(45,25,"y");

    // Obtener las divisiones de las Barras
    painter.drawText(90,472,"N1");
    painter.drawText(200,472,"N2");
    painter.drawText(300,472,"N3");

    // Obtener las divisiones entre números
    painter.setFont(QFont("Coffee Shop",19));
    // Ciclo en ciclo
    for(int i=0; i<20; i+=5){
        painter.drawText(28,392,"i");
    }

}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::incrementoY(int alto)
{
    return 400 - alto;
}

void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo Guardado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo Guardar el Archivo");
    }
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}
