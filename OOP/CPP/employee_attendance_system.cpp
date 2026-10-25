#include <iostream>

struct WorkSchedule {
    int startHour;
    int endHour;
};

struct AttendanceRecord {
    const char* date;
    int arrivalHour;
    int departureHour;
};

class Employee {
public:
    const char* name;
    int id;
    WorkSchedule schedule;
    AttendanceRecord attendance[100]; 
    int recordCount;

    Employee(const char* empName, int empId, int start, int end) {
        name = empName;
        id = empId;
        schedule.startHour = start;
        schedule.endHour = end;
        recordCount = 0;
    }

    void recordAttendance(const char* date, int arrival, int departure) {
        if (recordCount < 100) {
            attendance[recordCount].date = date;
            attendance[recordCount].arrivalHour = arrival;
            attendance[recordCount].departureHour = departure;
            recordCount++;
        } else {
            std::cout << "Attendance record is full!\n";
        }
    }

    int calculateWorkHours() {
        int totalHours = 0;
        for (int i = 0; i < recordCount; i++) {
            totalHours += (attendance[i].departureHour - attendance[i].arrivalHour);
        }
        return totalHours;
    }

    void generateAttendanceReport() {
        std::cout << "Attendance Report for " << name << " (ID: " << id << ")\n";
        for (int i = 0; i < recordCount; i++) {
            std::cout << "Date: " << attendance[i].date 
                      << ", Arrival: " << attendance[i].arrivalHour 
                      << ", Departure: " << attendance[i].departureHour 
                      << ", Hours Worked: " << (attendance[i].departureHour - attendance[i].arrivalHour) << "\n";
        }
        std::cout << "Total Hours Worked: " << calculateWorkHours() << "\n";
    }
};

int main() {
    Employee emp1("Prabh ", 101, 9, 17);

    emp1.recordAttendance("2024-12-01", 9, 17);
    emp1.recordAttendance("2024-12-02", 9, 16);
    emp1.recordAttendance("2024-12-03", 10, 18);

    emp1.generateAttendanceReport();

    return 0;
}
