#ifndef NEURO_GLOBAL_HPP
#define NEURO_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(NEURO_LIBRARY)
#  define NEUROSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NEUROSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NEURO_GLOBAL_HPP
