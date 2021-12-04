#include <iostream>
#include <iomanip>
using namespace std;

class Abiturients {
private:
    string Surname, Name, Patronymic, Adress;
    int Ocenka_1, Ocenka_2, Ocenka_3;
public:
    Abiturients(string SN, string N, string PN, string A, int O_1, int O_2, int O_3) {
        Surname = SN;
        Name = N;
        Patronymic = PN;
        Adress = A;
        Ocenka_1 = O_1;
        Ocenka_2 = O_2;
        Ocenka_3 = O_3;
    }
    void get() {
        cout << setw(10) << Surname << " " << setw(10) << Name << " " << setw(15) << Patronymic << "  " << "Ocenki: " << Ocenka_1 << ", " << Ocenka_2 << ", " << Ocenka_3 << endl;
    }
    void f1() {
        if (Ocenka_1 < 3 || Ocenka_2 < 3 || Ocenka_3 < 3) {
            cout << setw(10) << Surname << " " << setw(10) << Name << " " << setw(15) << Patronymic << "  " << "Ocenki: " << Ocenka_1 << ", " << Ocenka_2 << ", " << Ocenka_3 << endl;
        }
    }

    void f2() {
        if (Ocenka_1 + Ocenka_2 + Ocenka_3 >= 10) {
            cout << setw(10) << Surname << " " << setw(10) << Name << " " << setw(15) << Patronymic << "  " << "Ocenki: " << Ocenka_1 << ", " << Ocenka_2 << ", " << Ocenka_3 << endl;
        }
    }
    void f3() {
        if (Ocenka_1 + Ocenka_2 + Ocenka_3 <= 15 && Ocenka_1 + Ocenka_2 + Ocenka_3 >= 13) {
            cout << setw(10) << Surname << " " << setw(10) << Name << " " << setw(15) << Patronymic << "  " << "Ocenki: " << Ocenka_1 << ", " << Ocenka_2 << ", " << Ocenka_3 << endl;
        }
    }
    void f4() {
        if (Ocenka_1 + Ocenka_2 + Ocenka_3 <= 12 && Ocenka_1 + Ocenka_2 + Ocenka_3 >= 11) {
            cout << setw(10) << Surname << " " << setw(10) << Name << " " << setw(15) << Patronymic << "  " << "Ocenki: " << Ocenka_1 << ", " << Ocenka_2 << ", " << Ocenka_3 << endl;
        }
    }
    ~Abiturients() {

    }
};

int main()
{
    Abiturients Abiturient[5]{
        Abiturients("Lanzov","Vechislav","Andreevich","Lenian 92",5,5,4),
        Abiturients("Gorko","Maxsim","Vladimirovich","Poza 89",4,4,3),
        Abiturients("Urban","Michail","Andreevich","Klinova 15",3,2,4),
        Abiturients("Huchan","Sergej","Alexandrovich","Lomonosova 113",3,2,2),
        Abiturients("Monko","Alexsandor","Alexandrovich","Nagibina 5",5,3,5)
    };
    for (int i = 0; i < 5; i++) {
        Abiturient[i].get();
    }

    cout << endl << "Spisok abiturientiw s neydovketvoritelnimi ocenkami:" << endl;
    for (int i = 0; i < 5; i++) {
        Abiturient[i].f1();
    }
    cout << endl << "Spisok abiturientiw s summoi ballow ne menhe 10:" << endl;
    for (int i = 0; i < 5; i++) {
        Abiturient[i].f2();
    }
    cout << endl << "Spisok abiturientiw s prohodnim ballom:" << endl;
    for (int i = 0; i < 5; i++) {
        Abiturient[i].f3();
    }
    cout << endl << "Spisok abiturientiw s polyprohodnim ballom:" << endl;
    for (int i = 0; i < 5; i++) {
        Abiturient[i].f4();
    }
    return 0;
}
