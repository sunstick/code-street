/*
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4
Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
*/
  
int search(string array[], const string &target, int size) { // iterative solution
    int lower = 0;
    int upper = size - 1;

    while (lower <= upper) {
        while (lower <= upper && array[upper] == "")
            upper--;

        if (lower > upper)
            return -1;

        int middle = (upper + lower) / 2;
        int temp = middle;

        while (array[middle] == "")
            middle++;
        if (array[middle] == target)
            return middle;
        if (array[middle] > target)
            upper = temp - 1;
        if (array[middle] < target)
            lower = middle + 1;
    }
    return -1;
}