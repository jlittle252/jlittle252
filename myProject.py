# Group 6
# Prof Leflore
# Comp 267
# program to connect to allow instructor to view student grades and edit them, also to allow Student to view weighted average or total grades



import mysql.connector
from mysql.connector import errorcode


#event handler to ensure proper connection is made with SQL Database

def create_connection(userName,userPassword):
    try:
        connection = mysql.connector.connect(
        host="localhost",
        user= userName,
        password= userPassword,
        database="Gradebook"
    )
        print("")
        print("* * Connection Successful * *")
        print("")
        return connection


    except mysql.connector.Error as err:
        if err.errno == errorcode.ER_ACCESS_DENIED_ERROR:
            print("Invalid Credentials")
            return None
        elif err.errno == errorcode.ER_BAD_DB_ERROR:
            print("Database not found")
            return None
        else:
            print("Cannot connect to database")
            return None


    # Execute the query with the username parameter






def WelcomeMenu(): # menu displayed to user when called
    print('*************************************************')
    print("         Grade Book Log In          " )
    print("            -Main Menu-              ")
    print(" ")
    print(" ")
    print(' S)  Student Log In             ')
    print(' I)  Instructor Log In          ')
    print(' E)  Exit                       ') # exit program
    print('==================================================')

def StudentWelcome():# Menu displayed to Student
    print("****************************************")
    print("         - Student Menu -        ")
    print("                                        ")
    print(f"       J) View Weighted Grade Total   ") # see weighted total
    print(f"       K) View All Assignment Grades   ")
    print(f"       E) Exit         ") # Exit program student portal
    print("****************************************")

def profWelcome():# Menu displayed to Instructor
    print("****************************************")
    print("         - Instructor  Menu - ")
    print("                             ")
    print(f"       A) Enter Grades      ")
    print(f"       B) Delete Assignment ")
    print(f"       C) View Grades       ")
    print(f"       D) Enter Student     ")
    print(f"       E) Delete Student    ")
    print(f"       F) Add Categories    ")
    print(f"       H) View Categories   ")
    print(f"       I) View Assignments  ")
    print(f"       X) Exit              ") # exit instructor portal
    print("****************************************")



#View All Categories Function
def viewAllCategories(connection):
    cursor = connection.cursor()
    display = "Select * From Category"
    cursor.execute(display)
    categories = cursor.fetchall()
    if categories:
        print(" ")
        print("=====Category Codes======")
        print(categories)
        print(" ")

def viewAllStudents(connection):
    cursor = connection.cursor()
    display = "Select * From Student"
    cursor.execute(display)
    stu = cursor.fetchall()
    if stu:
        print(" ")
        print("=====All Students======")
        print(stu)
        print(" ")


 # Function to grab categories from sql
def categoryConnection(connection):
    cursor = connection.cursor(dictionary=True)
    display = "Select ID, assignmentType From Category"
    cursor.execute(display)
    categories = cursor.fetchall()
    cursor.close()
    return categories



# Student View All Grades Function
def viewAllGrades(connection, student_email):
    cursor = connection.cursor(dictionary=True)

    # Fetch the student ID based on the provided email
    cursor.execute("SELECT ID FROM Student WHERE email = %s", (student_email,))
    results = cursor.fetchone()

    if results:
        student_id = results['ID']  # Get student ID

        # Query to get all assignments and grades for the student
        display = """
        SELECT a.assignmentName AS assignmentID, wg.grade
        FROM WeightedGrades wg
        JOIN Gradebook.Assignment A on wg.assignmentID = A.ID
        WHERE wg.studentID = %s
        """
        cursor.execute(display, (student_id,))

        # Fetch all grades for the student
        all_grades = cursor.fetchall()

        if all_grades:
            print("Here are all the grades:")
            for grades in all_grades:
                assignment_id = grades['assignmentID']
                grade = grades['grade']
                print(f"{assignment_id}, Grade: {grade:.2f}%")
    cursor.close()



def viewGrades(connection):
    cursor = connection.cursor()

    # Query to fetch student names and their weighted grades
    query = """
        SELECT
        CONCAT(s.firstName, ' ', s.lastName) AS StudentName,
        SUM(grade * weight) / SUM(weight) AS WeightedGrade
        FROM Student s
        LEFT JOIN WeightedGrades wg ON s.ID = wg.studentID
        GROUP BY s.ID, s.firstName, s.lastName
        ORDER BY s.lastName, s.firstName;
    """
    cursor.execute(query)
    results = cursor.fetchall()

    if results:
        print("\nStudent Weighted Grades:\n")
        print(f"{'Student Name':<30}{'Weighted Grade':<15}")
        print("-" * 50)
        for student_name, weighted_grade in results:
            print(f"{student_name:<30}{weighted_grade:<15.2f}")



        cursor.close()


def viewAssignments(connection):
    cursor = connection.cursor()

    # Query to fetch student names and their weighted grades
    query = """
        SELECT assignmentName, assignmentType FROM Assignment, Category WHERE Assignment.categoryID = Category.ID;
    """
    cursor.execute(query)
    results = cursor.fetchall()

    if results:
        print("\nAssignments:\n")
        print(f"{'Assignment Name':<30}{'Assignment type':<15}")
        print("-" * 50)
        for assignment_name, assignment_type in results:
            print(f"{assignment_name:<30}{assignment_type:<15}")



        cursor.close()



def showGrade(connection, student_email):# display Student info and welcome
   #cursor = connection.cursor()
   cursor = connection.cursor(dictionary=True)
   cursor.execute("SELECT ID FROM Student WHERE email = %s", (student_email,))
   student = cursor.fetchone()
   if student:
       student_id = student['ID']
       display="""
           SELECT studentID, SUM(grade * weight) / SUM(weight) AS weighted_average
           FROM WeightedGrades
           Where studentID = %s;
       """
       cursor.execute(display,(student_id,))
       # cursor.execute("SELECT * FROM WeightedGrades WHERE studentID = %s ", (student_id,))
       result = cursor.fetchone()
       if result and result['weighted_average'] is not None:
           weighted_average = result['weighted_average']
           print(f"Total Weighted Grade: {weighted_average:.2f}%")


   cursor.close()



def update_student_table(connection):
    cursor = connection.cursor()

    # Prompt the user for input
    print("Enter the details to update the Student table:")
    first_name = input("First Name: ").strip()
    last_name = input("Last Name: ").strip()
    email = input("Email: ").strip()


    # Construct the SQL query
    query = ('INSERT INTO Student'
             '(firstName, lastName, email)'
             'VALUES (%s, %s, %s)')
    studentData = (first_name, last_name, email)
    cursor.execute(query, studentData)
    connection.commit()
    cursor.close()


def delete_assignment(connection):
    cursor = connection.cursor()
    viewAssignments(connection)

    # Prompt the user for input
    print("")
    print("Enter the ID of the assignment to delete:[Key Test1->600, Homework->602, Quiz->603, Final->604")
    assignment_id = input("Assignment ID: ").strip()

    # Confirm deletion
    confirmation = input(f"Are you sure you want to delete assignment with ID '{assignment_id}'?  (yes/no): ").strip().lower()
    if confirmation != 'yes':
        print("Deletion canceled.")
        return

    try:

        delete_weighted_grades_query = "DELETE FROM WeightedGrades WHERE assignmentID = %s"
        cursor.execute(delete_weighted_grades_query, (assignment_id,))
        print(f"Deleted {cursor.rowcount} rows from WeightedGrades.")



        # Delete the assignment
        delete_assignment_query = "DELETE FROM Assignment WHERE ID = %s"
        cursor.execute(delete_assignment_query, (assignment_id,))
        print(f"Deleted assignment with ID '{assignment_id}'.")

        # Commit the transaction
        connection.commit()
        print("Deletion completed successfully.")

    except mysql.connector.Error as err:

        print(f"Error: {err}")
    finally:
        cursor.close()


def delete_student(connection):
    cursor = connection.cursor()

    # Prompt the user for input
    print("Enter the email of the student to delete:")
    email = input("Email: ").strip()

    # Confirm deletion
    confirmation = input(f"Are you sure you want to delete the student with email '{email}'? (yes/no): ").strip().lower()
    if confirmation != 'yes':
        print("Deletion canceled.")
        return

    # Construct the SQL query
    query = "DELETE FROM Student WHERE email = %s"

    try:
        # Execute the query
        cursor.execute(query, (email,))
        connection.commit()

        # Check if a row was deleted
        if cursor.rowcount > 0:
            print(f"Student with email '{email}' has been deleted successfully.")
        else:
            print(f"No student found with email '{email}'.")
    except mysql.connector.Error as err:
        print(f"Error: {err}")
    finally:
        cursor.close()




def enter_grade(connection,student_email, categoryID, grade):

    cursor = connection.cursor(dictionary=True)
    try:
        cursor.execute("SELECT ID FROM Student WHERE email = %s", (student_email,))
        student = cursor.fetchone()
        if student:
            student_id = student['ID']
            cursor.execute("SELECT * FROM WeightedGrades WHERE studentID = %s AND categoryID = %s", (student_id, categoryID))
            category_entry = cursor.fetchone()
            if category_entry:
                cursor.execute("UPDATE WeightedGrades SET grade = %s WHERE ID = %s", (grade, category_entry['ID']))
            else:
                weight = float(input(f"Enter the weight for {categoryID} :  "))
                cursor.execute("INSERT INTO WeightedGrades (studentID, categoryID, weight, grade) VALUES (%s, %s, %s, %s)",
                               (student_id, categoryID, weight, grade))
            connection.commit()
            print(f"Grade for category '{categoryID}' updated for {student_email}.")
        else:
            print("Student not found.")
    except mysql.connector.Error as err:
        print(f"Error: {err}")
    finally:
        cursor.close()
        connection.close()

def show_userStu(connection, userName):# display Student info and welcome
    cursor = connection.cursor()
    display= "SELECT username FROM Authentication WHERE UserName = %s "
    cursor.execute(display, (userName,))
    result = cursor.fetchone()
    if result:
        username = result
        print("")
        print(f" {'Welcome'} {username} ")
        print("")


    option = 'Z'
    while option != 'E':
        StudentWelcome()
        option = input("Enter Student Menu Option : ").upper()

        if option == 'J':
            print("")
            student_email = input("Enter your Email:  ").strip()
            showGrade(connection, student_email)

        elif (option =='K'):
            student_email = input("Enter your Email:  ").strip()
            viewAllGrades(connection, student_email)

        elif (option == 'E'):
            print("")
            print(f"        {'*'}    {'*'}       ")
            print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
            print(f"  {'*'}{'Exiting Student Portal'}{'*'}  ")
            print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
            print(f"        {'*'}    {'*'}       ")
            print("")
    WelcomeMenu()
    cursor.close()


def addCategory(connection):
    cursor = connection.cursor()

    # Prompt the user for input
    print("Enter the new category:")
    category = input("Category: ").strip()

    # Construct the SQL query
    query = ('INSERT INTO category'
             '(assignmentType)'
             'VALUES (%s)')

    cursor.execute(query, (category,))
    connection.commit()
    cursor.close()



def show_userProf(connection, userName):# display Prof info and welcome
    cursor = connection.cursor()
    display= "SELECT username FROM Authentication WHERE UserName = %s "
    cursor.execute(display, (userName,))
    result = cursor.fetchone()
    if result:
        username = result
        print(f" {'Welcome'} {username} ")

    option = 'Z'
    while option != 'X':
        profWelcome()
        option = input("Enter Instructor Menu Option : ").upper()

        if option == 'A':
            while True:
                student_email = input("Enter student email (or done to stop): ")
                if student_email.lower() == 'done':
                    break
                categories = categoryConnection(connection)
                if categories:
                    print(f" \nClass Categories: ")
                    for category in categories:
                        print(f" {category['assignmentType']} -> {category['ID']}")
                        categoryID = input("Enter assignment category ID (Listed Above): ")
                        grade = float(input("Enter grade: "))
                        enter_grade(connection, student_email, categoryID, grade)

        elif (option == 'B'):
            delete_assignment(connection)

        elif (option == 'C'):
            viewGrades(connection)

        elif (option == 'D'):
            update_student_table(connection)

        elif (option == 'E'):
            viewAllStudents(connection)
            delete_student(connection)

        elif (option == 'F'):
            addCategory(connection)

        elif (option == 'H'):
            viewAllCategories(connection)


        elif (option == 'I'):
            viewAssignments(connection)



        elif (option == 'X'):
            print("")
            print(f"            {'*'}     {'*'}    {'*'}    ")
            print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
            print(f"  {'*'}{'Exiting Instructor Portal'}{'*'}  ")
            print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
            print(f"            {'*'}     {'*'}     {'*'}  ")
            print("")
            WelcomeMenu()

        cursor.close()



option = 'Z' #initalization of option variable
WelcomeMenu()

# loop that will keep the program running until quit option is chosen
while option != 'E':

    option = input("Enter Main Menu Option : ").upper()



    if (option == 'S'):# student log in
        if (option == 'S'):  # student log in

            print('==================================================')
            print(f" {'*'} {'Student'} {'Portal'} {'Log In'} {'*'}")
            print("")

            userName = input('Enter Username *Case Sensitive*  :  ')
            userPassword = input('Enter Password *Case Sensitive*  :  ')
            connection = create_connection(userName, userPassword)
            while connection is None:
                userName = input('Enter Username *Case Sensitive*  :  ')
                userPassword = input('Enter Password *Case Sensitive*  :  ')
                connection = create_connection(userName, userPassword)
            show_userStu(connection, userName)
            connection.close()




    elif (option == 'I'): #instructor log in
        print('==================================================')
        print(f" {'*'} {'Instructor'} {'Portal'} {'Log In'} {'*'}")
        print("")

        userName = input('Enter Username *Case Sensitive*  :  ')
        userPassword = input('Enter Password *Case Sensitive*  :  ')
        connection = create_connection(userName, userPassword)
        while connection is None:
            userName = input('Enter Username *Case Sensitive*  :  ')
            userPassword = input('Enter Password *Case Sensitive*  :  ')
            connection = create_connection(userName, userPassword)


        viewGrades(connection)
        print("**************************************")
        show_userProf(connection, userName)
        connection.close()

    elif (option == 'E'): #Exit Gradebook program (End loop)
        print("")
        print(f"         {'*'}    {'*'}       ")
        print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
        print(f"  {'*'} {'Exiting Grade Book'} {'*'}  ")
        print(f"    {'*'}   {'*'}   {'*'}   {'*'}   {'*'}")
        print(f"         {'*'}    {'*'}       ")
        print("")




