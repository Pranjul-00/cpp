#include <iostream>
using namespace std;

// int sum(int num1, int num2);

//Print numbers from 1 to 1000
// int main(){
//     int i=1;
//     while(i<=1000){
//     cout<<i <<endl;
//     i++;
//     }
//     return 0;
// }

//Table of a number using while
// int main(){
//     cout << "Enter a number : ";
//     int num;
//     cin >> num;
//     int i=1;
//     while(i<=10){
//         cout << num << " * " << i << " = " << num*i <<endl;
//         i++;
//     }
//     return 0;
// }

//Table of a number using do while
// int main(){
//     cout << "Enter a number : ";
//     int num;
//     cin >> num;
//     int i=1;
//     do{
//         cout << num << " * " << i << " = " << num*i <<endl;
//         i++;
//     }while(i<=10);
//     return 0;
// }

//Factorial of a number     
// int main(){
//     int num;
//     cout << "Enter a number : ";
//     cin >> num;
//     int result=1;
//     if(num<0){
//         cout << "Factorial is not defined for negative numbers";
//         return 0;
//     }
//     else{
//         while(num>=1){
//             result = result*num;
//             num--;
//         }
//         cout << result;
//     }
//     return 0;
// }

//Table of a number using for
// int main(){
//     cout << "Enter a number : ";
//     int num;
//     cin >> num;
//     cout << "Table of " << num << endl;
//     for(int i=1;i<=10;i++){
//         cout << num << " * " << i << " = " << num*i <<endl;
//     }
//     return 0;
// }

//Printing Patterns #1
// int main(){
//     cout << "Enter no. of lines to be printed : ";
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//  Printing Patterns #2
// int main(){
//     cout << "Enter no. of lines to be printed : ";
//     int n; 
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//Printing Patters #3
// int main(){
//     cout << "Enter no. of lines to be printed : ";
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout << " ";
//         }
//         for(int j=1;j<=2*i-1;j++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//Sum of two numbers
// int main(){
//     cout<<"Enter first number : ";
//     int num1;
//     cin>>num1;
//     cout<<"Enter second number : ";
//     int num2;
//     cin>>num2;
//     int c= sum(num1,num2);
//     cout<<"The sum of "<<num1<<" and "<<num2<<" is "<<c<<endl;
//     return 0;
// }

// int sum(int num1, int num2){
//     int result = num1 + num2;
//     return result;
// }


// int main() {
//     cout << "Enter the size of the square (n): ";
//     int n;
//     cin >> n;
    
//     int arr[10][10];
//     int num = 1;
    
//     // Fill the upper triangle
//     for (int d = 0; d < n; d++) {
//         if (d % 2 == 0) {
//             // Move down-left
//             for (int i = 0; i <= d; i++) {
//                 arr[i][d - i] = num++;
//             }
//         } else {
//             // Move up-right
//             for (int i = d; i >= 0; i--) {
//                 arr[i][d - i] = num++;
//             }
//         }
//     }
    
//     // Fill the lower triangle
//     for (int d = 1; d < n; d++) {
//         if ((n + d - 1) % 2 == 0) {
//             // Move down-left
//             for (int i = d; i < n; i++) {
//                 arr[i][n - 1 - (i - d)] = num++;
//             }
//         } else {
//             // Move up-right
//             for (int i = n - 1; i >= d; i--) {
//                 arr[i][n - 1 - (i - d)] = num++;
//             }
//         }
//     }
    
//     // Print the pattern
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << arr[i][j] << "\t";
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }


int main(){
    int arr[]={1,2,3,4,5};
    int *p=arr;
    cout<<*(p++)<<endl;
    cout<<*p<<endl;
    cout<<*(++p)<<endl;
    cout<<*p++<<endl;
    return 0;
}