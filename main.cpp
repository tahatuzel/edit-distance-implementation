#include "EditDistance.h"
#include "EditDistanceRecursive.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <chrono> 

using namespace std;


void runComparison(const std::string& str1, const std::string& str2, bool run_recursive = true) {

    long long dp_duration = -1;
    long long rec_duration = -1;
    int distance1 = -1;
    int distance2 = -1;

    cout << "Calculating with Dynamic Programming..." << endl;
    try {
        auto start_dp = std::chrono::high_resolution_clock::now();
        
        distance1 = editDistance(str1, str2);
        
        auto stop_dp = std::chrono::high_resolution_clock::now();
        
        // CHANGE 1: Use nanoseconds instead of microseconds
        auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_dp - start_dp);
        dp_duration = duration_ns.count();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred (DP): " << e.what() << '\n';
    }

    if (run_recursive) {
        cout << "Calculating with Recursive (this may be slow)..." << endl;
        try {
            auto start_rec = std::chrono::high_resolution_clock::now();
            
            distance2 = edit_distance_recursive(str1, str2); 
            
            auto stop_rec = std::chrono::high_resolution_clock::now();
            
            // CHANGE 2: Use nanoseconds here too
            auto duration_ns_rec = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_rec - start_rec);
            rec_duration = duration_ns_rec.count();
        } catch (const std::exception& e) {
             std::cerr << "An error occurred (Recursive): " << e.what() << '\n';
        }
    }

    // ... (Print Result section same as before) ...

    cout << "\n----------------------------------------------" << endl;
    cout << "PERFORMANCE COMPARISON (Time)" << endl;
    cout << "----------------------------------------------" << endl;
    
    // CHANGE 3: Update print statements to show nanoseconds and microseconds
    if (dp_duration != -1) {
        cout << "-> Dynamic Programming : " << dp_duration << " ns (" << dp_duration / 1000.0 << " us)" << endl;
    } else {
        cout << "-> Dynamic Programming : FAILED" << endl;
    }

    if (run_recursive) {
        if (rec_duration != -1) {
            cout << "-> Recursive           : " << rec_duration << " ns (" << rec_duration / 1000.0 << " us)" << endl;
            
            if (rec_duration > 0 && dp_duration > 0) {
                 double speedup = (double)rec_duration / dp_duration;
                 cout << "   (DP was approx " << std::fixed << std::setprecision(2) << speedup << "x faster)" << endl;
            }
        } else {
            cout << "-> Recursive           : FAILED" << endl;
        }
    } else {
        cout << "-> Recursive           : SKIPPED" << endl;
    }
    cout << "==============================================\n" << endl;
}

int main() {
    string input1, input2;
    
    cout << "*************************************************" << endl;
    cout << "* EDIT DISTANCE ALGORITHM COMPARATOR       *" << endl;
    cout << "*************************************************" << endl;
    cout << "* Type 'exit' to stop the program. *" << endl;

    while (true) {
        cout << "\n-------------------------------------------------" << endl;
        
        cout << ">> First Word: ";
        if (!getline(cin, input1)) break;
        if (input1 == "exit") break;

        cout << ">> Second Word: ";
        if (!getline(cin, input2)) break;
        if (input2 == "exit") break;


        runComparison(input1, input2);
    }

    cout << "\nExiting ..." << endl;
    return 0;
}

