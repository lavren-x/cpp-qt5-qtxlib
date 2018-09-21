/*
    QTXLib, (c) E.Gaevsky, A.Legalov, 2016. Remaked by I.Kuznetsov, 2018.
    Simple cross-platform graphics library. Based on Qt.


	QTxPoint class definition file.
	This class represents a simple point on the screen.
	
*/

#ifndef QTXPOINT_H
#define QTXPOINT_H

#include <QPoint>
#include "qtxcnt.h"

class QTXLIBSHARED_EXPORT QTxPoint
{
public:
    QTxPoint(int x, int y);
    QPoint* p;
    int X, Y;
};

#endif
