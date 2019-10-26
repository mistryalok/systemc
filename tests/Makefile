
export SYSTEMC_HOME=/usr/local/systemc-2.3.2
export LD_LIBRARY_PATH=/usr/local/systemc-2.3.2/lib-linux64

HELLO = hello

TARGET = ${HELLO}


all:
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux64 -o ${TARGET} ${TARGET}.cc -lsystemc -lm
