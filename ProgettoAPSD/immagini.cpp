#include "immagini.h"

immagini::immagini()
{
    immagine.resize(10);
    int dime = 80;
    for(int i = 0; i < 10; i++) {
        immagine[i] = QPixmap(":/Resources/Immagini/img" + QString::number(i) + ".png").scaled(dime, dime, Qt::AspectRatioMode());
    }
}

QVector<QPixmap> immagini::getImmagine() const {
    return immagine;
}
