#ifndef TESTSHAREDLIB_GLOBAL_H
#define TESTSHAREDLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTSHAREDLIB_LIBRARY)
#  define TESTSHAREDLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TESTSHAREDLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTSHAREDLIB_GLOBAL_H