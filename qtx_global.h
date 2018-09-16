#ifndef QTX_GLOBAL_H
#define QTX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTX_LIBRARY)
#  define QTXSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTXSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTX_GLOBAL_H
