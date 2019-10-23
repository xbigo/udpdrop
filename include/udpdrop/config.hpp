#ifndef UDPDROP_CONFIG_H
#define UDPDROP_CONFIG_H
#include <udpdrop/version.hpp>
#include <udpdrop/config/config.hpp>

#if defined (UD_DLL_EXPORT)
#   define UD_API UD_DLL_EXPORT
#   define UD_INTERFACE UD_DLL_INTERFACE
#elif defined (UD_DLL_IMPORT)
#   define UD_API UD_DLL_IMPORT
#   define UD_INTERFACE UD_DLL_INTERFACE
#else
#   define UD_API          //for static
#   define UD_INTERFACE
#endif

#endif //end UDPDROP_CONFIG_H

