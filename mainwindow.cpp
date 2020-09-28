#include "mainwindow.h"
#include "QDebug"
#include "QInputDialog"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

// получить k-ый бит числа
unsigned getKBit(unsigned n, unsigned k) {
  unsigned res = (n >> k);

  return res & 1;
}

// установить/снять k-ый бит числа
unsigned setUnsetKBit(unsigned n, unsigned k) {
  unsigned m = 1 << k;

  return n ^ m;
}

// вывести k-ый бит числа
void MainWindow::on_calculateButton_clicked() {
  bool ok;

  unsigned n = ui->numberLineEdit->text().toInt(&ok, 2);
  if (!ok) {
    qDebug() << "cannot convert to uint";
    return;
  }

  unsigned k = ui->kLineEdit->text().toInt();

  unsigned ress = getKBit(n, k);

  ui->responseLineEdit->setText(QString::number(ress));
}

// вывести число с измененным k-м битом
void MainWindow::on_setUnsetButton_clicked() {
  bool ok;

  unsigned n = ui->numberLineEdit->text().toInt(&ok, 2);
  if (!ok) {
    qDebug() << "cannot convert to uint";
    return;
  }

  unsigned k = ui->kLineEdit->text().toInt();

  unsigned ress = setUnsetKBit(n, k);

  ui->responseLineEdit->setText(QString::number(ress, 2));
}

// Обнуление младших k бит числа
void MainWindow::on_setZeroButton_clicked() {
  bool ok;

  unsigned n = ui->numberLineEdit->text().toUInt(&ok, 2);
  if (!ok) {
    qDebug() << "cannot convert to uint";
    return;
  }

  unsigned k = ui->kLineEdit->text().toUInt();
  unsigned res = (n >> k) << k;

  ui->responseLineEdit->setText(QString::number(res,2));
}

// смена мест i-, j- ых битов в числе
void MainWindow::on_swapButton_clicked() {
  bool ok;

  unsigned num = ui->numberLineEdit->text().toUInt(&ok, 2);
  if (!ok) {
    qDebug() << "cannot convert to uint";
    return;
  }

  unsigned i = QInputDialog::getInt(this, QString::fromUtf8("i бит"),
                                    QString::fromUtf8("Введите i бит"), 0.00,
                                    -10000, 10000, 3);
  unsigned iValue = getKBit(num, i);

  unsigned j = QInputDialog::getInt(this, QString::fromUtf8("j бит"),
                                    QString::fromUtf8("Введите j бит"), 0.00,
                                    -10000, 10000, 3);
  unsigned jValue = getKBit(num, j);

  unsigned res = num;

  if (jValue != iValue) {
    unsigned ress = setUnsetKBit(num, i);
    res = setUnsetKBit(ress, j);
  }

  ui->responseLineEdit->setText(QString::number(res, 2));
}
