#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    ui->lVersion->setText("Version : 4.0");
    ui->lDateCreation->setText("Date de création : 29/05/2023");
    ui->lAuteur->setText("Auteur : CLEMENCEAU Edouard/DARRIGADE Lucas");
    ui->lMiseAJour->setText("Dernière Mise à jour : 05/06/2023");
    ui->lInformations->setText("Informations sur l'application");
}

info::~info()
{
    delete ui;
}
