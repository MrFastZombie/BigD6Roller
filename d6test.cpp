#include <iostream>
#include <stdlib.h> 
#include <random>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

/*int rolld6() { //This used mt19937, which seemed to be faster than Rand() but still too slow for this.
    auto t0 = chrono::high_resolution_clock::now();
    auto nanosec = t0.time_since_epoch().count();
    mt19937 mt(nanosec);
    uniform_int_distribution die{1,6};

    return die(mt);
}*/

int rolld6() { //I switched to minstd_rand here, which appears to be insanely fast.
    auto t0 = chrono::high_resolution_clock::now();
    auto nanosec = t0.time_since_epoch().count();

    minstd_rand gen(nanosec);
    uniform_real_distribution<double> dist(1,7);

    return dist(gen);
}


int main()
{
    unsigned long long int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    int sum5 = 0;
    int sum6 = 0;
    int roll = 0;

    for(unsigned int i = 0; i < 1000000; i++) { //Check the die distribution
        roll = rolld6();
        switch (roll) {
        case 1:
            sum1++;
            break;
        case 2:
            sum2++;
            break;
        case 3:
            sum3++;
            break;
        case 4:
            sum4++;
            break;
        case 5:
            sum5++;
            break;
        case 6:
            sum6++;
            break;
        
        default:
            cout << "The die roller went out of bounds! Rolled: " << roll << endl;
        }
    }

    cout << "Die Distribution" << endl << " 1: " << sum1 << " 2: " << sum2 << " 3: " << sum3 << " 4: " << sum4 << " 5: " << sum5 << " 6: " << sum6 << endl;
    for(long long int i = 1; i <= 2400000000L; i++) {
        sum = sum + rolld6();
        if(i%10000000L == 0) {
            cout << "\rrolled " << i << " die.";
        }
    }
    cout << endl << sum << endl;
    system("pause");
    return 0;
}