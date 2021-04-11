#pragma once

#ifdef _WIN32
#  if defined(value_shared_EXPORTS)
#    define VALUE_API __declspec(dllexport)
#  elif defined(value_shared_IMPORTS)
#    define VALUE_API __declspec(dllimport)
#  else
#    define VALUE_API
#  endif
#else
#  define VALUE_API
#endif

extern "C" {

VALUE_API int value();

}
