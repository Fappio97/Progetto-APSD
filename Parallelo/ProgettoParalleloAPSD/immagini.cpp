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


#include "immagini.h"

Immagini::Immagini()
{
    immagini.resize(10);
    for(int i = 0; i < 10; ++i)
        immagini[i] = QPixmap(":/Resources/Immagini/img" + QString::number(i) + ".png").scaled(dimensioneCelle, dimensioneCelle, Qt::AspectRatioMode());
}

Immagini::~Immagini() {
    immagini.clear();
}

QVector<QPixmap> Immagini::getImmagini() const {
    return immagini;
}
