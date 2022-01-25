#include "sdl.h"

bool moreThan500(Number& Num)
{
	return Num.num > 500;
}

bool smallerThan300(Number& Num)
{
	return Num.num < 300;
}

bool downward(Number& numOne, Number& numTwo)
{
	return numOne.num > numTwo.num;
}

istream& operator>>(istream& isFile, Number& Num)
{
	isFile >> Num.num;
	return isFile;
}

ostream& operator<<(ostream& outFile, const Number& Num)
{
	return outFile << Num.num << endl;
}

bool compare(const Number& s1, const Number& s2) {
	return s1.num < s2.num;
}

int main()
{
	//napuni vektor brojevima iz datoteke
	vector<Number> numbers;

	ifstream file("numbers.txt");
	
	try {
		if (!file.is_open()) {
			throw 1;
		}
		istream_iterator<Number> is1(file), ends1;
		copy(is1, ends1, back_inserter(numbers));
	}
	catch (int) {
		cout << "Error, no file" << endl;
	}

	cout << count_if(numbers.begin(), numbers.end(), moreThan500) << endl;

	numbers.erase(remove_if(numbers.begin(), numbers.end(), smallerThan300), numbers.end());

	sort(numbers.begin(), numbers.end(), downward);

	//minimum i maximum broj
	auto max = std::max_element(numbers.begin(),numbers.end(), compare);
	auto min = std::min_element(numbers.begin(), numbers.end(), compare);

	//ispis
	ostream_iterator<Number> os3(cout, "\n");
	copy(numbers.begin(), numbers.end(), os3);
	std::cout << "max" << max->num << endl;
	std::cout << "min" << min->num << endl;
	file.close();
}