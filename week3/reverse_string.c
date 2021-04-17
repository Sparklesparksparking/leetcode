void Helper(char* s, int left, int right) {
    if (left >= right) {
        return;
    }

    char tmp;
    tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;

    Helper(s, left + 1, right - 1);
}

void reverseString(char* s, int sSize){
    if (s == NULL || sSize == 0) {
        return;
    }
    Helper(s, 0, sSize - 1);
}