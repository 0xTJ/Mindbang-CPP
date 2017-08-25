#include "Mindbang.hpp"
//TODO: implement negative tape
//TODO: implement jmp
//TODO: implement file reads
//TODO: implement infinite tape
//TODO: implement running from tape or modifying prog
//TODO: implement syscalls

Mindbang::Mindbang(const char *proc) {
	p = proc;
	p_s = p;
	t = tape;
}

void Mindbang::pInc() {
	++t;
}

void Mindbang::pDec() {
	--t;
}

void Mindbang::dInc() {
	++*t;
}

void Mindbang::dDec() {
	--*t;
}
void Mindbang::dPut() {
	std::cout << *t;
}

void Mindbang::dGet() {
	std::cin >> *t;
}

void Mindbang::whlB() {
	if (!*t) {
		int cBr = 1;
		do {
			p++;
			if (*p == '[')
				cBr++;
			else if (*p == ']')
				cBr--;
		} while ( cBr != 0 );
	}
}

void Mindbang::Mindbang::whlE() {
	if (*t) {
		int cBr = 1;
		do {
			p--;
			if (*p == '[')
				cBr--;
			else if (*p == ']')
				cBr++;
		} while ( cBr != 0 );
	}
}

int Mindbang::proc() {
	while (*p) {
		switch (*p) {
		case '>':
			pInc();
			break;
		case '<':
			pDec();
			break;
		case '+':
			dInc();
			break;
		case '-':
			dDec();
			break;
		case '.':
			dPut();
			break;
		case ',':
			dGet();
			break;
		case '[':
			whlB();
			break;
		case ']':
			whlE();
			break;
		}
		p++;
	}
	return *t;
}

void Mindbang::dump() {
	int i = 0;
	while (tape[i]) {
		printf("%d", tape[i++]);
	}
	printf("\n");
}

void Mindbang::sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
	