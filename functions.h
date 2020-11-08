//
// Created by nikit on 06.11.2020.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#ifndef VIGENERE_FUNCTIONS_H
#define VIGENERE_FUNCTIONS_H

#include <algorithm>
#include <iostream>
#include <string>
/** operation body */
struct operation
{
    std::string inputFileName = "";  ///< name of the input file which stores given text
    std::string outputFileName = ""; ///< name of the output file which will store encrypted/decrypted text
    std::string keyFileName = "";    ///< name of the file which contains the encryption key
    std::string message = "";        ///< text that is to be encrypted/decrypted
    std::string key = "";            ///< encryption key
    int msgLen = 0;                  ///< length of the given text
    int keyLen = 0;                  ///< length of the given encryption key
};

/** Function for decryption the text file.
  @param msgLen length of the given text
  @param encryptedMsg the encrypted message
  @param newKey the encryption key created in order to fit the length of the given text
  @return Function returns the decrypted text.
*/
std::string decryptor(int msgLen, std::string encryptedMsg, std::string newKey);

/** Function for encrypting the text file.
  @param msgLen length of the given text
  @param msg the given text which is to be encrypted
  @param newKey the encryption key created in order to fit the length of the given text
  @return Function returns the encrypted text.
*/
std::string encryptor(int msgLen, std::string msg, std::string newKey);

/** Function for generating the new key for it to fit the length of the given text.
  @param msgLen length of the given text
  @param keyLen length of the given encryption key
  @param key the given encryption key itself
  @return Function returns a new encryption key, which fits the length of the given text.
*/
std::string newKeyGen(int msgLen, int keyLen, std::string key);

/** Function for making sure that all the characters of the given text are uppercase.
  @param x a string which might contain lowercase characters
  @return Function returns a new string with all uppercase characters.
*/
std::string makeUpper(std::string x);

/** Function for making sure that the given text does not contain spaces.
  @param x a string which might contain spaces
  @return Function returns a new string with no spaces in it.
*/
std::string spaceEraser(std::string x);

#endif

#endif //VIGENERE_FUNCTIONS_H
