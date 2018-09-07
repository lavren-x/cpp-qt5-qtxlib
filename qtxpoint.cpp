/*
    qTXLib, (c) E.Gaevsky, A.Legalov, 2016. Remaked by I.Kuznetsov, 2018.
    Simple cross-platform graphics library. Based on Qt.


	QTxPoint class definition file.
	This class represents a simple point on the screen.
	
*/

#include "qtxpoint.h"

QTxPoint::QTxPoint(int x, int y)
{ 
    p = new QPoint(x, y);
    X = x;
    Y = y;
}
