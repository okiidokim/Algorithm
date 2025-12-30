function solution(arr1, arr2) {
    if (arr1.length > arr2.length) return 1;
    else if (arr1.length < arr2.length) return -1;
    
    const sum1 = arr1.reduce((acc, curr) => acc += curr, 0);
    const sum2 = arr2.reduce((acc, curr) => acc += curr, 0);
    if (sum1 > sum2) return 1;
    else if (sum1 < sum2) return -1;
    
    return 0;
}