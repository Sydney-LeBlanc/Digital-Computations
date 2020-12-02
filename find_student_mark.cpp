//
//  find_students_mark
//
//  Created by Sydney LeBlanc on 2020-10-23.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>

using namespace std;

int calc_mark_percentage(int correct_ans, int incorrect_ans){
    double temp_mark = 0;
    int final_mark = 0, total_questions = 0;
    total_questions = correct_ans + incorrect_ans;
    
    temp_mark = ((total_questions - (incorrect_ans * 0.25)) / total_questions) * 100;
    final_mark = temp_mark;
    
    return final_mark;
}

int highest_mark(int students_marks[], int MAX_STUDENTS){
    int highest_mark = 0;
    for (int index = 0; index < MAX_STUDENTS; index++) {
        if (students_marks[index] > highest_mark) {
            highest_mark = students_marks[index];
        }
    }
    return highest_mark;
}

int lowest_mark(int students_marks[],int MAX_STUDENTS){
    int lowest_mark = 100;
       for (int index = 0; index < MAX_STUDENTS; index++) {
           if (students_marks[index] < lowest_mark) {
               lowest_mark = students_marks[index];
           }
       }
       return lowest_mark;
}

int average_score(int students_marks[], int MAX_STUDENTS){
    int sum = 0, average_score = 0;
    
    for (int index = 0; index < MAX_STUDENTS; index++) {
        sum += students_marks[index];
    }
    average_score = sum / MAX_STUDENTS;
    return average_score;
}

void q4_pp5(){
    int correct_ans = 0, incorrect_ans = 0, total_students,
    students_marks[8] = {};
    
    cout << "How many students? ";
    cin >> total_students;
    const int MAX_STUDENTS = total_students;
  
    for (int index = 0; index < MAX_STUDENTS; index++) {
        
        
        cout << "Student #" << (index + 1) << "'s correct answers: ";
        cin >> correct_ans;
        cout << "Student #" << (index + 1) << "'s incorrect answers: ";
        cin >> incorrect_ans;
        
        
        students_marks[index] = calc_mark_percentage(correct_ans, incorrect_ans);
        cout << "final mark: " << students_marks[index] << endl;
    }
    cout << "The highest mark is: " << highest_mark(students_marks, MAX_STUDENTS) << "%\n";
    cout << "The lowest mark is: " << lowest_mark(students_marks, MAX_STUDENTS) << "%\n";
    cout << "The average score is: " << average_score(students_marks, MAX_STUDENTS) << "%\n";
    
}




int main() {
    q4_pp5();
}
