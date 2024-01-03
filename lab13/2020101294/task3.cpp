#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Book {
public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}

    void displayInfo() const {
        std::cout << "������" << title << "�����ߣ�" << author << std::endl;
    }

    const std::string& getTitle() const {
        return title;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_shared<Book>(title, author));
        std::cout << "�ɹ�����鼮��" << title << std::endl;
    }

    void removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(),
                                 [&title](const std::shared_ptr<Book>& book) {
                                     return book->getTitle() == title;
                                 });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "�ɹ�ɾ���鼮��" << title << std::endl;
        } else {
            std::cout << "δ�ҵ�Ҫɾ�����鼮��" << title << std::endl;
        }
    }

    void displayBooks() const {
        std::cout << "ͼ����е��鼮��" << std::endl;
        for (const auto& book : books) {
            book->displayInfo();
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    Library library;

    int choice;

    do {
        std::cout << "\nͼ��ݹ���ϵͳ\n";
        std::cout << "1. ����鼮\n";
        std::cout << "2. ɾ���鼮\n";
        std::cout << "3. ��ʾ�����鼮\n";
        std::cout << "0. �˳�\n";
        std::cout << "����������ѡ��: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author;
                std::cout << "����������: ";
                std::cin >> title;
                std::cout << "����������: ";
                std::cin >> author;
                library.addBook(title, author);
                break;
            }
            case 2: {
                std::string title;
                std::cout << "������Ҫɾ��������: ";
                std::cin >> title;
                library.removeBook(title);
                break;
            }
            case 3:
                library.displayBooks();
                break;
            case 0:
                std::cout << "�����˳�\n";
                break;
            default:
                std::cout << "��Ч��ѡ������������\n";
        }

    } while (choice != 0);

    return 0;
}