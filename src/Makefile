# makfile configuration

CPU             	= msp430g2553

CFLAGS          	= -mmcu=${CPU} -Os -I../h -I../lcdLib -I../timerLib

LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-gcc -mmcu=${CPU} -c



all: toy.elf



#additional rules for files

toy.elf: ${COMMON_OBJECTS} main.o switches.o stateMachines.o buzzer.o led.o lcd_states.o ../lib/libTimer.a ../lib/libLcd.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd



load: toy.elf

	msp430loader.sh $^



clean:

	rm -f *.o *.elf

