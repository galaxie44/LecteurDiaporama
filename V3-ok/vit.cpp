#include "vit.h"
#include "ui_vit.h"

vit::vit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vit)
{
    ui->setupUi(this);
}

vit::~vit()
{
    delete ui;
}

void vit::setSpine(int valeur) //Affiche la valeur actuelle de la vitesse
{
    ui->sVit->setValue(valeur);
}

int vit::valueSpine() //Récupérer la valeur de la vitesse saisie par l'utilisateur
{
    return ui->sVit->value();
}
