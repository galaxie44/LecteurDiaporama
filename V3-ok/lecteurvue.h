#ifndef LECTEURVUE_H
#define LECTEURVUE_H
#include "image.h"
#include <QMainWindow>
#include "info.h"
#include "vit.h"
#include <vector>
#include <QTimer>

typedef vector<Image*> Diaporama;   // Structure de données contenant les infos sur les images

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class lecteurVue : public QMainWindow
{
    Q_OBJECT

public:    
    enum Mode {automatique,manuel};
    enum categorieImage {animal,personne,tous};
    categorieImage imageCategorieCourant;
    Mode etat;
    int compteur=0;
    QTimer timer;
    int vitesse_defilement=2;

    void avancer(int);             // incrémente _posImageCourante, modulo nbImages()
    void reculer(int);             // décrémente _posImageCourante, modulo nbImages()
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    unsigned int nbImages();    // affiche la taille de _diaporama
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    unsigned int numDiaporamaCourant();
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();
    void lancer();

public slots:
    void lancerDiaporama();
    void av();//avancer
    void rec();//reculer
    void arreterDiaporama();
    void toutFermer();
    void aide();
    void chargerdiapo1();
    void enleverdiapo1();
    void defile();


private:
    Ui::lecteurVue *ui;

    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */

private:
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete


};
#endif // LECTEURVUE_H
