#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QInputDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned getKBit(unsigned n, unsigned k){
    unsigned res = (n>>k);
    unsigned ress = res & 1;
    return ress;
}


void MainWindow::on_goButton_clicked()
{
    QString num = ui->numberLineEdit->text();
    unsigned n = num.toInt();
    unsigned k = ui->kLineEdit->text().toInt();
    unsigned ress = getKBit(n,k);

    ui->responseLineEdit->setText(QString::number(ress));
}

void MainWindow::on_goButton_4_clicked()
{
    QString num = ui->numberLineEdit->text();
    unsigned n = num.toInt();
    unsigned k = ui->kLineEdit->text().toInt();
    unsigned res = (n>>k)<<k;

    ui->responseLineEdit->setText(QString::number(res));
}


unsigned setUnsetKBit(unsigned n, unsigned k){
    unsigned m = 1 << k;

    unsigned ress = n^m;
    return ress;
}
// установка снятие бита
void MainWindow::on_goButton_2_clicked()
{
    QString num = ui->numberLineEdit->text();
    unsigned n = num.toInt();
    unsigned k = ui->kLineEdit->text().toInt();

    unsigned ress = setUnsetKBit(n, k);
    ui->responseLineEdit->setText(QString::number(ress));
}

void MainWindow::on_goButton_3_clicked()
{
     unsigned num = ui->numberLineEdit->text().toInt();
    unsigned i = QInputDialog::getInt(this,
                              QString::fromUtf8("i бит"),
                              QString::fromUtf8("Введите i бит"),
                              0.00, -10000, 10000, 3);

    unsigned iValue = getKBit(num, i);

    unsigned j = QInputDialog::getInt(this,
                              QString::fromUtf8("j бит"),
                              QString::fromUtf8("Введите j бит"),
                              0.00, -10000, 10000, 3);
    unsigned jValue = getKBit(num, j);

    unsigned res = num;
    //if (jValue != iValue){
            unsigned ress = setUnsetKBit(num, i);
            res = setUnsetKBit(ress, j);
   // }

    ui->responseLineEdit->setText(QString::number(res));

}
