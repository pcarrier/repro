.PHONY: serve

serve: wasm.js
	python3 -m http.server

wasm.js: wasm.cc
	emcc \
		-sALLOW_MEMORY_GROWTH=1 \
		-sSTACK_SIZE=1KB \
		-sEXPORTED_RUNTIME_METHODS=cwrap \
		$< -o $@
