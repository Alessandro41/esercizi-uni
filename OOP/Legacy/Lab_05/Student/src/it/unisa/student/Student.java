package it.unisa.student;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Student implements Comparable{
    private final String firstName;
    private final String lastName;
    List<Exam> exams;

    public Student(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.exams = new ArrayList<>();
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public List<Exam> getExams() {
        return exams;
    }

    public void registerExam(Exam exam) {
        this.exams.add(exam);
    }

    public double computeAverageGrade() {
        double averageGrade = 0;
        for (Exam exam : this.exams) {
            averageGrade += exam.getGrade();
        }
        averageGrade /= exams.size();
        return averageGrade;
    }

    public int compareTo (Student other) {
        Comparator comparator = new Comparator() {
            @Override
            public int compare(Object , Object o2) {
                return 0;
            }
        }
    }
}