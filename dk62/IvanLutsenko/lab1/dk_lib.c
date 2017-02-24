#include "dk_lib.h"

int result(int c, int d, int f) {
	int res = 0;
	for (int a = 1; a <= d; a++)
		res += a * (f - c);
	return res;
}
