#include <emscripten.h>
#include <emscripten/stack.h>
#include <algorithm>
#include <sstream>
#include <iostream>

inline void dump_stack(std::string msg) {
  std::cout << msg << ": " << emscripten_stack_get_base() << ":" << emscripten_stack_get_current() << ":" << emscripten_stack_get_end() << std::endl;
}

std::string jsString(std::string src) {
  std::stringstream ss;
  ss << "\"";
  for (auto c : src) {
    switch (c) {
      case '\\': ss << "\\\\"; break;
      case '\'': ss << "\\'"; break;
      case '"': ss << "\\\""; break;
      default: ss << c; break;
    }
  }
  ss << "\"";
  return ss.str();
}

extern "C" EMSCRIPTEN_KEEPALIVE void loop(const int n, const char *str)
{
  std::string received(str);
  reverse(received.begin(), received.end());
  auto escapedReceived = jsString(received);

  std::stringstream ss;
  ss << "self.postMessage('$target.innerHTML = \\'" << n << ": " << escapedReceived << "\\'; $worker.postMessage([" << n + 1 << ", " << escapedReceived << "]);');";
  auto running = ss.str();
  emscripten_run_script(running.c_str());
}

int main() {
  emscripten_run_script("self.postMessage(undefined);");
}
