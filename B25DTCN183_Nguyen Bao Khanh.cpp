#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int id;         // ma sinh vien
    string name;    // ten sinh vien
    float score;    // diem trung binh

    // ham tao co tham so
    Student(int _id, string _name, float _score) {
        id = _id;
        name = _name;
        score = _score;
    }

    // ham hien thi thong tin
    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Diem: " << score << endl;
    }
};

// them sinh vien
void addStudent(Student* a[], int &n, int &nextId) {
    string name;
    float score;

    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);

    cout << "Nhap diem trung binh: ";
    cin >> score;

    a[n] = new Student(nextId, name, score);
    n++;
    nextId++;

    cout << "Them sinh vien thanh cong!" << endl;
}

// hien thi danh sach
void showStudents(Student* a[], int n) {
    if (n == 0) {
        cout << "Danh sach sinh vien rong!" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        a[i]->printInfo();
    }
}

// cap nhat diem
void updateStudent(Student* a[], int n) {
    int id;
    cout << "Nhap ma sinh vien can cap nhat: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (a[i]->id == id) {
            cout << "Nhap diem moi: ";
            cin >> a[i]->score;
            cout << "Cap nhat thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay sinh vien!" << endl;
}

// xoa sinh vien
void deleteStudent(Student* a[], int &n) {
    int id;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (a[i]->id == id) {
            delete a[i];

            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }

            n--;
            cout << "Xoa sinh vien thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay sinh vien!" << endl;
}

int main() {
    Student* students[100]; // mang sinh vien toi da 100
    int count = 0;          // so luong sinh vien
    int nextId = 1001;      // ma sinh vien tu dong tang
    int choice;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Hien thi danh sach" << endl;
        cout << "3. Cap nhat diem" << endl;
        cout << "4. Xoa sinh vien" << endl;
        cout << "5. Thoat" << endl;
        cout << "----------------" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, count, nextId);
            break;
        case 2:
            showStudents(students, count);
            break;
        case 3:
            updateStudent(students, count);
            break;
        case 4:
            deleteStudent(students, count);
            break;
        case 5:
            cout << "Thoat chuong trinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 5);
    return 0;
}

