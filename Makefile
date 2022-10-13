LPATH=~/openssl/lib
SPATH=~/openssl/src

all:
        cd $(LPATH); make all
        cd $(SPATH); make all

clean:
        cd $(LPATH); make clean
        cd $(SPATH); make clean
