int maxValue(int n, int index, int maxSum) {
    int left = 1;
    int right = maxSum;
    
    while(left < right - 1) {
        int mid = left + (right - left) / 2;

        if (possible(n, index, mid, maxSum)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    if (possible(n, index, right, maxSum)) return right;
    else return left;
    
}

bool possible(int n, int index, int top, int limit) { // check whether possible if set index as top value 
    // left: [0, index - 1]
	// [index] = top
    // right: [index + 1, n - 1];
    long long total = top;
    
    total += calc(n, index, top);
    total += calc(n, n - 1 - index, top); // reverse the arry and calculate the right side
    
    return total <= limit;
}

long long calc(int n, int index, int top) { // if set index to top value, what's the sum from the left elements have to be
    long long total = 0;
    if (index > 0) { // if index is 0, no left element so total is 0
        if (top - index > 0) { // [0] is greater or equal to 1
            total += (long long)(top - index + top - 1) * (index) / 2;
        } else { // [0] .. [x] is all 1
            total += (long long)(1 + top - 1) * (top - 1) / 2;
            total += 1 * (index - top + 1);
        }
    }
    return total;
}
