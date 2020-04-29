#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class FirstUnique1 {
   private:
    vector<int> vec;
    unordered_map<int, int> hmap;

   public:
    FirstUnique1(vector<int>& nums) {
        vec = nums;
        for (int i : nums) {
            hmap[i]++;
        }
    }

    int showFirstUnique() {
        for (auto i : vec) {
            if (hmap[i] == 1)
                return i;
        }
        return -1;
    }

    void add(int value) {
        vec.push_back(value);
        hmap[value]++;
    }
};

class FirstUnique {
   private:
    list<int> l;
    unordered_map<int, int> hmap;

   public:
    FirstUnique(vector<int>& nums) {
        for (int i : nums) {
            if (!hmap[i])
                l.push_back(i);
            else if (l.front() == i)
                l.pop_front();

            hmap[i]++;
        }
    }

    int showFirstUnique() {
        int firstUnique = l.front();
        if (hmap[firstUnique] == 1)
            return firstUnique;
        else
            return -1;
    }

    void add(int value) {
        if (l.front() == value)
            l.pop_front();
        else if (!hmap[value])
            l.push_back(value);

        hmap[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

int main(int argc, char** argv) {
    vector<int> nums = {2, 3, 5};
    FirstUnique* firstUnique = new FirstUnique(nums);
    firstUnique->showFirstUnique();  // return 2
    cout << firstUnique->showFirstUnique() << endl;
    firstUnique->add(5);             // the queue is now [2,3,5,5]
    firstUnique->showFirstUnique();  // return 2
    cout << firstUnique->showFirstUnique() << endl;
    firstUnique->add(2);             // the queue is now [2,3,5,5,2]
    firstUnique->showFirstUnique();  // return 3
    cout << firstUnique->showFirstUnique() << endl;
    firstUnique->add(3);             // the queue is now [2,3,5,5,2,3]
    firstUnique->showFirstUnique();  // return -1
    cout << firstUnique->showFirstUnique() << endl;
    cout << endl;

    nums = {7, 7, 7, 7, 7, 7};
    FirstUnique firstUnique2 = FirstUnique(nums);
    firstUnique2.showFirstUnique();  // return -1
    cout << firstUnique2.showFirstUnique() << endl;
    firstUnique2.add(7);             // the queue is now [7,7,7,7,7,7,7]
    firstUnique2.add(3);             // the queue is now [7,7,7,7,7,7,7,3]
    firstUnique2.add(3);             // the queue is now [7,7,7,7,7,7,7,3,3]
    firstUnique2.add(7);             // the queue is now [7,7,7,7,7,7,7,3,3,7]
    firstUnique2.add(17);            // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
    firstUnique2.showFirstUnique();  // return 17
    cout << firstUnique2.showFirstUnique() << endl;
    cout << endl;

    nums = {809};
    FirstUnique firstUnique3 = FirstUnique(nums);
    firstUnique3.showFirstUnique();  // return 809
    cout << firstUnique3.showFirstUnique() << endl;
    firstUnique3.add(809);           // the queue is now [809,809]
    firstUnique3.showFirstUnique();  // return -1
    cout << firstUnique3.showFirstUnique() << endl;
    cout << endl;

    return 0;
}