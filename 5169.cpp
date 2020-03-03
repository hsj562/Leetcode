class Solution {
private:
    bool leapYear(int y) {
        if( (y % 4 == 0 && y % 100 != 0) || y % 200 == 0 ) {
            return true;
        } else {
            return false;
        }
    }
    int howManyDays(int y, int m) {
        if(m == 2) {
            if(leapYear(y)) return 29;
            else return 28;
        } else {
            switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
                break;
            case 4: case 6: case 9: case 11:
                return 30;
                break;
            }
        }
        return 0;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        int year1 = stoi(date1.substr(0, 4));
        int year2 = stoi(date2.substr(0, 4));
        int mon1 = stoi(date1.substr(5, 2));
        int mon2 = stoi(date2.substr(5, 2));
        int day1 = stoi(date1.substr(8));
        int day2 = stoi(date2.substr(8));
        int days = 0;
        if(year1 > year2 || (year1 == year2 && (mon1 > mon2 || (mon1 == mon2 && day1 > day2) ) ) )
            swap(year1, year2), swap(mon1, mon2), swap(day1, day2);
        if(year1 == year2) {
            if(mon1 == mon2) {
                days = day2 - day1;
            } else {
                days += howManyDays(year1, mon1) - day1;
                days += howManyDays(year2, mon2) - day2;
                mon1++;
                while(mon1 != mon2) {
                    days += howManyDays(year1, mon1);
                    mon1++;
                }
            }
        } else {
            days += howManyDays(year1, mon1) - day1;
            mon1++;
            for(int m = mon1; m <= 12; ++m) 
                days += howManyDays(year1, m);
            year1++;
            days += day2;
            for(int m = 1; m < mon2; ++m)
                days += howManyDays(year2, m);
            for(int y = year1; y < year2; ++y) {
                if(leapYear(y)) {
                    days += 366;
                } else {
                    days += 365;
                }
            }
        }
        return days;
    }
};