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

TXWINDOW txCreateWindow(char **argv, int width, int height, const char *title = NULL );

TXWINDOW txCreateWindow(char **argv, int x, int y, int width, int height, const char *title = NULL );

bool txLine(int x, int y, int x1, int y1);

bool txCircle(int x, int y, int r);

bool txEllipse(int x, int y, int r, int r2);

bool txRectangle(int x, int y, int x1, int y1);

int txExec();

bool txSetColor(COLORREF color, double thickness = 1);

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

bool txSelectFont(const char name[], int sizeY, int sizeX = -1,
                  int bold = 0, bool italic = false,
                  bool underline = false, bool strikeout = false,
                  double angle = 0);

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

bool txFloodFill (double x, double y, COLORREF color = TX_TRANSPARENT, DWORD mode = 0);

int txGetTextExtentY (const char text[]);

int txGetTextExtentX (const char text[]);

SIZE txGetTextExtent (const char text[]);

bool txDrawText (double x0, double y0, double x1, double y1, const char text[], unsigned format = 0);

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();

bool txSelectObject(unsigned obj);

int txUpdateWindow(int update);

int txBegin(bool mode = false);

int txEnd();

bool txLock(bool wait = true);

bool txUnlock();

bool txDestroyWindow();

void txExitApp(int resultCode = 0);

double txQueryPerformance();

HDCQ txDC();

HDCQ txCreateCompatibleDC(double sizeX, double sizeY, HBITMAPQ bitmap = NULL, int size = 0);

HDCQ txLoadImage(const char filename[], unsigned imageFlags = 0, unsigned loadFlags = 0);

bool txDeleteDC(HDCQ dc);

bool txBitBlt(HDCQ dest, double xDest, double yDest, double width, double height,
              HDCQ src, double xSrc = 0, double ySrc = 0, DWORD rOp = 0);

bool txTransparentBlt(HDCQ dest, double xDest, double yDest, double width, double height,
                      HDCQ src, double xSrc = 0, double ySrc = 0, COLORREF transColor = TX_BLACK);

bool txAlphaBlend (HDCQ dest, double xDest, double yDest, double width, double height,
                   HDCQ src, double xSrc = 0, double ySrc = 0, double alpha = 1.0);

void txKeyEvent(KEYEVENTHANDLER f);

void txMouseEvent(MOUSEEVENTHANDLER f);

void txTimerEvent(TIMEREVENTHANDLER f, void *p, unsigned time);

unsigned txMessageBox(const char *text, const char *header = "QTXLib сообщает", unsigned flags = 0);

const char *txInputBox(const char *text = NULL, const char *caption = NULL, const char *input = NULL);

bool txDrawDC(double x, double y, HDCQ dc);

void txSetWindow(TXWINDOW w);

TXWINDOW txGetWindow();

void txGetWindowRect(TXWINDOW w, RECT *r);

bool txNotifyIcon(unsigned flags, const char title[], const char format[]);

bool txPlaySound(const char filename[] = NULL, DWORD mode = 0);

QPushButton *txButton(int x, int y, int width, int height, const char *caption,
                      TXSLOT p = NULL, char *xml = NULL);

QTextEdit *txTextEdit(int x, int y, int width, int height, const char *caption,
                      TXSLOT p = NULL, char *xml = NULL);

QLineEdit *txEdit(int x, int y, int width, int height, const char *caption,
                  TXSLOT p = NULL, char *xml = NULL);

QLabel *txLabel(int x, int y, int width, int height, const char *caption,
                TXSLOT p = NULL, char *xml = NULL);

QCheckBox *txCheckBox(int x, int y, int width, int height, const char *caption, bool *state,
                      TXSLOT p = NULL, char *xml = NULL);

QRadioButton *txRadioButton(int x, int y, int width, int height, const char *caption, bool *state,
                            TXSLOT p = NULL, char *xml = NULL);

QGroupBox *txRadioGroup(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, const char *s, ...);

QGroupBox *txRadioGroup(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

QComboBox *txComboBox(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

QListWidget *txListBox(int x, int y, int width, int height, const char *caption, int *id, TXSLOT p, char *xml, char **list);

const char *txAppDirPath();

const char *txFromAppDirPath(const char *subDirectoryPath);

#endif
