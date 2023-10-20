importScripts("wasm.js");
const loop = Module.cwrap("loop", null, ["number", "string"]);
self.onmessage = (evt) => loop(...evt.data);
