//
//  main.cpp
//  Password Generator
//
//  Created by Tan Tran on 3/16/26.
//

#include <iostream>
#include <string>
#include <random>

int main(int argc, const char * argv[]) {
    
    int passLength;
    std::cout << "Enter Password length: " << std::endl;
    std::cin >> passLength;
    
    char choice;
    
    std::cout << "Include uppercase? (y/n): " << std::endl;
    std::cin >> choice;
    bool isIncludeUppercase = (choice == 'y' || choice == 'Y');
    
    std::cout << "Include lowercase? (y/n): " << std::endl;
    std::cin >> choice;
    bool isIncludeLowercase = (choice == 'y' || choice == 'Y');
    
    std::cout << "Include Numbers? (y/n): " << std::endl;
    std::cin >> choice;
    bool isIncludeNumbers = (choice == 'y' || choice == 'Y');
    
    std::cout << "Include symbols? (y/n): " << std::endl;
    std::cin >> choice;
    bool isIncludeSymbols = (choice == 'y' || choice == 'Y');
    
    std::string pool;

    if(isIncludeUppercase) pool += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(isIncludeLowercase) pool += "abcdefghijklmnopqrstuvwxyz";
    if(isIncludeNumbers) pool += "0123456789";
    if(isIncludeSymbols) pool += "!@#$%^&*";
    if(pool.empty()){
        std::cout << "Error: Select at least one option!\n" << std::endl;
        return 0;
    }
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, pool.size() - 1);
    std::string password = "";
    for (int i =0; i < passLength; i++){
        
        password += pool[dist(rng)];
    }
    
    std::cout << "Password: " << password << "\n" << std::endl;
    
    return 0;
}

