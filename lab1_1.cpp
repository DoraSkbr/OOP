#include <iostream>
#include <locale>
using namespace std;
class Stock {
private:
    string company;
    int shares;
    double share_val;
    double total_val;
    double set_tot() { return shares * share_val; };
public:
    void acquire(string name, int kol, double cena);
    void buy(int kol);
    void sell(int kol);
    void show();
    void update(double cena);
};
void Stock::buy(int kol) {
    if (kol > 0) shares = shares + kol;
    else cout << "Func Buy: Vvedeno otric zhachenie!" << "\n\n";
};
void Stock::sell(int kol) {
    if (kol > 0 && kol < shares) shares = shares - kol;
    else cout << "Func Sell: Vvedeni nevernie dannie!" << "\n\n";
};
void Stock::update(double cena) {
    share_val = cena;
    total_val = set_tot();
};
void Stock::acquire(string name, int kol, double cena) {
    company = name;
    shares = kol;
    share_val = cena;
    total_val = set_tot();
};
void Stock::show() {
    cout << "Company: " << company << "\n";
    cout << "Company shares: " << shares << "\n";
    cout << "Share value: " << share_val << "\n";
    cout << "Total shares value: " << total_val << "\n\n";
};
int main() {
    Stock com1, com2;
    com1.acquire("Tesla", 1000, 30);
    com2.acquire("Microsoft", 2000, 60);
    com1.show();
    com2.show();
    com1.update(20);
    com1.show();
    com1.buy(200);
    com1.show();
    com1.sell(100);
    com1.show();
    return 0;
}
