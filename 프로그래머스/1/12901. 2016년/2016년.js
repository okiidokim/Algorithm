function solution(a, b) {
    const map = {
        1 : 31,
        2 : 29,
        3 : 31,
        4 : 30,
        5 : 31,
        6 : 30,
        7 : 31,
        8 : 31,
        9 : 30,
        10 : 31,
        11 : 30,
        12 : 31
    }
    const mapDate = {
        0 : "THU",
        1 : "FRI",
        2 : "SAT",
        3 : "SUN",
        4 : "MON",
        5 : "TUE",
        6 : "WED"
    }
    let days = 0;
    for (let i = 1; i < a; i++) {
        days += map[i];
    }
    days += b;
    days %= 7;
    return mapDate[days];
}