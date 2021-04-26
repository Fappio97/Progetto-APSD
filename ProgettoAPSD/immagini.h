#ifndef IMMAGINI_H
#define IMMAGINI_H

#include <QPixmap>
#include <QVector>

class immagini
{
    QVector<QPixmap> immagine;
public:
    immagini();

    QVector<QPixmap> getImmagine() const;
};

#endif // IMMAGINI_H
