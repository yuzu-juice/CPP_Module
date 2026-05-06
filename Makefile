CLANG_IMAGE := silkeh/clang:19

CLANG_DOCKER := docker run --rm \
								-v $$(pwd):/workspace \
								-w /workspace \
								$(CLANG_IMAGE) /bin/sh -c

FILES := $$(find . -not -path "./build/*" -name "*.cpp" -o -not -path "./build/*" -name "*.hpp" | tr '\n' ' ')

format:
	$(CLANG_DOCKER) \
	"clang-format -i -style=Google --verbose $(FILES)"

.PHONY: format
