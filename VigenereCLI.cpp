#include <bits/stdc++.h>

using namespace std;

int main(){
    setlocale(LC_ALL,"Rus");
    vector <char> all_chars;
    for (char cur_char = 'A';cur_char <= 'Z';cur_char++){
        all_chars.push_back(cur_char);
    }
    map <char,int> number_for_char;
    for (int i = 0;i < all_chars.size();i++){
        number_for_char[all_chars[i]] = i;
    }
    std::cout << "Введите сообщение, которое нужно зашифровать:\n";
    string text;
    getline(cin,text);
    std::cout << "Введите ключ шифрования:\n";
    string key;
    std::cin >> key;
    for (int i = 0;i < text.size();i++){
        if (text[i] >= 'a' && text[i] <= 'z'){
            text[i] = toupper(text[i]);
        }
    }
    for (int i = 0;i < key.size();i++){
        if (key[i] >= 'a' && key[i] <= 'z'){
            key[i] = toupper(key[i]);
        }
    }
    string pattern = "";
    int pos = 0;
    for (auto ch : text){
        if (ch >= 'A' && ch <= 'Z'){
            pattern += key[pos];
            pos++;
            if (pos == key.size()){
                pos = 0;
            }
            continue;
        }
        pattern += ch;
    }
    string encrypted_text = "";
    for (int i = 0;i < text.size();i++){
        if (text[i] >= 'A' && text[i] <= 'Z'){
            encrypted_text += all_chars[(number_for_char[text[i]] + number_for_char[pattern[i]]) % all_chars.size()];
            continue;
        }
        encrypted_text += text[i];
    }
    string decrypted_text = "";
    for (int i = 0;i < encrypted_text.size();i++){
        if (encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z'){
            decrypted_text += all_chars[(number_for_char[encrypted_text[i]] - number_for_char[pattern[i]] + all_chars.size()) % all_chars.size()];
            continue;
        }
        decrypted_text += encrypted_text[i];
    }
    std::cout << "Зашифрованное сообщение - " << encrypted_text << "\n";
    std::cout << "Расшифрованное сообщение - " << decrypted_text;
}