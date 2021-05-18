/*
This file is part of Terreno.

Terreno is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Terreno is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Terreno.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef IMMAGINI_H
#define IMMAGINI_H

#include <QPixmap>
#include <QVector>

const int dimensioneCelle = 200;

class Immagini
{
    QVector<QPixmap> immagini;
public:
    Immagini();
    ~Immagini();

    QVector<QPixmap> getImmagini() const;
};

#endif // IMMAGINI_H
