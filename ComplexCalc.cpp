#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double real;
    double imag;
    
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Addition
    Complex add(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Subtraction
    Complex subtract(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }
    
    // Multiplication
    Complex multiply(const Complex& other) {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }
    
    // Division
    Complex divide(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            cout << "Error: Division by zero!" << endl;
            return Complex(0, 0);
        }
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }
    
    // Magnitude (absolute value)
    double magnitude() {
        return sqrt(real * real + imag * imag);
    }
    
    // Conjugate
    Complex conjugate() {
        return Complex(real, -imag);
    }
    
    // Display function
    void display() {
        if (imag >= 0) {
            cout << real << " + " << imag << "i";
        } else {
            cout << real << " - " << abs(imag) << "i";
        }
    }
};

int main() {
    // Example usage
    Complex c1(3, 4);    // 3 + 4i
    Complex c2(1, 2);    // 1 + 2i
    
    cout << "c1 = ";
    c1.display();
    cout << endl;
    
    cout << "c2 = ";
    c2.display();
    cout << endl;
    
    // Addition
    Complex sum = c1.add(c2);
    cout << "c1 + c2 = ";
    sum.display();
    cout << endl;
    
    // Subtraction
    Complex diff = c1.subtract(c2);
    cout << "c1 - c2 = ";
    diff.display();
    cout << endl;
    
    // Multiplication
    Complex product = c1.multiply(c2);
    cout << "c1 * c2 = ";
    product.display();
    cout << endl;
    
    // Division
    Complex quotient = c1.divide(c2);
    cout << "c1 / c2 = ";
    quotient.display();
    cout << endl;
    
    // Magnitude
    cout << "Magnitude of c1 = " << c1.magnitude() << endl;
    
    // Conjugate
    Complex conj = c1.conjugate();
    cout << "Conjugate of c1 = ";
    conj.display();
    cout << endl;
    
    return 0;
}