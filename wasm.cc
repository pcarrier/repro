#include <emscripten.h>
#include <emscripten/stack.h>
#include <sstream>
#include <iostream>

inline void dump_stack(std::string msg) {
  std::cout << msg << ": " << emscripten_stack_get_base() << ":" << emscripten_stack_get_current() << ":" << emscripten_stack_get_end() << std::endl;
}

extern "C" EMSCRIPTEN_KEEPALIVE void loop(int n)
{
  dump_stack("start");
  std::stringstream ss;
  ss << "self.postMessage('$target.innerHTML = " << n << "; $worker.postMessage(" << n + 1 << ");');";
  auto msg = ss.str();
  std::cout << msg << std::endl;
  emscripten_run_script(msg.c_str());
  dump_stack("end");
}
