#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Chuyển struct Food thành class Food (sử dụng từ khóa public:)
class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin >> ws, name); // ws giúp xóa bộ nhớ đệm (khoảng trắng/xuống dòng thừa)
        cout << "Nhap gia: ";
        cin >> price;
        quantity = 0;
    }

    void display() {
        cout << name << " - " << price << " (" << quantity << ")" << endl;
    }
};

int main() {
    // 2. Yêu cầu: Tạo danh sách chứa 3 món ăn và nhập thông tin
    int n = 3;
    vector<Food> menu(n);

    for (int i = 0; i < n; i++) {
        menu[i].input();
    }

    // In danh sách các món ăn
    cout << "\n=== Danh sach mon an ===" << endl;
    for (int i = 0; i < n; i++) {
        menu[i].display();
    }

    // Tìm món ăn theo tên
    string searchName;
    cout << "\nNhap ten mon an can tim: ";
    getline(cin >> ws, searchName);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (menu[i].name == searchName) {
            cout << "Da tim thấy món: ";
            menu[i].display();
            found = true;

            // Cập nhật giá của món ăn tìm thấy
            double newPrice;
            cout << "Nhap gia moi cho mon " << menu[i].name << ": ";
            cin >> newPrice;
            menu[i].price = newPrice;

            cout << "Sau khi cap nhat gia: ";
            menu[i].display();
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!" << endl;
    }

    return 0;
}