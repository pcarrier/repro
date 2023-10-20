.PHONY: serve deploy

serve: wasm.js
	python3 -m http.server

deploy: wasm.js
	rsync -av index.html worker.js wasm.js wasm.wasm horse:web/emscripten/

wasm.js: wasm.cc
	emcc \
		-sALLOW_MEMORY_GROWTH=1 \
		-sSTACK_SIZE=64KB \
		-sEXPORTED_RUNTIME_METHODS=cwrap \
		-g3 \
		$< -o $@