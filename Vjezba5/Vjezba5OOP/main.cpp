#include "classWork.h"

using namespace std;

int main() {
	srand(time(NULL));

	dot first, second, third;

	first.setPseudorandom(1, 10);
	second.setPseudorandom(1, 10);
	third.setPseudorandom(1, 10);

	std::cout << "Distance between first and second dot in 2D is:" << endl;
	std::cout << first.distance2D(second) << endl;

	std::cout << "Distance between first and second dot in 3D is:" << endl;
	std::cout << first.distance3D(third) << endl;

	weapon gun;
	gun.generateShooter(first, 30);
	gun.reload();


	int n = 100;
	target* object = new target[n];

	for (int i = 0; i < n; i++) {
		first.setPseudorandom(1, 10);
		second.setPseudorandom(1, 10);
		object[i].generateTarget(first, second);
	}

	int shooted = 0;


	for (int i = 0; i < n && gun.cBullets() > 0; i++) {
		
		std::cout << "shooted " << shooted << " Broj metaka: " << gun.cBullets() << " trenutni i: " << i << endl;
		double a = gun.getPosition().getZ() - object[i].getLL().getZ();
		double b = gun.getPosition().getZ() - object[i].getUR().getZ();
		
		gun.shoot();

		/*if (!gun.cBullets()) {
			std::cout << "Broj pogodenih meta sa jednim punjenjem je: " << shooted << endl;
			gun.reload();
		}*/
		if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
			shooted += object[i].hits();
		}
	}
	
	std::cout << "Broj pogodenih meta je: " << shooted << endl;

	return 0;
}