#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

vector<string> kelimeler = {"izmir", "ankara", "kayseri", "gaziantep", "hatay", "denizli", "malatya", "manisa", "trabzon", "sivas"};

string kelime_secim() {
    srand(time(nullptr));
    int index = rand() % kelimeler.size();
    return kelimeler[index];
}

void adam_asmaca(string kelime) {
    const int max_tahmin = 10;
    int kalan_tahmin = max_tahmin;
    string dogru_tahmin;
    string gizli_kelime(kelime.length(), '_ ');

    while (kalan_tahmin > 0 && gizli_kelime != kelime) {
        char tahmin;
        cout << "Kalan tahmin hakk�n�z: " << kalan_tahmin << endl;
        cout << "Bir harf tahmin edin : ";
        cin >> tahmin;

        if (dogru_tahmin.find(tahmin) != string::npos) {
            cout << "Bu harfi daha �nce tahmin ettiniz. Ba�ka bir harf giriniz." << endl;
            continue;
        }

        bool dogru = false;
        for (int i = 0; i < kelime.length(); i++) {
            if (kelime[i] == tahmin) {
                gizli_kelime[i] = tahmin;
                dogru = true;
            }
        }

        if (dogru) {
            cout << "Kelimenin i�inde bu harf var. Tebrikler!" << endl;
            kalan_tahmin--;
        } else {
            cout << "Yanl�� tahmin. Tekrar deneyiniz." << endl;
            kalan_tahmin--;
        }

        dogru_tahmin += tahmin;
        cout << "Tahmin edilen kelime: " << gizli_kelime << endl;
    }

    if (gizli_kelime == kelime) {
        cout << "Tebrikler! Kelimeyi do�ru tahmin ettiniz. Kelime: " << kelime << endl;
    } else {
        cout << "Maalesef, tahmin hakk�n�z bitti. Do�ru kelime: " << kelime << endl;
    }
}

int main()
{
    cout << "----- Sehir Tahmin Oyunu  -----" << endl;
    cout << "10 hakkin�z var. Ba�arilar..." << endl;
    string kelime = kelime_secim();
    adam_asmaca(kelime);
    return 0;
}
