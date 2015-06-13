/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef KOMIWOJAZERPLUGININTERFAC_H
#define KOMIWOJAZERPLUGININTERFAC_H

#include <QString>

//! [0]
class KomiwojazerPluginInterface
{
public:
    //! Destructor
    virtual ~KomiwojazerPluginInterface() {}
    //! Returns (short) name (for menu entry, etc.)
    virtual QString getName() const = 0;
    //! Returns long name/description (for tooltip, etc.)
    virtual QString getDescription() const = 0;
    //! Returns maximum number of places that algorithm may calculate. Zero means infinate. It is good to limit something like brute force algorithm...
    virtual unsigned int getMaxNumberOfPlaces() const = 0;
    //! Main calculating function. It tab is 2D array of cost moving from place i-th to j-th place (tab[i][j]). sorted - sorted indexes with optimal rout.
    virtual void calculate(const double ** const &_costs, unsigned int * const &_sorted, const unsigned int _size) = 0;
};


QT_BEGIN_NAMESPACE

#define KomiwojazerPluginInterface_iid "ztpr.Michal.Magda.KomiwojazerPluginInterface"

Q_DECLARE_INTERFACE(KomiwojazerPluginInterface, KomiwojazerPluginInterface_iid)
QT_END_NAMESPACE

//! [0]
#endif
