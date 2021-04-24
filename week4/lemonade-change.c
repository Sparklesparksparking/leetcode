bool lemonadeChange(int* bills, int billsSize){
    if (bills == NULL || billsSize == 0) {
        return false;
    }
    int five = 0;
    int ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five == 0) {
                return false;
            } else {
                five--;
            }
            ten++;
        }else {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}