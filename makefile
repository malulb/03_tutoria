bin: threads.c
	gcc -pthread -o $@ $<

.PHONY: run clean

run:
	./bin

clean:
	rm bin
