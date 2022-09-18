#pragma once
#include <string>
using namespace std;
class modRoutingCipher
{
public:
modRoutingCipher(const int &skey); 
string encrypt(const string &open_text); 
string decrypt(const string &cipher_text); 
modRoutingCipher()=delete;
private:
int key;
};