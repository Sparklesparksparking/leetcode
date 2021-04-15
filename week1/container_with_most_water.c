int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize == 0) {
        return 0;
    }
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    int area;
    while(left < right) {
        if (height[left] > height[right]) {
            area = height[right] * (right - left);
            right--;
            while (height[right + 1] > height[right]) {
                right--;
            }
        } else {
            area = height[left] * (right - left);
            left++;  
            while (height[left - 1] > height[left]) {
                left++;
            }
        }
        if(max < area) {
            max = area;
        }
    }
    return max;
}