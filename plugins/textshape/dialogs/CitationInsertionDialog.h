/* This file is part of the KDE project
 * Copyright (C) 2011 Smit Patel <smitpatel24@gmail.com>
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
#ifndef CITATIONINSERTIONDIALOG_H
#define CITATIONINSERTIONDIALOG_H

#include "ui_CitationInsertionDialog.h"
#include <KoListStyle.h>
#include <KoTextEditor.h>
#include <QTextBlock>


class TextTool;
class KoStyleManager;
class KoInlineCite;

class CitationInsertionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CitationInsertionDialog(KoTextEditor *editor ,QWidget *parent = 0);
    KoInlineCite *toCite();                 //returns cite with values filled from Insertion form
    void fillValuesFrom(KoInlineCite *cite);        //fills form with values in cite

public slots:
    void setStyleManager(KoStyleManager *sm);
    void insert();
    void selectionChangedFromExistingCites();

signals:
    void doneWithFocus();

private:
    Ui::CitationInsertionDialog dialog;
    KoStyleManager *m_styleManager;
    bool m_blockSignals;
    QTextBlock m_currentBlock;
    KoTextEditor *m_editor;
    QMap<QString, KoInlineCite*> m_cites;
};

#endif // CITATIONBIBLIOGRAPHYDIALOG_H
