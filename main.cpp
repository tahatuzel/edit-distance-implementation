#include "EditDistance.h"
#include "EditDistanceRecursive.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono> // Make sure this is included at the top

using namespace std;

/**
 * @brief Runs a comparison between DP and Recursive edit distance algorithms.
 * @param str1 The first string.
 * @param str2 The second string.
 * @param run_recursive A flag to decide if we should run the slow recursive version.
 * This is useful for skipping it on very long strings.
 */
void runComparison(const std::string& str1, const std::string& str2, bool run_recursive = true) {
    cout << "\n==============================================" << endl;
    cout << "Comparing algorithms for:" << endl;
    cout << "Word 1: \"" << str1 << "\" (Length: " << str1.length() << ")" << endl;
    cout << "Word 2: \"" << str2 << "\" (Length: " << str2.length() << ")" << endl;
    cout << "==============================================" << endl;

    long long dp_duration = -1;
    long long rec_duration = -1;
    int distance1 = -1;
    int distance2 = -1;

    // --- 1. Dynamic Programming (Hesaplama) ---
    cout << "Calculating with Dynamic Programming..." << endl;
    try {
        auto start_dp = std::chrono::high_resolution_clock::now();
        distance1 = editDistance(str1, str2); // Hesapla ama henüz yazdirma
        auto stop_dp = std::chrono::high_resolution_clock::now();
        
        auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(stop_dp - start_dp);
        dp_duration = duration_us.count();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred (DP): " << e.what() << '\n';
    }

    // --- 2. Recursive (Hesaplama) ---
    if (run_recursive) {
        cout << "Calculating with Recursive (this may be slow)..." << endl;
        try {
            auto start_rec = std::chrono::high_resolution_clock::now();
            distance2 = edit_distance_recursive(str1, str2); // Hesapla ama henüz yazdirma
            auto stop_rec = std::chrono::high_resolution_clock::now();
            
            auto duration_us_rec = std::chrono::duration_cast<std::chrono::microseconds>(stop_rec - start_rec);
            rec_duration = duration_us_rec.count();
        } catch (const std::exception& e) {
            std::cerr << "An error occurred (Recursive): " << e.what() << '\n';
        }
    } else {
        cout << "Skipping Recursive (input too long)..." << endl;
    }

    // --- 3. SONUÇLARI YAZDIRMA (Istedigin Format) ---
    
    cout << "\n----------------------------------------------" << endl;
    cout << "FINAL RESULT" << endl;
    cout << "----------------------------------------------" << endl;
    
    // Önce Edit Distance sonucunu veriyoruz (DP sonucu güvenilir oldugu için onu baz aliyoruz)
    if (distance1 != -1) {
        cout << "-> Edit Distance: " << distance1 << endl;
    } else {
        cout << "-> Edit Distance: ERROR" << endl;
    }

    // Recursive hesaplandiysa ve sonuçlar tutmuyorsa uyari ver
    if (run_recursive && distance2 != -1 && distance1 != distance2) {
        cout << "   (Warning: Recursive result " << distance2 << " does not match DP!)" << endl;
    }

    cout << "\n----------------------------------------------" << endl;
    cout << "PERFORMANCE COMPARISON (Time)" << endl;
    cout << "----------------------------------------------" << endl;
    
    // Süreleri asagida veriyoruz
    if (dp_duration != -1) {
        cout << "-> Dynamic Programming : " << dp_duration << " microseconds" << endl;
    } else {
        cout << "-> Dynamic Programming : FAILED" << endl;
    }

    if (run_recursive) {
        if (rec_duration != -1) {
            cout << "-> Recursive           : " << rec_duration << " microseconds" << endl;
            
            // Opsiyonel: DP'nin kaç kat daha hizli oldugunu gösterelim
            if (rec_duration > 0 && dp_duration > 0) {
                 double speedup = (double)rec_duration / dp_duration;
                 cout << "   (DP was approx " << speedup << "x faster)" << endl;
            }
        } else {
            cout << "-> Recursive           : FAILED" << endl;
        }
    } else {
        cout << "-> Recursive           : SKIPPED" << endl;
    }
    cout << "==============================================\n" << endl;
}

// =========================================================================
//                  MAIN EXECUTION
// =========================================================================

int main() {
    string input1, input2;
    
    cout << "*************************************************" << endl;
    cout << "* EDIT DISTANCE ALGORITHM COMPARATOR       *" << endl;
    cout << "*************************************************" << endl;
    cout << "* Cikmak icin herhangi bir kelimeye 'exit' yazin. *" << endl;

    while (true) {
        cout << "\n-------------------------------------------------" << endl;
        
        // 1. Kelimeyi al
        cout << ">> Birinci kelimeyi girin: ";
        if (!getline(cin, input1)) break; // Input hatasi kontrolü
        if (input1 == "exit") break;

        // 2. Kelimeyi al
        cout << ">> Ikinci kelimeyi girin : ";
        if (!getline(cin, input2)) break;
        if (input2 == "exit") break;


        // Karsilastirmayi çalistir
        runComparison(input1, input2);
    }

    cout << "\nProgramdan cikiliyor. Iyi gunler!" << endl;
    return 0;
}
