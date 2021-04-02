int trap(int* height, int heightSize){
    if ((height == NULL) || (heightSize == 0)) {
        return 0;
    }

    int* leftHeight = (int*)malloc((sizeof(int) * heightSize));
    int* rightHeight = (int*)malloc((sizeof(int) * heightSize));

    for (int i = 0; i < heightSize; i++) {
        leftHeight[i] = 0;
        rightHeight[i] = 0;
    }
    for (int i = 1; i < heightSize - 1; i++) {
        leftHeight[i] = leftHeight[i - 1];
        if (leftHeight[i] < height[i - 1]) {
            leftHeight[i] = height[i - 1];
        }
    }
    for (int j = heightSize - 2; j > 0; j--) {
        rightHeight[j] = rightHeight[j + 1];
        if (rightHeight[j] < height[j + 1]) {
            rightHeight[j] = height[j + 1];
        }
    }

    int min = 0;
    int sum = 0;
    for (int i = 1; i < heightSize - 1; i++) {
        if (leftHeight[i] < rightHeight[i]) {
            min = leftHeight[i];
        } else {
            min = rightHeight[i];
        }
        if (min > height[i]) {
            sum += min - height[i];
        }
    }    
    return sum;
}