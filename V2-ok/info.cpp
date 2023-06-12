#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    ui->lVertion->setText("vertion : 2.0");
    ui->lDateCration->setText("date de création : 11/05/2023");
    ui->lAuteur->setText("auteur : CLEMENCEAU EDOUARD");
}

info::~info()
{
    delete ui;
}
