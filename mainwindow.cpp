#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vigenerencrypt.h"
VigenerEncrypt Vigener;
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


void MainWindow::on_Encrypt_clicked()
{
    QString alphabet = ("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    QString input = ui->Input_Text->toPlainText();
    QString key = ui->Key_Text->toPlainText();
    if(ui->ChangeLang->currentIndex()==1) alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    else alphabet = ("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    ui->Output_Text->setText(Vigener.Encrypt(alphabet,input,key));

}


void MainWindow::on_Decrypt_clicked()
{
    QString alphabet = ("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    QString input = ui->Input_Text->toPlainText();
    QString key = ui->Key_Text->toPlainText();
    if(ui->ChangeLang->currentIndex()==1) alphabet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    else alphabet = ("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ");
    ui->Output_Text->setText(Vigener.Decrypt(alphabet,input,key));
}

