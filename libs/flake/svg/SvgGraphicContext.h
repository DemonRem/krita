/* This file is part of the KDE project
 * Copyright (C) 2003,2005 Rob Buis <buis@kde.org>
 * Copyright (C) 2007,2009 Jan Hambrecht <jaham@gmx.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef SVGGRAPHICCONTEXT_H
#define SVGGRAPHICCONTEXT_H

#include "kritaflake_export.h"
#include <KoShapeStroke.h>
#include <QFont>
#include <QTransform>
#include <text/KoSvgTextProperties.h>

class KRITAFLAKE_EXPORT SvgGraphicsContext
{
public:
    // Fill/stroke styles
    enum StyleType {
        None,     ///< no style
        Solid,    ///< solid style
        Complex   ///< gradient or pattern style
    };

    SvgGraphicsContext();
    void workaroundClearInheritedFillProperties();

    StyleType     fillType;  ///< the current fill type
    Qt::FillRule  fillRule;  ///< the current fill rule
    QColor        fillColor; ///< the current fill color
    QString       fillId;    ///< the current fill id (used for gradient/pattern fills)

    StyleType     strokeType;///< the current stroke type
    QString       strokeId;  ///< the current stroke id (used for gradient strokes)
    KoShapeStrokeSP stroke;    ///< the current stroke

    QString filterId;       ///< the current filter id
    QString clipPathId;     ///< the current clip path id
    QString clipMaskId;     ///< the current clip mask id
    Qt::FillRule clipRule;  ///< the current clip rule
    qreal opacity;          ///< the shapes opacity

    QTransform matrix;      ///< the current transformation matrix
    QFont   font;           ///< the current font
    QStringList fontFamiliesList; ///< the full list of all the families to search glyphs in
    QColor  currentColor;   ///< the current color
    QString xmlBaseDir;     ///< the current base directory (used for loading external content)
    bool preserveWhitespace;///< preserve whitespace in element text

    QRectF currentBoundingBox; ///< the current bound box used for bounding box units
    bool   forcePercentage; ///< force parsing coordinates/length as percentages of currentBoundbox
    QTransform viewboxTransform; ///< view box transformation

    bool display;           ///< controls display of shape
    bool visible;           ///< controls visibility of the shape (inherited)
    bool isResolutionFrame;
    qreal pixelsPerInch;    ///< controls the resolution of the image raster
    qreal forcedFontSizeCoeff; ///< workaround for a Krita 3.3 odf-based files that use different resolution for font size

    QString markerStartId;
    QString markerMidId;
    QString markerEndId;

    bool autoFillMarkers;

    KoSvgTextProperties textProperties;
};

#endif // SVGGRAPHICCONTEXT_H
