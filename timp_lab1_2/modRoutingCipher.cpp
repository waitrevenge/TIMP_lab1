#include "modRoutingCipher.h"
#include <locale>
#include <codecvt>
modRoutingCipher::modRoutingCipher(const int &skey)
{
    this->key = skey;
}
string modRoutingCipher::encrypt(const string &open_text)
{
    setlocale(LC_ALL, "Russian");
    locale loc("ru_RU.UTF-8");
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring op = codec.from_bytes(open_text);
    int LENGTH = op.size();
    wchar_t ch[LENGTH+1];
    int KEY = key-1;
    int k = 0;
    int i = 0;
    while(KEY>=0) {
        k = KEY;
        while(k<LENGTH) {
            if(k + key > LENGTH) {
                break;
            }
            k = k + key;
        }
        while(k>=0) {
            if(k!= LENGTH) {
                ch[i] = op[k];
                i++;
            }
            k = k - key;
        }
        KEY--;
    }
    ch[LENGTH] = '\0';
    op = wstring(ch);
    string str = codec.to_bytes(op);
    return str;
}
string modRoutingCipher::decrypt(const string &open_text)
{
    setlocale(LC_ALL, "Russian");
    locale loc("ru_RU.UTF-8");
    wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring op = codec.from_bytes(open_text);
    int LENGTH = op.size();
    wchar_t ch [LENGTH+1];
    int Mod = (LENGTH-1)/key;
    int Div = (LENGTH-1)/key+(((LENGTH-1)%key)>0);
    int colichestvonex = Div*key - LENGTH;
    int colichestvoxv = key - colichestvonex;
    int KEY = LENGTH-1;
    int key1 = key;
    int i = 0, j = 0, k = 0, y = 0;
    if(colichestvonex==0) {
        key1 = 0;
        while(key1<Div) {
            k = KEY;
            while(k>=0) {
                ch[y] = op[k];
                y++;
                k = k - Div;
            }
            key1++;
            KEY--;
        }
    } else {
        while(key1>=0) {
            k = KEY;
            while((j<colichestvoxv) && (k>=0)) {
                ch[y] = op[k];
                y++;
                k = k - Div;
                j++;
                i = 0;
            }
            while((i<colichestvonex) && (k>=0)) {
                ch[y] = op[k];
                y++;
                k = k - Mod;
                i++;
                j = 0;
            }
            KEY--;
            key1--;
        }
    }
    ch[LENGTH] = '\0';
    op = wstring(ch);
    string str = codec.to_bytes(op);
    return str;
}
