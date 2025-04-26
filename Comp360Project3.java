/*

 Project 3
 Student registration program designed to take user input that will allow them to register for a class, 
 cancel their registration, view all registered students, and view remaining class seats. 
*/



package project360;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

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

class Student {
    private String name;
    private int seatNumber;
    private LocalDate registrationDate;

    public Student(String name, int seatNumber, LocalDate registrationDate) {
        this.setName(name);
        this.seatNumber = seatNumber;
        this.registrationDate = registrationDate;
    }

    public int getSeatNumber() {
        return seatNumber;
    }

    public LocalDate getRegistrationDate() {
        return registrationDate;
    }

    @Override
    public String toString() {
        return " Student Name: " + name + ",  Registration Date: " + registrationDate + ", Seat Number: " + seatNumber ;
    }

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
    
    
}

class Comp360RegistrationSystem {
    private static final int MAX_SEATS = 3;
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
        System.out.println( " * * * * Successfully Registered* * * * " );
        System.out.println(student);
    }

    public void cancelRegistration(String name) {
        registeredStudents.removeIf(student -> student.getName().equals(name));
        System.out.println(" ");
        System.out.println("Registration Cancelled for : " + name);
        System.out.print(" ");
    }

    public void displayRegisteredStudents() {
        System.out.println("Registered Students:");
        System.out.println(registeredStudents);
        
        
    }
    public static void main(String[] args) {
    	Comp360RegistrationSystem registrationSystem = new Comp360RegistrationSystem();
    	Scanner inPut = new Scanner(System.in);
    	String choice;
    	int seatNum;
    	
    	do {
    		System.out.print(" ");
    		System.out.println("Menu Options");
    		System.out.println("A - New Student Registration");
    		System.out.println("B - Cancel Student Registration");
    		System.out.println("C - View Registered Students");
    		System.out.println("D - View Remaining Seats");
    		System.out.println("X - Exit ");
    		choice = inPut.nextLine().toUpperCase();
    		System.out.println(" ");
    		
    		
    		
    		switch (choice)
    		{
    		
    		case "A":
    	    	try {
    	    		
    	    		System.out.println("Enter Student Name");
    	    		String newStudent = inPut.nextLine();
    	    		registrationSystem.registerStudent(newStudent.toUpperCase());
    	    		System.out.println(" ");
    	    		}
    	    	
    	    	
    	    	catch (ClassRoomFull e) {
    	    		System.err.println(e.getMessage());
    	    		}
    	    	
    	    	
    			break;
    		case "B":
    			
    			System.out.println("Enter Student to Cancel");
    			
    			
	    		String stuName = inPut.nextLine();
    			
    			registrationSystem.cancelRegistration(stuName.toUpperCase());
    			
                
                break;
            
    		case "C": 
            	
            	System.out.println(" ");
            	registrationSystem.displayRegisteredStudents();
            	System.out.println(" ");
                break;
                
    		case "D":
    			System.out.println(" Comp 360 Remaining Seats ");
    			System.out.println("--> " + MAX_SEATS + " <--");
    			
                break;
                
            case "X": 
            	
            	System.out.println("Good Bye");
                // .. exit program
                break;
            
            default:
                System.out.println("Pick Valid Option");
        }   
    } while (choice != "X");
    	
    	inPut.close();
    	
    }
}
    		
// End of code
   	

    	
    

    
    


