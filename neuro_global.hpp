#pragma once

#include <QtCore/qglobal.h>

#if defined(NEURO_LIBRARY)
#  define NEUROSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NEUROSHARED_EXPORT Q_DECL_IMPORT
#endif
