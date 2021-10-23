#include "pravokutnik.hpp"

int sFunkcija(const Pravokutnik(&p)[4], int n, const Kruznica& k) {
	int sijece = 0;
	for (int i = 0; i < n; i++) {
		int dijagonala = sqrt(pow(p[i].c.y, 2) + (pow(p[i].c.x, 2)));
		if (dijagonala > k.radijus) {
			sijece++;
		}
	}
	return sijece;
}