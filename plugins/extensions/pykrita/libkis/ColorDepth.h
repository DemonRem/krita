/*
 *  Copyright (c) 2016 Boudewijn Rempt <boud@valdyas.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef LIBKIS_COLORDEPTH_H
#define LIBKIS_COLORDEPTH_H

#include <QObject>

#include "kritalibkis_export.h"
#include "libkis.h"

/**
 * ColorDepth
 */
class KRITALIBKIS_EXPORT ColorDepth : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ColorDepth)

    Q_PROPERTY(int depth READ depth WRITE setdepth)

public:
    explicit ColorDepth(QObject *parent = 0);
    virtual ~ColorDepth();

    int depth() const;
    void setdepth(int value);



public Q_SLOTS:



Q_SIGNALS:



private:
    struct Private;
    const Private *const d;

};

#endif // LIBKIS_COLORDEPTH_H