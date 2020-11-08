/** @file */

#include<iostream>
#include <fstream>
#include <string>
#include "functions.h"


int main (int argc, char* argv[]) {
    int flag {0}; // variable which controls the flow of the program
    for (int i = 1; i < argc; i++) {
        std::string temp = argv[i]; // temporary variable which is to identify command line switches
        if (temp == "--en") {
            flag = 1;
            break;
        } else if (temp == "--de") {
            flag = 2;
            break;
        } else if (temp == "--br") {
            flag = 3;
            break;
        } else {
            flag = 0;
        }
    }
    if (flag == 0) {
        std::cout << "NO MAIN SWITCH HAS BEEN PROVIDED - TERMINATED";
        return 1;
    }

    operation myOp; // creating variable of opeartion type to implement program

    if (flag == 1) {
        for (int i = 0; i < argc; i++) {
            std::string temp = argv[i];
            if (temp == "-i") {
                myOp.inputFileName = argv[i + 1];
//                myOp.inputFileName += ".txt";
            } else if (temp == "-o") {
                myOp.outputFileName = argv[i + 1];
//                myOp.outputFileName += ".txt";
            } else if (temp == "-k") {
                myOp.keyFileName = argv[i + 1];
//                myOp.keyFileName += ".txt";
            }
        }
        std::ifstream inputFile(myOp.inputFileName);   // opening given input file in read mode
        std::ofstream outputFile(myOp.outputFileName); // opening given output file in write mode
        std::ifstream keyFile(myOp.keyFileName);       // opening given file with encryption key in read mode
        if (inputFile && outputFile && keyFile) {
            std::getline(inputFile, myOp.message);
            std::getline(keyFile, myOp.key);
        } else {
            std::cout << "Program has been terminated. Could not open files." << std::endl;
        }
        inputFile.close();
        keyFile.close();
        myOp.message = makeUpper(myOp.message);
        myOp.message = spaceEraser(myOp.message);
        myOp.key = makeUpper(myOp.key);
        myOp.key = spaceEraser(myOp.key);
        myOp.msgLen = myOp.message.length();
        myOp.keyLen = myOp.key.length();
        myOp.key = newKeyGen(myOp.msgLen, myOp.keyLen, myOp.key);
        myOp.message = encryptor(myOp.msgLen, myOp.message, myOp.key);
        outputFile << myOp.message;
        outputFile.close();
        std::cout << "Program has been executed successfuly" << std::endl;
        return 0;
    } else if (flag == 2) {
        for (int i = 0; i < argc; i++)
        {
            std::string temp = argv[i];
            if (temp == "-i")
            {
                myOp.inputFileName = argv[i + 1];
//                myOp.inputFileName += ".txt";
            }
            else if (temp == "-o")
            {
                myOp.outputFileName = argv[i + 1];
//                myOp.outputFileName += ".txt";
            }
            else if (temp == "-k")
            {
                myOp.keyFileName = argv[i + 1];
//                myOp.keyFileName += ".txt";
            }
        }
        std::ifstream inputFile(myOp.inputFileName);   // opening given input file in read mode
        std::ofstream outputFile(myOp.outputFileName); // opening given output file in write mode
        std::ifstream keyFile(myOp.keyFileName);       // opening given file with encryption key in read mode
        if (inputFile && outputFile && keyFile)
        {
            std::getline(inputFile, myOp.message);
            std::getline(keyFile, myOp.key);
        } else {
            std::cout << "Program has been terminated. Could not open files." << std::endl;
            return 0;
        }
        inputFile.close();
        keyFile.close();
        myOp.message = makeUpper(myOp.message);
        myOp.message = spaceEraser(myOp.message);
        myOp.key = makeUpper(myOp.key);
        myOp.key = spaceEraser(myOp.key);
        myOp.msgLen = myOp.message.length();
        myOp.keyLen = myOp.key.length();
        myOp.key = newKeyGen(myOp.msgLen, myOp.keyLen, myOp.key);
        myOp.message = decryptor(myOp.msgLen, myOp.message, myOp.key);
        outputFile << myOp.message;
        outputFile.close();
        std::cout << "Program has been executed successfuly" << std::endl;
        return 0;
    }
    return 0;
}
