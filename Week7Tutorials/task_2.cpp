/*
    task_1.cpp does not exist as it consists of looking over the example code files provided to
    give an understanding and are not actual workable assignments for me to write out
*/

#include <iostream>
#include <string>

using namespace std;

class Time{
    private:
    int hour;
    int minute;
    int second;

    public:

    Time (int h=0, int m=0, int s=0){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    void setTime(int h, int m, int s){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    Time operator+ (Time const& t){
        Time time = Time();
        time.second = (this->second + t.second)%60;
        time.minute = (this->minute + t.minute + (this->second + t.second)/60)%60;
        time.hour = (this->hour + t.hour + (this->minute + t.minute + (this->second + t.second)/60)/60)%24;
        return time;
    }

    Time operator++ (){
        ++second;
        if (second >= 60)
        {
            ++minute;
            second -= 60;
            if (minute >= 60){
                ++hour;
                hour %= 24;
                minute -= 60;
            }
        }
        
        return Time(hour, minute, second);
    }

    Time operator++ ( int ){

        Time T = Time(hour, minute, second);

        ++second;
        if (second >= 60)
        {
            ++minute;
            second -= 60;
            if (minute >= 60){
                ++hour;
                hour %= 24;
                minute -= 60;
            }
        }

        return T;
    }

    friend ostream& operator <<(ostream& out,const Time& time);
};

ostream& operator <<(ostream& out,const Time& time){
    (time.hour < 10) ? out << '0' << time.hour : out << time.hour;
    out << ':';
    (time.minute < 10) ? out << '0' << time.minute : out << time.minute;
    out << ':';
    (time.second < 10) ? out << '0' << time.second : out << time.second;
    return out;
}


int main(){
    Time t1 = Time(15,59,58);
    cout << "counting up:" << endl;
    for (int s = 0; s < 4; s++)
    {
        cout << t1 << endl;
        t1++;
    }
    
    t1.setTime(15,59,59);
    Time t2(12,0,1);
    cout << "Adding " << t1 << " and " << t2 << endl;
    Time t3 = t1 + t2;
    cout << t3 << endl;
    return 0;
}