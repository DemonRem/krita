/*
 *  Copyright (c) 2017 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KISMASKINGBRUSHOPTIONPROPERTIES_H
#define KISMASKINGBRUSHOPTIONPROPERTIES_H

#include "kritapaintop_export.h"
#include <kis_types.h>

class KisBrush;
typedef KisSharedPtr<KisBrush> KisBrushSP;

struct PAINTOP_EXPORT KisMaskingBrushOptionProperties
{
    bool isEnabled = false;
    KisBrushSP brush;

    void write(KisPropertiesConfiguration *setting) const;
    void read(const KisPropertiesConfiguration *setting);
};

#endif // KISMASKINGBRUSHOPTIONPROPERTIES_H
