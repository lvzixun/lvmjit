.PHONY : macosx linux clean

macosx:
	clang -Wall -g -O2 -shared -undefined dynamic_lookup -o lvmjit.so lvm_jit.c -Ilua/

linux:
	gcc -Wall -g -O2 -shared -o lvmjit.so lvm_jit.c -Ilua/

lvmjit:
	cd dynasm && luajit dynasm.lua -o ../lvm_x64.h ../lvm_x64.dasc

test:
	../lua/lua-5.4.0/src/lua test.lua