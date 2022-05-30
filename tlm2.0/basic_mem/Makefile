
export SYS_PATH=/home/alok/Desktop/git/systemc/systemc-2.3.3/systemc-2.3.3

export SYSTEMC_HOME=${SYS_PATH}
export LD_LIBRARY_PATH=${SYS_PATH}/lib-linux64

HELLO = testbench

TARGET = ${HELLO}


all:
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux64 -o ${TARGET} ${TARGET}.cc -lsystemc -lm
	./$(TARGET)
