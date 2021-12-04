#include <iostream>
using namespace std;

class Stock {
private:
    string Name_Company;
    int Kol_vo_Stock;
    float Price_Stock;
    float Sum;
public:
    Stock(string Name, int Kol, float Price) {
        Name_Company = Name;
        Kol_vo_Stock = Kol;
        Price_Stock = Price;
        set_tot();
    }
    void set_tot() {
        Sum = Kol_vo_Stock * Price_Stock;
    }
    void show() {
        cout << "Name Company = " << Name_Company << endl << "Kol-vo Stock = " << Kol_vo_Stock << endl << "Price one Stock = " << Price_Stock << endl << "Sum Price Stock = " << Sum << endl << endl;
    }

    void buy(int x) {
        if (x > 0) {
            Kol_vo_Stock = Kol_vo_Stock + x;
            set_tot();
        }
    }

    void sell(int y) {
        if (y > 0 && y <= Kol_vo_Stock) {
            Kol_vo_Stock = Kol_vo_Stock - y;
            set_tot();
        }
    }

    void update(float k) {
        Price_Stock = k;
        set_tot();
    }

    ~Stock() {

    }
};

int main()
{
    Stock Packet_Stock_1("Company 1", 30, 14000);
    Packet_Stock_1.show();

    Stock Packet_Stock_2("Company 2", 25, 11450);
    Packet_Stock_2.show();

    Stock Packet_Stock_3("Company 3", 15, 22340);
    Packet_Stock_3.show();

    cout << "Function Buy:" << endl;
    Packet_Stock_1.buy(20);
    Packet_Stock_1.show();

    cout << "Function Sell:" << endl;
    Packet_Stock_2.sell(25);
    Packet_Stock_2.show();

    cout << "Function Update:" << endl;
    Packet_Stock_3.update(31980);
    Packet_Stock_3.show();
    return 0;
}
