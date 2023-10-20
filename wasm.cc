#include <emscripten.h>
#include <emscripten/stack.h>
#include <algorithm>
#include <sstream>
#include <iostream>

inline void dump_stack(std::string msg) {
  std::cout << msg << ": " << emscripten_stack_get_base() << ":" << emscripten_stack_get_current() << ":" << emscripten_stack_get_end() << std::endl << std::flush;
}

extern "C" EMSCRIPTEN_KEEPALIVE void loop(const int n, const char *str)
{
  dump_stack("start");

  std::string received(str);
  reverse(received.begin(), received.end());

  std::stringstream ss;
  ss << "self.postMessage('$target.innerHTML = \"" << n << ": " << received << "\"; $worker.postMessage([" << n + 1 << ", \"" << received << "\"]);');";
  auto running = ss.str();
  emscripten_run_script(running.c_str());

  dump_stack("end");
}

int main() {
  emscripten_run_script("self.postMessage(undefined);");
}
