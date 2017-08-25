#include <iostream>
#include <time.h>

class Mindbang {
  public:
    char tape[10000] = {0};
    char *t;
    const char *p;
    const char *p_s;
	
	Mindbang(const char *proc);
	void pInc();
	void pDec();
	void dInc();
	void dDec();
	void dPut();
	void dGet();
	void whlB();
	void whlE();
	void proc();
	
	void dump();
	void sleep(unsigned int mseconds);
};