//Complex Numbers
/*
This program takes four inputs from a user (two complex numbers)
The code uses the dot operator to access/apply the real and imaginary parts that make up each complex number
Function protoypes are declared above main for adding, subtracting, multiplying, and dividing
Function definitions are behind main
The functions are called from within main to apply calculations for each set of complex numbers
This is possible by creating the forumlas with variables and then assigning the variables to the calculations
For example, a*c is represented by variables num1.real * num2.real
The cmath library was also enabled to achieve this

All results are stored under a results object and outputted with a function of type void
A do while loop was also implemented to allow for multiple runs as long as the user agrees by pressing "y/Y"
A second while loop was needed for error-checking because the second complex number mustn't be 0 or 0i
*/


using namespace std;

#include <iostream>
#include <cmath>


struct ComplexNumber {
	double real;
	double imag;
};

ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2);
ComplexNumber subtractComplexNumbers(ComplexNumber num1, ComplexNumber num2);
ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2);
ComplexNumber divideComplexNumbers(ComplexNumber num1, ComplexNumber num2);
void displayComplexNumber(ComplexNumber num);



int main() {
	ComplexNumber num1;
	ComplexNumber num2;
	char userChar;


	cout << "**** Complex Numbers ****" << endl;
	cout << endl;

	do {
		cout << "Enter 1st complex number real and imaginary parts separated by space: ";
		cin >> num1.real >> num1.imag;
		cout << endl;

		cout << "Enter 2nd complex number real and imaginary parts (non-zero) separated by space: ";
		cin >> num2.real >> num2.imag;

		while (num2.real == 0 || num2.imag == 0) {
			cout << ">>>ERROR: Both numbers must be non-zero -- try again! <<<" << endl;
			cout << endl;
			cout << "Enter 2nd complex number real and imaginary parts (non-zero) separated by space: ";
			cin >> num2.real >> num2.imag;
		}

		cout << endl;
		cout << "Results:" << endl;
		cout << "\tAddition results: ";
		displayComplexNumber(addComplexNumbers(num1, num2));
		cout << endl;

		cout << "\tSubtraction results: ";
		displayComplexNumber(subtractComplexNumbers(num1, num2));
		cout << endl;

		cout << "\tMultiplication results: ";
		displayComplexNumber(multiplyComplexNumbers(num1, num2));
		cout << endl;

		cout << "\tDivision results: ";
		displayComplexNumber(divideComplexNumbers(num1, num2));
		cout << endl;

		cout << endl;
		cout << endl;
		cout << "Run again (y or Y) or any other character to end? ";
		cin >> userChar;
		cout << endl;


	} while (userChar == 'y' || userChar == 'Y');
	// tolower() is also an option 


	return 0;
}

ComplexNumber addComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.real = num1.real + num2.real;
	result.imag = num1.imag + num2.imag;

	return result;
}

ComplexNumber subtractComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.real = num1.real - num2.real;
	result.imag = num1.imag - num2.imag;

	return result;
}

ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;

	result.real = ((num1.real * num2.real) - (num1.imag * num2.imag));
	result.imag = ((num1.real * num2.imag) + (num1.imag * num2.real));

	return result;
}

ComplexNumber divideComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
	ComplexNumber result;
	double divider = pow(num2.real, 2) + pow(num2.imag, 2);

	result.real = ((num1.real * num2.real) + (num1.imag * num2.imag)) / divider;
	result.imag = ((num1.imag * num2.real) - (num1.real * num2.imag)) / divider;

	return result;
}


void displayComplexNumber(ComplexNumber num) {
	ComplexNumber result;

	cout << num.real << " " << num.imag << "i";

}






/*


	a = num1.real
	b = num1.imag
	c = num2.real
	d = num2.imag

	multiplication:
	(ac - bd) + (ad + bc) i

						(a		*	c)			(b		*	d)				(a	  *		d)				(b	  *		c)
	result.real = ((num1.real * num2.real) - (num1.imag * num2.imag))
	result.imag = ((num1.real * num2.imag) + (num1.imag * num2.real)) i



	division:

		(ac + bd / c^2 + d^2)  + (bc - ad/ c^2 + d^2) i

							(a     *     c)     +  	 (b      *   d)                       (b       *    c)    -   (a        *     d)
		result.real = ((num1.real * num2.real) + (num1.imag * num2.imag)) / divider;

		result.imag ((num1.imag * num2.real) - (num1.real * num2.imag)) / divider;


	 */

