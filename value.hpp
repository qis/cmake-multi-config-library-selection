#pragma once

#ifdef _WIN32
#  if defined(value_shared_EXPORTS)
#    define VALUE_EXPORT __declspec(dllexport)
#  elif defined(value_shared_IMPORTS)
#    define VALUE_EXPORT __declspec(dllimport)
#  else
#    define VALUE_EXPORT
#  endif
#else
#  define VALUE_EXPORT
#endif

extern "C" {

VALUE_EXPORT int value();

}
