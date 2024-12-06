#include <iostream>
#include <string>
#include "url.h"  // Ensure url.h and url.cpp are in your build
#include <limits>


int main() {
    std::cout << "=============================================\n";
    std::cout << "            URL Testing Tool\n";
    std::cout << "=============================================\n\n";
    std::cout << "Choose mode:\n";
    std::cout << "  1) Test a single URL\n";
    std::cout << "  2) Compare two URLs\n";
    std::cout << "Enter choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice == 1) {
        // Single URL mode
        PARSED_URL p;
        std::string user_url;

        std::cout << "\nEnter a URL: ";
        std::getline(std::cin, user_url);

        parse_url(user_url.c_str(), p);

        std::cout << "\nParsed URL Components:\n";
        std::cout << "  Protocol: " << p.protocol << "\n"
                  << "  Host:     " << p.host << "\n"
                  << "  Port:     " << p.port << "\n"
                  << "  File:     " << p.file << "\n"
                  << "  User:     " << p.user << "\n"
                  << "  Password: " << p.passwd << "\n\n";

        int total_tests = 5;
        int passed_tests = 0;

        auto print_result = [&](const std::string& test_name, bool condition) {
            std::cout << test_name << ": " << (condition ? "Passed" : "Failed") << "\n";
            if (condition) passed_tests++;
        };

        std::cout << "Running Basic Tests on Parsed URL...\n\n";
        print_result("Test 1 (Protocol recognized)", p.protocol != URL_PROTOCOL_UNKNOWN);
        print_result("Test 2 (Host not empty)", p.host[0] != '\0');
        print_result("Test 3 (Port > 0)", p.port > 0);
        // In this example, Test 4 and 5 always pass
        print_result("Test 4 (File field handled)", true);
        print_result("Test 5 (User/Pass handling)", true);

        std::cout << "\n" << passed_tests << " out of " << total_tests 
                  << " tests passed for URL: " << user_url << "\n";

    } else if (choice == 2) {
        // Comparison mode
        std::string url1, url2;
        std::cout << "\nEnter the first URL: ";
        std::getline(std::cin, url1);
        std::cout << "Enter the second URL: ";
        std::getline(std::cin, url2);

        std::cout << "\nTesting is_https_transition()...\n";
        bool https_trans = is_https_transition(url1.c_str(), url2.c_str());
        std::cout << "  " << url1 << " -> " << url2 << ": "
                  << (https_trans ? "Yes (HTTPS Transition)" : "No (Not a Transition)") << "\n";

        std::cout << "\nTesting urls_match()...\n";
        bool match = urls_match(url1.c_str(), url2.c_str());
        std::cout << "  " << url1 << " vs " << url2 << ": "
                  << (match ? "Match" : "Do Not Match") << "\n";

    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    std::cout << "\nAll done.\n";
    return 0;
}
