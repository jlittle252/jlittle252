/*

 Project 3
 Student registration program designed to take user input that will allow them to register for a class, 
 cancel their registration, view all registered students, and view remaining class seats. 
*/

package registration;

import javax.swing.*;
import java.awt.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

// Custom exception
class ClassRoomFull extends Exception {
    private LocalDate registrationDate;

    public ClassRoomFull(LocalDate registrationDate) {
        super(" ** Class Full **  Registration Attempt Date:  " + registrationDate);
        this.registrationDate = registrationDate;
    }

    public LocalDate getRegistrationDate() {
        return registrationDate;
    }
}

// Student model
class Student {
    private String name;
    private int seatNumber;
    private LocalDate registrationDate;

    public Student(String name, int seatNumber, LocalDate registrationDate) {
        this.name = name;
        this.seatNumber = seatNumber;
        this.registrationDate = registrationDate;
    }

    public int getSeatNumber() {
        return seatNumber;
    }

    public LocalDate getRegistrationDate() {
        return registrationDate;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Student Name: " + name + ", Registration Date: " + registrationDate + ", Seat Number: " + seatNumber;
    }
}

// Main registration system with GUI
public class Comp360RegistrationSystem {

    private static final int MAX_SEATS = 30;
    private List<Student> registeredStudents;

    public Comp360RegistrationSystem() {
        registeredStudents = new ArrayList<>();
    }

    public boolean isClassRoomFull() {
        return registeredStudents.size() >= MAX_SEATS;
    }

    public void registerStudent(String name) throws ClassRoomFull {
        LocalDate registrationDate = LocalDate.now();
        if (isClassRoomFull()) {
            throw new ClassRoomFull(registrationDate);
        }
        int seatNumber = registeredStudents.size() + 1;
        Student student = new Student(name, seatNumber, registrationDate);
        registeredStudents.add(student);
        System.out.println(" * * * * Successfully Registered * * * * ");
        System.out.println(student);
    }

    public void cancelRegistration(String name) {
        registeredStudents.removeIf(student -> student.getName().equals(name));
        System.out.println("Registration Cancelled for: " + name);
    }

    public List<Student> getRegisteredStudents() {
        return new ArrayList<>(registeredStudents); // Defensive copy
    }

    public int getRemainingSeats() {
        return MAX_SEATS - registeredStudents.size();
    }

    // GUI launcher
    public static void main(String[] args) {
        Comp360RegistrationSystem registrationSystem = new Comp360RegistrationSystem();

        JFrame frame = new JFrame("COMP 360 Registration System");
        frame.setSize(600, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(7, 1));

        JTextField nameField = new JTextField();
        JTextArea displayArea = new JTextArea();
        displayArea.setEditable(false);

        // Register Button
        JButton registerBtn = new JButton("Register Student");
        registerBtn.addActionListener(e -> {
            String name = nameField.getText().trim().toUpperCase();
            try {
                registrationSystem.registerStudent(name);
                displayArea.setText("Successfully registered: " + name);
            } catch (ClassRoomFull ex) {
                displayArea.setText(ex.getMessage());
            }
        });

        // Cancel Button
        JButton cancelBtn = new JButton("Cancel Registration");
        cancelBtn.addActionListener(e -> {
            String name = nameField.getText().trim().toUpperCase();
            registrationSystem.cancelRegistration(name);
            displayArea.setText("Cancelled registration for: " + name);
        });

        // View Students
        JButton viewBtn = new JButton("View Registered Students");
        viewBtn.addActionListener(e -> {
            List<Student> students = registrationSystem.getRegisteredStudents();
            if (students.isEmpty()) {
                displayArea.setText("No students registered.");
            } else {
                StringBuilder sb = new StringBuilder();
                for (Student s : students) {
                    sb.append(s).append("\n");
                }
                displayArea.setText(sb.toString());
            }
        });

        // View Remaining Seats
        JButton seatsBtn = new JButton("View Remaining Seats");
        seatsBtn.addActionListener(e -> {
            int remaining = registrationSystem.getRemainingSeats();
            displayArea.setText("Remaining Seats: " + remaining);
        });

        // Add components
        frame.add(new JLabel("Enter Student Name:"));
        frame.add(nameField);
        frame.add(registerBtn);
        frame.add(cancelBtn);
        frame.add(viewBtn);
        frame.add(seatsBtn);
        frame.add(new JScrollPane(displayArea));

        frame.setVisible(true);
    }
}
// End of Code
