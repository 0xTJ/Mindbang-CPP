#include <iostream>
#include "Mindbang.hpp"

int main() {
	Mindbang *MB = new Mindbang("+[[->]-[-<]>-]>.>>>>.<<<<-.>>-.>.<<.>>>>-.<<<<<++.>>++.");
	MB->proc();
	return 0;
}