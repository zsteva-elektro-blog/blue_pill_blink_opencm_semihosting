

all: .build-libopencm3

.build-libopencm3: libopencm3
	make -C libopencm3 all
	touch .build-libopencm3

libopencm3:
	git submodule update --init


