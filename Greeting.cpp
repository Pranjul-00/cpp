#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;

    if (hour < 12) {
        cout << "Good Morning" << endl;
    }
    else if (hour < 18) {
        cout << "Good Afternoon" << endl;
    }
    else {
        cout << "Good Evening" << endl;
    }
    return 0;
}