#include "value.hpp"
#include <string>
#include <cstdio>
#include <cerrno>
#include <dlfcn.h>

struct Display;
Display* XOpenDisplay(const char* name);

int main() {
  std::puts(std::to_string(value()).data());
  const auto handle = dlopen("/usr/lib/x86_64-linux-gnu/libX11.so", RTLD_NOW);
  if (!handle) {
    std::fprintf(stderr, "could not open libX11.so: %s\n", dlerror());
    return 1;
  }
  const auto XOpenDisplayProc = reinterpret_cast<decltype(&XOpenDisplay)>(dlsym(handle, "XOpenDisplay"));
  if (!XOpenDisplayProc) {
    std::fputs("could not get function address: XOpenDisplay\n", stderr);
    return 1;
  }
}
