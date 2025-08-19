function solution(n) {
    if (n % 2 == 1) {
        const N = (n+1)/2;
        return N*N;
    } else {
        const N = n/2;
        return 2*N*(N+1)*(2*N+1)/3;
    }
}