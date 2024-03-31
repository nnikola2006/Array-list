#include <iostream>
#include <cctype>
using std::cout, std::cin, std::endl;
using std::string;

template <typename T>
class ArrayList{
private:
    T *arr;
    int size;
    int capacity;
public:
    ArrayList(const int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->arr = new T[capacity];

        for(int i = 0; i < capacity; i++){
            arr[i] = 0;
        }
    }
    void add(const T element){
        if(size < capacity){
            arr[size] = element;
            size++;
        }
        else{
            const int newCapacity = capacity * 2;
            T *temp;
            try{
                temp = new T[capacity];

                for(int i = 0; i < size; i++){
                    temp[i] = arr[i];
                }
                temp[size] = element;
            }
            catch(std::bad_alloc &ba){
                delete[] temp;
                cout << "Bad allocation: " << ba.what() << endl;
                return;
            }
            
            delete[] arr;
            arr = temp;
            capacity = newCapacity;
            size++;
        }
    }
    void remove(const int index){
        if(index < 0 || index >= size){
            cout << "Index out of bounds" << endl;
            return;
        }
        for(int i = index; i < size; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    void get(const int index) const{
        if(index >= 0 && index < size){
            cout << "Element at index " << index << " is " << arr[index] << endl;
        }
        else{
            cout << "Index out of bounds" << endl;
        }
    }
    void print() const{
        if(size == 0){
            cout << "List is empty" << endl;
        }
        for(int i = 0; i < size; i++){
            cout << arr[i] << ", ";
        }
    }
    void fullPrint() const{
        cout << "Capacity: " << capacity << endl;
        cout << "Size: " << size << endl;
        cout << "Elements: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << ", ";
        }
    }
};

int arrayType(){
    unsigned int type = 0;
    while(type < 1 || type > 5){
        cout << "\033[2J\033[01;1H"; // works for vscode
        cout << "Welcome to the ArrayList program" << endl;
        cout << "Choose what type of array do you want?: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Double" << endl;
        cout << "3. Char" << endl;
        cout << "4. String" << endl;
        cout << "5. Exit" << endl;
    }
    
    return type;
}

template <typename T>
void createArrayType(){
    unsigned int capacity = 0;
    capacityInput(capacity);
    ArrayList<T> list(capacity);
}

void capacityInput(unsigned int &capacity){
    cout << "How much capacity does the list have?: ";
    cin >> capacity;
}

void printMenu(){
    cout << endl;
    cout << "Choose what you want to do with the list: " << endl;
    cout << "1. Add element" << endl;
    cout << "2. Remove element" << endl;
    cout << "3. Get element" << endl;
    cout << "4. Print elements" << endl;
    cout << "5. Full print of the list" << endl;
    cout << "6. Exit" << endl;
}

int main(){
    unsigned int type = arrayType();
    if(type == 5){
        cout << "Exiting..." << endl;
        return 0;
    }

    unsigned int capacity = 0;
    capacityInput(capacity);
    ArrayList<int> list(capacity);

    unsigned int option = 0;
    while(option != 6){
        printMenu();
        cin >> option;
        cout << "\033[2J\033[01;1H"; // works for vscode

        if(!(option > 0 && option <= 5)){
            cout << "Invalid option" << endl;
        }
        switch(option){
            case 1:{
                cout << "Enter the element you want to add: ";
                int element;
                 cin >> element;
                list.add(element);
                break;
            }
            case 2:{
                cout << "Enter the index of the element you want to remove: ";
                int index;
                cin >> index;
                list.remove(index);
                break;
            }
            case 3:{
                cout << "Enter the index of the element you want to get: ";
                int index;
                cin >> index;
                list.get(index);
                break;
            }
            case 4:{
                cout << "The elemenets of the list are: " << endl;
                list.print();
                break;
            }
            case 5:{
                cout << "Full print of the list is: " << endl;
                list.fullPrint();
                break;
            }
            case 6:{
                cout << "Exiting..." << endl;
                break;
            }
        }
    }

    return 0;
}