function solution(cacheSize, cities) {
    if (cacheSize === 0) return cities.length * 5;
    let time = 0;
    let cache = [];
    
    for (let item of cities) {
        item = item.toLowerCase();
        if (cache.includes(item)) {
            time++;
            const index = cache.indexOf(item);
            cache = [...cache.slice(0, index), ...cache.slice(index + 1)];
        } else {
            time += 5;
            if (cache.length === cacheSize) {
                cache.shift();
            }
        }
        cache.push(item);
    }
    return time;
}