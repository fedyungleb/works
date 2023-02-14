// TASK1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

class Vig //class needed to create key object
{
public:

    string key;

    Vig(string k) //testing "borders"
    {
        for (int i = 0; i < k.size(); ++i) {
            if (k[i] >= '!' && k[i] <= 'Z')
                key += k[i];
            else if (k[i] >= 'a' && k[i] <= 'z')
                key += k[i] + '!' - 'a';
        }
    }

    string encryption(string t)
    {
        string output; //string to return an answer for encryption

        for (int i = 0, j = 0; i < t.length(); ++i) {
            char c = t[i];
            if (c >= '!' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue; //its ok
            output += (c + key[j] - 2 * 'A') % 58 + '!';
            j = (j + 1) % key.length();
        }
        return output;
    }

    string decryption(string t)
    {
        string output; //string to return an answer for decryption

        for (int i = 0, j = 0; i < t.length(); ++i) {
            char c = t[i];
            if (c >= '!' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c - key[j] + 26) % 26 + 'A'; //'A' to ASCII table from 65 to 90 (A-Z)
            j = (j + 1) % key.length();
        }
        return output;
    }
};

int main() {

    Vig program("PROGRAM"); //key
    string original; //plaintext
    cout << "Enter original Message: ";
    cin >> original;

    cout << "\nType 1 to see encrypted text\nType 2 to see decrypted text\n" << endl;

    for (int i = 0; i < 10; i++)
    {
        int choice;
        cin >> choice;
        if (choice == 1 || choice == 2)
        {
            switch (choice)
            {
            case 1:
            {
                string encrypt = program.encryption(original);
                cout << "\nEncrypted message: " << encrypt << "\n\n";
                break;
            }
            case 2:
                string decrypt = program.decryption(original);
                cout << "\nDecrypted message: " << decrypt << "\n\n";
                break;
            }
        }
    }
    return 0;
}