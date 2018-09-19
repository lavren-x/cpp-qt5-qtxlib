/*
    qTXLib, (c) E.Gaevsky, A.Legalov, 2016. Remaked by I.Kuznetsov, 2018.
    Simple cross-platform graphics library. Based on Qt.


    This file contains definition of txXXXXXX wrapper functions to provide end-user communication.
	
*/

#ifndef QTXWRAPPER_H
#define QTXWRAPPER_H


#include <math.h>
#include <sys/time.h>

#include "qtx.h"

#include "txdefs.h"

void txInit(char **argv, const char *s);

bool txNeedToCloseApplication();

bool txSetDefaults();

int txGetExtentX();

int txGetExtentY();

bool txOK();

POINT txGetExtent();

/*inline*/ const char* txVersion();

const char* txGetModuleFileName (bool fileNameOnly);

TXWINDOW txCreateWindow(char **argv, int width, int height, const char *title );

TXWINDOW txCreateWindow(char **argv, int x, int y, int width, int height, const char *title );

bool txLine(int x, int y, int x1, int y1);

bool txCircle(int x, int y, int r);

bool txEllipse(int x, int y, int r, int r2);

bool txRectangle(int x, int y, int x1, int y1);

int txExec();

bool txSetColor(COLORREF color, double thickness);

bool txColor(unsigned red, unsigned green, unsigned blue);

COLORREF txGetColor();

bool txSetFillColor(COLORREF color);

bool txTextCursor(bool mode);

bool txFillColor(unsigned red, unsigned green, unsigned blue);

COLORREF txGetFillColor();

int txExtractColor (COLORREF color, COLORREF component);

//-----------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor);

//-----------------------------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor);

bool txSelectFont(const char name[], int sizeY, int sizeX,
                  int bold, bool italic,
                  bool underline, bool strikeout,
                  double angle);

unsigned txSetTextAlign (unsigned align);

bool txTextOut(int x, int y, const char *text);

bool txArc(double x0, double  y0, double  x1, double y1, double  startAngle, double totalAngle );

bool txPie(double x0, double y0, double  x1, double  y1, double  startAngle, double  totalAngle);

bool txChord (double x0, double  y0, double  x1, double  y1, double  startAngle, double  totalAngle);

bool txTriangle(double  x1, double  y1, double  x2, double  y2, double  x3, double  y3);

bool txSetPixel(double x, double  y, COLORREF color);

bool txPixel(double  x, double  y, double  red, double  green, double  blue);

bool txClear();

COLORREF txGetPixel(double x, double y);

void txGetPixel(double x, double y, int *r, int *g, int *b);

bool txPolygon (const POINT points[], int numPoints);

double txSleep (double time);

void txDrawMan (int x, int y, int sizeX, int sizeY, COLORREF color, double handL, double handR, double twist,
                double head, double eyes, double wink, double crazy, double smile, double hair, double wind);

/*inline*/ bool In (const POINT& pt, const RECT& rect);

//-----------------------------------------------------------------------------------------------------------------

bool In (const COORD& pt, const SMALL_RECT& rect);

//-----------------------------------------------------------------------------------------------------------------

/*inline*/ int random (int range);

//-----------------------------------------------------------------------------------------------------------------

/*inline*/ double random (double left, double right);

bool txFloodFill (double x, double y, COLORREF color, DWORD mode);

int txGetTextExtentY (const char text[]);

int txGetTextExtentX (const char text[]);

SIZE txGetTextExtent (const char text[]);

bool txDrawText (double x0, double y0, double x1, double y1, const char text[], unsigned format);

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();

bool txSelectObject(unsigned obj);

int txUpdateWindow(int update);

int txBegin(bool mode);

int txEnd();

bool txLock(bool wait);

bool txUnlock();

bool txDestroyWindow();

void txExitApp(int resultCode);

double txQueryPerformance();

HDCQ /*HDC*/ txDC();

HDCQ /*HDC*/ txCreateCompatibleDC(double sizeX, double sizeY, HBITMAPQ /*HDC*/ bitmap, int size);

HDCQ /*HDC*/ txLoadImage(const char filename[], unsigned imageFlags, unsigned loadFlags);

bool txDeleteDC(HDCQ /*HDC*/ dc);

bool txBitBlt(HDCQ /*HDC*/ dest, double xDest, double yDest, double width, double height, HDCQ /*HDC*/ src, double xSrc, double ySrc, DWORD rOp);

bool txTransparentBlt(HDCQ /*HDC*/ dest, double xDest, double yDest, double width, double height, HDCQ /*HDC*/ src, double xSrc, double ySrc, COLORREF transColor);

bool txAlphaBlend (HDCQ /*HDC*/ dest, double xDest, double yDest, double width, double height, HDCQ /*HDC*/ src, double xSrc, double ySrc, double alpha);

void txKeyEvent(KEYEVENTHANDLER f);

void txMouseEvent(MOUSEEVENTHANDLER f);

void txTimerEvent(TIMEREVENTHANDLER f, void *p, unsigned time);

unsigned txMessageBox(const char *text, const char *header, unsigned flags);

const char *txInputBox(const char *text, const char *caption, const char *input);

bool txDrawDC(double x, double y, HDCQ /*HDC*/ dc);

void txSetWindow(TXWINDOW w);

TXWINDOW txGetWindow();

void txGetWindowRect(TXWINDOW w, RECT *r);

bool txNotifyIcon(unsigned flags, const char title[], const char format[]);

bool txPlaySound(const char filename[], DWORD mode);

QPushButton *txButton(int x, int y, int width, int height, const char *caption, TXSLOT p, char *xml);

QTextEdit *txTextEdit(int x, int y, int width, int height, const char *caption, TXSLOT p, char *xml);

QLineEdit *txEdit(int x, int y, int width, int height, const char *caption, TXSLOT p, char *xml);

QLabel *txLabel(int x, int y, int width, int height, const char *caption, TXSLOT p, char *xml);

QCheckBox *txCheckBox(int x, int y, int width, int height, const char *caption, bool *state, TXSLOT p, char *xml);

QRadioButton *txRadioButton(int x, int y, int width, int height, const char *caption, bool *state, TXSLOT p, char *xml);

QGroupBox *txRadioGroup(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, const char *s, ...);

QGroupBox *txRadioGroup(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

QComboBox *txComboBox(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

QListWidget *txListBox(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

const char *txAppDirPath();

const char *txFromAppDirPath(const char *subDirectoryPath);

#endif
