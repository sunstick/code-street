/*
There are two rows of numbers, each row has ten numbers.
Given the first row, output the second row such that each element in the second row is the number of times that the corresponding first row element appears in the second row.
*/

#define len 10

int top[len];
int bottom[len];
bool success;

int *getBottom();
void setNextBottom();
int getFrequecy(int num);

void NumberTB() {
    success = false;

    for (int i = 0; i < len; i++) {
        top[i] = i;
    }
}

int *getBottom() {
    int i = 0;
    while (!success) {
        i++;
        setNextBottom();
    }
    return bottom;
}

void setNextBottom() {
    bool reB = true;
    for (int i = 0; i < len; i++) {
        int frequecy = getFrequecy(top[i]);
        if (bottom[i] != frequecy) {
            bottom[i] = frequecy;
            reB = false;
        }
    }
    success = reB;

    for (int i = 0; i < len; i++) {
        cout << bottom[i] << " ";
    }
    cout << endl;
}

int getFrequecy(int num) { //此处的num 即指上排的数i
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (bottom[i] == num)
            count++;
    }
    return count; //count 即对应frequecy
}

void test() {
    NumberTB();
    int *result = getBottom();

    cout << "---------------" << endl;

    for (int i = 0; i < len; i++)
        cout << *result++ << " ";
    cout << endl;
}
