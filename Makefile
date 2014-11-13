





# expt: x-experiments.c keybindings.h keypress.c keypress.h keybindings.c
# 	gcc -o expt x-experiments.c keypress.c keybindings.c -lX11

all: chordial.c keybindings.h keypress.c keypress.h keybindings.c
	gcc -g -o chordial chordial.c keypress.c keybindings.c -lX11 -lXtst

tfk: test_fakekey.c keybindings.h keypress.c keypress.h keybindings.c
	gcc -g -o tfk test_fakekey.c keypress.c keybindings.c -lX11 -lXtst

xex:  x-experiments.c keybindings.h keypress.c keypress.h keybindings.c
	gcc -g -o xex x-experiments.c keypress.c keybindings.c -lX11 -lXtst
