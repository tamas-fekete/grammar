parser: main.o tokenizer.o
	gcc -o parser main.o tokenizer.o

main.o: main.c
	gcc -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

debug = .PHONY
debug:
	gcc -g main.c tokenizer.c -o dbparser -lm

clean = .PHONY
clean:
	rm *.o parser
