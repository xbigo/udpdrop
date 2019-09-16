#define UD_ABI_PREFIX <udpdrop/config/abi/msvc_prefix.hpp>
#define UD_ABI_SUFFIX <udpdrop/config/abi/msvc_suffix.hpp>

#define UD_FUNCTION __FUNCTION__ 

#define UD_DLL_EXPORT __declspec( dllexport )
#define UD_DLL_IMPORT __declspec( dllimport )

#define UD_DLL_INTERFACE __declspec(novtable)

