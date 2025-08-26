function solution(n) {
  let count = 0;
  for (let d = 1; d * d <= n; d++) {
    if (n % d === 0) {
      if (d % 2 === 1) count++;
      const q = n / d;
      if (q !== d && q % 2 === 1) count++;
    }
  }
  return count;
}