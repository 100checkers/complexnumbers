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
