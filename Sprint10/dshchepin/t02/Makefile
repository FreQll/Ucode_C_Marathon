name := mx_cat

all: $(name)

$(name):
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o $(name) src/*.c

clean:
	rm -rf $(name)

uninstall:
	rm -rf $(name)

reinstall:
	make uninstall
	make
