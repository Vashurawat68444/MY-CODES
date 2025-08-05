//banking management using semaphores and monitor.
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore>  // C++20 feature
#include <vector>
#include <chrono>

using namespace std;

// Monitor-style class for Bank Account
class BankMonitor {
private:
    int balance;
    mutex mtx;
    condition_variable cv;

public:
    BankMonitor(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount, int id) {
        unique_lock<mutex> lock(mtx);
        balance += amount;
        cout << "User " << id << " deposited Rs. " << amount << ". New balance: Rs. " << balance << endl;
        cv.notify_all();
    }

    void withdraw(int amount, int id) {
        unique_lock<mutex> lock(mtx);
        while (balance < amount) {
            cout << "User " << id << " waiting to withdraw Rs. " << amount << ". Current balance: Rs. " << balance << endl;
            cv.wait(lock);
        }
        balance -= amount;
        cout << "User " << id << " withdrew Rs. " << amount << ". New balance: Rs. " << balance << endl;
    }
};

// C++20 counting_semaphore
std::counting_semaphore<3> semaphore(3);  // allows 3 concurrent users

void userTask(BankMonitor& bank, int id) {
    semaphore.acquire();  // wait
    this_thread::sleep_for(chrono::milliseconds(100));

    bank.deposit(100 * id, id);
    this_thread::sleep_for(chrono::milliseconds(100));
    bank.withdraw(50 * id, id);

    semaphore.release();  // signal
}

int main() {
    BankMonitor bank(500); // Initial balance

    vector<thread> users;
    for (int i = 1; i <= 6; ++i) {
        users.emplace_back(userTask, ref(bank), i);
    }

    for (auto& t : users)
        t.join();

    return 0;
}
