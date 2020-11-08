//
// Created by nikit on 06.11.2020.
//

#include "functions.h"
#include <algorithm>
#include <iostream>
#include <string>


/** Function for decryption the text file.
  @param msgLen length of the given text
  @param encryptedMsg the encrypted message
  @param newKey the encryption key created in order to fit the length of the given text
  @return Function returns the decrypted text.
*/
std::string decryptor(int msgLen, std::string encryptedMsg, std::string newKey)
{
    std::string decryptedMsg = "";
    for (int i = 0; i < msgLen; ++i)
    {
        decryptedMsg += (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    }
    return decryptedMsg;
}

/** Function for encrypting the text file.
  @param msgLen length of the given text
  @param msg the given text which is to be encrypted
  @param newKey the encryption key created in order to fit the length of the given text
  @return Function returns the encrypted text.
*/
std::string encryptor(int msgLen, std::string msg, std::string newKey)
{
    std::string encryptedMsg = "";
    for (int i = 0; i < msgLen; i++)
    {
        encryptedMsg += ((msg[i] + newKey[i]) % 26) + 'A';
    }
    return encryptedMsg;
}

/** Function for generating the new key for it to fit the length of the given text.
  @param msgLen length of the given text
  @param keyLen length of the given encryption key
  @param key the given encryption key itself
  @return Function returns a new encryption key, which fits the length of the given text.
*/
std::string newKeyGen(int msgLen, int keyLen, std::string key)
{
    std::string newKey = "";
    for (int i = 0, j = 0; i < msgLen; ++i, ++j)
    {
        if (j == keyLen)
        {
            j = 0;
        }
        newKey += key[j];
    }
    return newKey;
}

/** Function for making sure that all the characters of the given text are uppercase.
  @param x a string which might contain lowercase characters
  @return Function returns a new string with all uppercase characters.
*/
std::string makeUpper(std::string x)
{
    char temp;
    for (int unsigned i = 0; i < x.length(); i++)
    {
        temp = x[i];
        temp = toupper(temp);
        x[i] = temp;
    }
    return x;
}

/** Function for making sure that the given text does not contain spaces.
  @param x a string which might contain spaces
  @return Function returns a new string with no spaces in it.
*/
std::string spaceEraser(std::string x)
{
    x.erase(remove(x.begin(), x.end(), ' '), x.end());
    x.erase(
            remove(x.begin(), x.end(), '!'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '?'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '_'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '-'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '/'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '|'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '\\'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '>'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '<'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '"'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '\''),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), ':'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), ';'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), ']'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '}'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '['),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '{'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), '.'),
            x.end());
    x.erase(
            remove(x.begin(), x.end(), ','),
            x.end());
    return x;
}
