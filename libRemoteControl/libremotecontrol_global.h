#ifndef libRemoteControl_GLOBAL_H
#define libRemoteControl_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LibRemoteControl_LIBRARY)
#  define libRemoteControlSHARED_EXPORT Q_DECL_EXPORT
#else
#  define libRemoteControlSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RemoteControlPresenter_GLOBAL_H
