.PHONY: all clean

all: test_wiegand_writer

test_wiegand_writer: test_wiegand_writer.c tinkerforge/ip_connection.c tinkerforge/bricklet_industrial_digital_out_4_v2.c
	gcc -O2 -Wall -Wextra -pthread $^ -o $@

clean:
	rm test_wiegand_writer
