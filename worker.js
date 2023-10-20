importScripts("wasm.js");
const loop = Module.cwrap("loop", null, ["number"]);
self.onmessage = (evt) => loop(evt.data);
self.postMessage(undefined);
